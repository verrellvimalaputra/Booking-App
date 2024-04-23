#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
using namespace std;

TravelAgency::TravelAgency()
{

}

TravelAgency::~TravelAgency(){
}


void TravelAgency::readFile(QString fileName) {
    allTravels.clear();
    allCustomers.clear();
    allBookings.clear(); // clear any existing bookings


    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Failed to open file!";
    }

    // Read the contents of the file into a QByteArray
    QByteArray jsonData = file.readAll();
    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    //checking the jsonDoc is valid
    if (!jsonDoc.isArray())
        throw std::invalid_argument("Invalid JSON File");

    QJsonArray bookingsArray = jsonDoc.array();
    for (int i = 0; i < bookingsArray.size(); i++) {
        if (!bookingsArray[i].isObject()) { //checking if the objects are valid
            throw std::invalid_argument("Invalid Booking in JSON File at object " + std::to_string(i+1));
        }
        QJsonObject bookingObject = bookingsArray[i].toObject();

        // Check for empty attributes
        if (bookingObject["type"].toString().isEmpty() || bookingObject["id"].toString().isEmpty() ||
                bookingObject["price"].isNull() || bookingObject["fromDate"].toString().isEmpty() ||
                bookingObject["toDate"].toString().isEmpty()) {
            throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1));
        }

        long customerId = bookingObject["customerId"].toVariant().toLongLong();
        std::string customerName = bookingObject["customerName"].toString().toStdString();
        long travelId = bookingObject["travelId"].toVariant().toLongLong();

        //Make the customer object
        std::shared_ptr<Customer> customer = findCustomer(customerId);
        if (customer != nullptr) {
            // Customer exists, do nothing


        } else {
            customer = std::make_shared<Customer>(customerId, customerName);
            allCustomers.push_back(customer);
        }

        //make the travel Object
        std::shared_ptr<Travel> travel = findTravel(travelId);
        if (travel != nullptr) {
            // travel exists, do nothing

        } else {
            travel = std::make_shared<Travel>(travelId, customerId);
            allTravels.push_back(travel);
            // Add the travel to the customer
            customer->addTravel(travel);
        }

        std::string type = bookingObject["type"].toString().toStdString();
        std::string id = bookingObject["id"].toString().toStdString();

        //Check if the price in the right format
        if (!bookingObject["price"].isDouble()) {
            throw std::invalid_argument("Invalid price in JSON File at object " + std::to_string(i+1));
        }
        double price = bookingObject["price"].toDouble();

        std::string fromDate = bookingObject["fromDate"].toString().toStdString();
        std::string toDate = bookingObject["toDate"].toString().toStdString();

        if (type == "Flight") {
            //check if the Flightbooking has all the attributes
            if (bookingObject["airline"].toString().isEmpty() || bookingObject["toDest"].toString().isEmpty()
                    || bookingObject["fromDest"].toString().isEmpty() || bookingObject["bookingClass"].toString().isEmpty()
                    || bookingObject["fromDestLatitude"].isNull() || bookingObject["fromDestLongitude"].isNull()
                    || bookingObject["toDestLatitude"].isNull() || bookingObject["toDestLongitude"].isNull()) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1));
            }
            std::string airline = bookingObject["airline"].toString().toStdString();
            std::string toDestination = bookingObject["toDest"].toString().toStdString();
            std::string fromDestination = bookingObject["fromDest"].toString().toStdString();
            //check if the Flughafenkuerzel in the right format
            if(fromDestination.length() != 3 || toDestination.length() != 3){
                throw std::invalid_argument("Invalid Flughafenkuerzel format at object " + std::to_string(i+1));
            }
            char bookingClass = bookingObject["bookingClass"].toString().toLatin1().at(0);
            double fromDestLatitude = bookingObject["fromDestLatitude"].toDouble();
            double fromDestLongitude = bookingObject["fromDestLongitude"].toDouble();
            double toDestLatitude = bookingObject["toDestLatitude"].toDouble();
            double toDestLongitude = bookingObject["toDestLongitude"].toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<FlightBooking>(id, price, fromDate, toDate, airline, toDestination, fromDestination, bookingClass,
                                                                               fromDestLatitude, fromDestLongitude, toDestLatitude, toDestLongitude);
            allBookings.push_back(booking);
            travel->addBooking(booking);
        } else if (type == "RentalCar") {
            //check if the Rentalcar has all the attributes
            if (bookingObject["company"].toString().isEmpty() ||bookingObject["pickupLocation"].toString().isEmpty() ||
                    bookingObject["returnLocation"].toString().isEmpty() || bookingObject["vehicleClass"].toString().isEmpty()
                    || bookingObject["pickupLatitude"].isNull() || bookingObject["pickupLongitude"].isNull()
                    || bookingObject["returnLatitude"].isNull() || bookingObject["returnLongitude"].isNull() ) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1));
            }
            std::string company = bookingObject["company"].toString().toStdString();
            std::string pickupLocation = bookingObject["pickupLocation"].toString().toStdString();
            std::string returnLocation = bookingObject["returnLocation"].toString().toStdString();
            std::string vehicleClass = bookingObject["vehicleClass"].toString().toStdString();
            double pickupLatitude = bookingObject["pickupLatitude"].toDouble();
            double pickupLongitude = bookingObject["pickupLongitude"].toDouble();
            double returnLatitude = bookingObject["returnLatitude"].toDouble();
            double returnLongitude = bookingObject["returnLongitude"].toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<RentalCarReservation>(id, price, fromDate, toDate, pickupLocation, returnLocation, company, vehicleClass,
                                                                                      pickupLatitude, pickupLongitude, returnLatitude, returnLongitude);
            allBookings.push_back(booking);
            travel->addBooking(booking);
        } else if (type == "Hotel") {
            //check if the Hotelbooking has all the attributes
            if (bookingObject["hotel"].toString().isEmpty() || bookingObject["town"].toString().isEmpty() || bookingObject["roomType"].toString().isEmpty()
                    || bookingObject["hotelLatitude"].isNull() || bookingObject["hotelLongitude"].isNull() ) {
                throw std::invalid_argument("Empty attribute in JSON File at object " + std::to_string(i+1));
            }
            std::string hotel = bookingObject["hotel"].toString().toStdString();
            std::string town = bookingObject["town"].toString().toStdString();
            std::string roomType = bookingObject["roomType"].toString().toStdString();
            double hotelLatitude = bookingObject["hotelLatitude"].toDouble();
            double hotelLongitude = bookingObject["hotelLongitude"].toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<HotelBooking>(id, price, fromDate, toDate, hotel, town, roomType, hotelLatitude, hotelLongitude);
            allBookings.push_back(booking);
            travel->addBooking(booking);
        } else {
            throw std::runtime_error("Invalid booking type");
        }
    }
    file.close();
}

void TravelAgency::readIataCodes(QString fileName) {
    allAirports.clear(); // clear any existing airport

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::invalid_argument("Failed to open file!");
    }

    // Read the contents of the file into a QByteArray
    QString jsonData = file.readAll();
    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData.toUtf8());

    //Checking if the JSON document is an array
    if (!jsonDoc.isArray()) {
        throw std::invalid_argument("Invalid JSON File");
    }

    QJsonArray airportsArray = jsonDoc.array();
    for (int i = 0; i < airportsArray.size(); i++) {
        if (!airportsArray[i].isObject()) { // Checking if the objects are valid
            throw std::invalid_argument("Invalid Airport in JSON File at object " + std::to_string(i + 1));
        }
        QJsonObject airportObject = airportsArray[i].toObject();

        std::string name = airportObject["name"].toString().toStdString();
        std::string isoCountry = airportObject["iso_country"].toString().toStdString();
        std::string municipality = airportObject["municipality"].toString().toStdString();
        std::string iata_code = airportObject["iata_code"].toString().toStdString();

        // Make an airport object
        shared_ptr<Airport> airport = findAirport(iata_code);
        if (airport != nullptr) {
            // Airport exists, do nothing
        } else {
            airport = std::make_shared<Airport>(name, isoCountry, municipality, iata_code);
            allAirports.push_back(airport);
        }
    }
    file.close();
}

QString TravelAgency::getBookingsInfo() {
    int flightCount = 0;
    double flightTotalValue = 0.0;
    int rentalCarCount = 0;
    double rentalCarTotalValue = 0.0;
    int hotelCount = 0;
    double hotelTotalValue = 0.0;
    int totalTravels = allTravels.size();
    int totalCustomers = allCustomers.size();
    std::shared_ptr<Customer> customer1 = findCustomer(1);
    std::shared_ptr<Travel> travel17 = findTravel(17);

    for (const auto& booking : allBookings) {
        std::shared_ptr<FlightBooking> flight = std::dynamic_pointer_cast<FlightBooking>(booking);
        std::shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking);
        std::shared_ptr<Booking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking);

        if (flight != nullptr) {
            flightCount++;
            flightTotalValue += flight->getPrice();
        } else if (rentalCar != nullptr) {
            rentalCarCount++;
            rentalCarTotalValue += rentalCar->getPrice();
        } else if (hotel != nullptr) {
            hotelCount++;
            hotelTotalValue += hotel->getPrice();
        }
    }

    std::ostringstream oss;
    oss << "Es wurden " << flightCount << " Flugbuchungen im Wert von " << flightTotalValue << " Euro, "
        << rentalCarCount << " Mietwagenbuchungen im Wert von " << rentalCarTotalValue << " Euro und "
        << hotelCount << " Hotelreservierungen im Wert von " << hotelTotalValue << " Euro angelegt."
        << "Es wurden " << totalTravels << " Reisen und " << totalCustomers << " Kunden angelegt. "
        << "Der Kunde mit der ID 1 hat "<< customer1->getTravelList().size() << " Reisen gebucht."
        << " Zur Reise mit der ID 17 gehoeren " << travel17->getTravelBookings().size() << " Buchungen" << std::endl;

    return QString::fromStdString(oss.str());
}


void TravelAgency::clearBookings(){
    allBookings.clear();
}

void TravelAgency::clearTravels(){
    allTravels.clear();
}

void TravelAgency::clearCustomers(){
    allCustomers.clear();
}

std::vector<std::shared_ptr<Booking>> TravelAgency::getBookings() const {
    return allBookings;
}

std::shared_ptr<Booking> TravelAgency::findBooking(std::string id){
    for (auto booking : allBookings){
        if (booking->getId() == id)
            return booking;
    }
    return 0;
}


std::shared_ptr<Travel> TravelAgency::findTravel(long id){
    for (auto travel : allTravels){
        if (travel->getId() == id)
            return travel;
    }
    return 0;
}

std::shared_ptr<Customer> TravelAgency::findCustomer(long id){
    for (auto customer : allCustomers){
        if (customer->getId() == id)
            return customer;
    }
    return 0;
}

std::shared_ptr<Airport> TravelAgency::findAirport(std::string airportCode){
    for (auto airport : allAirports){
        if (airport->getIataCode() == airportCode)
            return airport;
    }
    return 0;
}

//void TravelAgency::displayBookingsOnMap(const std::shared_ptr<Travel>& travel)
//{
//    QJsonArray geoJsonArray;

//    // Iterate over the bookings of the travel
//    for (const auto& booking : travel->getTravelBookings())
//    {
//        QJsonObject geoJson;

//        // Get the GPS coordinates for the booking (assuming the booking has latitude and longitude attributes)
//        double latitude = booking->getLatitude();
//        double longitude = booking->getLongitude();

//        // Create the GeoJson object for the booking
//        geoJson["type"] = "Point";
//        geoJson["coordinates"] = QJsonArray({longitude, latitude});

//        // Add the GeoJson object to the array
//        geoJsonArray.append(geoJson);
//    }

//    // Create the GeoJson document
//    QJsonDocument geoJsonDoc;
//    geoJsonDoc.setArray(geoJsonArray);

//    // Convert the GeoJson document to a string
//    QByteArray geoJsonData = geoJsonDoc.toJson(QJsonDocument::Compact);
//    QString geoJsonString(geoJsonData);

//    // Encode the GeoJson string for use in the URL
//    QString encodedGeoJson = QUrl::toPercentEncoding(geoJsonString);

//    // Create the URL with the encoded GeoJson
//    QString mapUrl = "http://townsendjennings.com/geo/?geojson=" + encodedGeoJson;

//    // Open the URL in the default web browser
//    QDesktopServices::openUrl(QUrl(mapUrl));
//}

//void TravelAgency::readBinaryFile(){

//    for (auto booking : bookings) {
//        delete booking;
//    }
//    bookings.clear(); // clear any existing bookings

//    QFile file("./bookingsBinary.bin");

//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        std::cerr << "Failed to open file!";
//    }

//    //deklarationen
//    char type;
//    char id[39];
//    double price;
//    char fromDate[9];
//    char toDate[9];
//    char fromDest[4];
//    char toDest[4];
//    char airline[16];
//    char pickupLocation[16];
//    char returnLocation[16];
//    char company[16];
//    char hotel[16];
//    char town[16];

//    while (file.read(&type, sizeof(char)) &&
//           file.read(id, sizeof(char) * 38) &&
//           file.read(reinterpret_cast<char*>(&price), sizeof(double)) &&
//           file.read(fromDate, sizeof(char) * 8) &&
//           file.read(toDate, sizeof(char) * 8))
//    {
//        Booking* booking = nullptr; //initialize
//        switch (type)
//        {
//        case 'F': // Flight
//            file.read(fromDest, sizeof(char) * 3);
//            file.read(toDest, sizeof(char) * 3);
//            file.read(airline, sizeof(char) * 15);
//            booking = new FlightBooking(id, price, fromDate, toDate, fromDest, toDest, airline);
//            bookings.push_back(booking);
//            break;
//        case 'R': // Rental Car
//            file.read(pickupLocation, sizeof(char) * 15);
//            file.read(returnLocation, sizeof(char) * 15);
//            file.read(company, sizeof(char) * 15);
//            booking = new RentalCarReservation(id, price, fromDate, toDate, pickupLocation, returnLocation, company);
//            bookings.push_back(booking);
//            break;
//        case 'H': // Hotel
//            file.read(hotel, sizeof(char) * 15);
//            file.read(town, sizeof(char) * 15);
//            booking = new HotelBooking(id, price, fromDate, toDate, hotel, town);
//            bookings.push_back(booking);
//            break;
//        }

//    }

//    file.close();
//}
