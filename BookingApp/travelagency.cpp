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

        std::string pred1 = ""; // Default value for predecessor1
        if (bookingObject.contains("predecessor1") && !bookingObject["predecessor1"].isNull()) {
            pred1 = bookingObject["predecessor1"].toString().toStdString();
        }
        std::string pred2 = ""; // Default value for predecessor1
        if (bookingObject.contains("predecessor2") && !bookingObject["predecessor2"].isNull()) {
            pred2 = bookingObject["predecessor2"].toString().toStdString();
        }

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
            double fromDestLatitude = bookingObject["fromDestLatitude"].toString().toDouble();;
            double fromDestLongitude = bookingObject["fromDestLongitude"].toString().toDouble();
            double toDestLatitude = bookingObject["toDestLatitude"].toString().toDouble();
            double toDestLongitude = bookingObject["toDestLongitude"].toString().toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<FlightBooking>(id, travelId, price, fromDate, toDate, pred1, pred2, airline, toDestination, fromDestination, bookingClass,
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
            double pickupLatitude = bookingObject["pickupLatitude"].toString().toDouble();
            double pickupLongitude = bookingObject["pickupLongitude"].toString().toDouble();
            double returnLatitude = bookingObject["returnLatitude"].toString().toDouble();
            double returnLongitude = bookingObject["returnLongitude"].toString().toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<RentalCarReservation>(id, travelId, price, fromDate, toDate, pred1, pred2, pickupLocation, returnLocation, company, vehicleClass,
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
            double hotelLatitude = bookingObject["hotelLatitude"].toString().toDouble();
            double hotelLongitude = bookingObject["hotelLongitude"].toString().toDouble();
            std::shared_ptr<Booking> booking = std::make_shared<HotelBooking>(id, travelId,price, fromDate, toDate, pred1, pred2, hotel, town, roomType, hotelLatitude, hotelLongitude);
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

    // Read the contents of the file into a QString
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

std::vector<std::shared_ptr<Travel>> TravelAgency::getTravels() const {
    return allTravels;
}
std::vector<std::shared_ptr<Customer>> TravelAgency::getCustomers() const {
    return allCustomers;
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

void TravelAgency::displayBookingsOnMap(const std::shared_ptr<Travel>& travel)
{
    QJsonObject geoJsonObject;
    geoJsonObject["type"] = "FeatureCollection";
    QJsonArray featureArray;

    // Iterate over the bookings of the travel
    for (const auto& booking : travel->getTravelBookings())
    {
        if (std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking))
        {
            // Flight Booking
            double fromDestLatitude = flightBooking->getFromDestLatitude();
            double fromDestLongitude = flightBooking->getFromDestLongitude();
            double toDestLatitude = flightBooking->getToDestLatitude();
            double toDestLongitude = flightBooking->getToDestLongitude();
            std::shared_ptr<Airport> fromAirport = findAirport(flightBooking->getFromDestination());
            QString fromAirportName = QString::fromStdString(fromAirport->getName());
            std::shared_ptr<Airport> toAirport = findAirport(flightBooking->getToDestination());
            QString toAirportName = QString::fromStdString(toAirport->getName());
            // Create the GeoJson object for the flight booking

            QJsonObject flightObject;
            flightObject["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "LineString";
            QJsonArray coordinates;
            QJsonArray startCoordinates;
            startCoordinates.append(fromDestLongitude);
            startCoordinates.append(fromDestLatitude);
            QJsonArray destCoordinates;
            destCoordinates.append(toDestLongitude);
            destCoordinates.append(toDestLatitude);
            coordinates.append(startCoordinates);
            coordinates.append(destCoordinates);
            geometry["coordinates"] = coordinates;
            flightObject["geometry"] = geometry;

            QJsonObject properties;
            properties["startAirportName"] = fromAirportName;
            properties["destAirportName"] = toAirportName;

            flightObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(flightObject);

        }
        else if (std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking))
        {
            // Hotel Booking
            double latitude = hotelBooking->getHotelLatitude();
            double longitude = hotelBooking->getHotelLongitude();
            QString hotelName = QString::fromStdString(hotelBooking->getHotel());

            // Create the GeoJson object for the hotel booking
            QJsonObject hotelObject;
            hotelObject["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "Point";
            QJsonArray coordinates;
            coordinates.append(longitude);
            coordinates.append(latitude);
            geometry["coordinates"] = coordinates;
            hotelObject["geometry"] = geometry;

            QJsonObject properties;
            properties["hotelName"] = hotelName;

            hotelObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(hotelObject);
        }
        else if (std::shared_ptr<RentalCarReservation> carBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking))
        {
            // Rental car reservation
            double pickupLatitude = carBooking->getPickupLatitude();
            double pickuplongitude = carBooking->getPickupLongitude();
            double returnLatitude = carBooking->getReturnLatitude();
            double returnLongitude = carBooking->getReturnLongitude();
            QString pickupLocation = QString::fromStdString(carBooking->getPickupLocation());
            QString returnLocation = QString::fromStdString(carBooking->getReturnLocation());

            // Create the GeoJson object for the Car Booking
            QJsonObject carObject;
            carObject["type"] = "Feature";
            QJsonObject geometry;
            geometry["type"] = "LineString";
            QJsonArray coordinates;
            QJsonArray startCoordinates;
            startCoordinates.append(pickuplongitude);
            startCoordinates.append(pickupLatitude);
            QJsonArray destCoordinates;
            destCoordinates.append(returnLongitude);
            destCoordinates.append(returnLatitude);
            coordinates.append(startCoordinates);
            coordinates.append(destCoordinates);
            geometry["coordinates"] = coordinates;
            carObject["geometry"] = geometry;

            QJsonObject properties;
            properties["pickupLocation"] = pickupLocation;
            properties["returnLocation"] = returnLocation;

            carObject["properties"] = properties;

            // Add the flightObject to the GeoJSON array
            featureArray.append(carObject);
        }
    }

    geoJsonObject["features"] = featureArray;

    // Create the GeoJson document
    QJsonDocument geoJsonDoc(geoJsonObject);

    // Convert the GeoJson document to a string
    QByteArray geoJsonData = geoJsonDoc.toJson(QJsonDocument::Indented);
    QString geoJsonString(geoJsonData);

    // Encode the GeoJson string for use in the URL
    QString encodedGeoJson = QUrl::toPercentEncoding(geoJsonString);

    // Create the URL with the encoded GeoJson
    QString mapUrl = "http://townsendjennings.com/geo/?geojson=" + encodedGeoJson;

    // Open the URL in the default web browser
    QDesktopServices::openUrl(QUrl(mapUrl));
}

long TravelAgency::addNewCustomer(QString name){
    long nextCustomerId = 0;

    // Find the highest assigned customer ID
    for (const auto& customer : allCustomers)
    {
        if (customer->getId() > nextCustomerId)
        {
            nextCustomerId = customer->getId();
        }
    }

    // Increment the highest assigned customer ID to get the next free number
    nextCustomerId++;

    // Create a new customer object
    std::shared_ptr<Customer> newCustomer = std::make_shared<Customer>(nextCustomerId, name.toStdString());

    // Add the new customer to the list of all customers
    allCustomers.push_back(newCustomer);
    return nextCustomerId;
}

void TravelAgency::addNewBooking(std::shared_ptr<Booking> booking){
    allBookings.push_back(booking);
}

long TravelAgency::addBookingtoNewTravel(long customerId, std::shared_ptr<Booking> booking){
    long nextTravelId = 0;

    // Find the highest assigned customer ID
    for (const auto& travel : allTravels)
    {
        if (travel->getId() > nextTravelId)
        {
            nextTravelId = travel->getId();
        }
    }

    // Increment the highest assigned customer ID to get the next free number
    nextTravelId++;

    // Create a new customer object
    std::shared_ptr<Travel> newTravel = std::make_shared<Travel>(nextTravelId, customerId);
    allTravels.push_back(newTravel);
    booking->setTravelId(nextTravelId);
    newTravel->addBooking(booking);
    std::shared_ptr<Customer> currentCustomer = findCustomer(customerId);
    currentCustomer->addTravel(newTravel);
    return nextTravelId;
}

void TravelAgency::sortBookings(const std::string& sortCriterion){
    SortFunktor sortFunktor(sortCriterion);
    std::sort(allBookings.begin(), allBookings.end(), sortFunktor);
}

void TravelAgency::saveToJSON(const std::string& filename){
    QJsonArray jsonArray;

    for (const auto& booking : allBookings) {
        QJsonObject bookingObject;
        std::shared_ptr<Travel> travel = findTravel(booking->getTravelId());
        std::shared_ptr<Customer> customer = findCustomer(travel->getCustomerId());
        bookingObject["id"] = QString::fromStdString(booking->getId());
        bookingObject["customerId"] = QString::number(customer->getId());
        bookingObject["customerName"] = QString::fromStdString(customer->getName());
        bookingObject["fromDate"] = QString::fromStdString(booking->getFromDate());
        bookingObject["toDate"] = QString::fromStdString(booking->getToDate());
        bookingObject["price"] = QString::number(booking->getPrice());
        bookingObject["travelId"] = QString::number(booking->getTravelId());

        if (std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking))
        {
            bookingObject["type"] = "Flight";
            bookingObject["airline"] = QString::fromStdString(flightBooking->getAirline());
            bookingObject["bookingClass"] = QString(flightBooking->getBookingClassCode());
            bookingObject["fromDest"] = QString::fromStdString(flightBooking->getFromDestination());
            bookingObject["toDest"] = QString::fromStdString(flightBooking->getToDestination());
            bookingObject["fromDestLatitude"] = QString::number(flightBooking->getFromDestLatitude());
            bookingObject["fromDestLongitude"] = QString::number(flightBooking->getFromDestLongitude());
            bookingObject["toDestLatitude"] = QString::number(flightBooking->getToDestLatitude());
            bookingObject["toDestLongitude"] = QString::number(flightBooking->getToDestLongitude());
        }
        else if (std::shared_ptr<RentalCarReservation> carBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking))
        {
            bookingObject["type"] = "RentalCar";
            bookingObject["company"] = QString::fromStdString(carBooking->getCompany());
            bookingObject["pickupLocation"] = QString::fromStdString(carBooking->getPickupLocation());
            bookingObject["returnLocation"] = QString::fromStdString(carBooking->getReturnLocation());
            bookingObject["vehicleClass"] = QString::fromStdString(carBooking->getVehicleClass());
            bookingObject["pickupLatitude"] = QString::number(carBooking->getPickupLatitude());
            bookingObject["pickupLongitude"] = QString::number(carBooking->getPickupLongitude());
            bookingObject["returnLatitude"] = QString::number(carBooking->getReturnLatitude());
            bookingObject["returnLongitude"] = QString::number(carBooking->getReturnLongitude());
        }
        else if (std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking))
        {
            bookingObject["type"] = "Hotel";
            bookingObject["hotel"] = QString::fromStdString(hotelBooking->getHotel());
            bookingObject["town"] = QString::fromStdString(hotelBooking->getTown());
            bookingObject["roomType"] = QString::fromStdString(hotelBooking->getRoomType());
            bookingObject["hotelLatitude"] = QString::number(hotelBooking->getHotelLatitude());
            bookingObject["hotelLongitude"] = QString::number(hotelBooking->getHotelLongitude());
            // Add more fields specific to Hotel booking
        }

        jsonArray.append(bookingObject);
    }

    QJsonDocument jsonDocument(jsonArray);

    QFile outputFile(QString::fromStdString(filename));
    if (outputFile.open(QIODevice::WriteOnly)) {
        outputFile.write(jsonDocument.toJson());
        outputFile.close();
    }
}

void TravelAgency::abcAnalyse()
{
    sort(allCustomers.begin(), allCustomers.end(),
         [](std::shared_ptr<Customer> c1, shared_ptr<Customer> c2){return c1->getTotalCustomerPrice() > c2->getTotalCustomerPrice();});
}

double TravelAgency::getTotalPrice()
{
    double totalPrice = 0;

    for (unsigned int i = 0; i < allBookings.size(); i++) {
        totalPrice = totalPrice + allBookings[i]->getPrice();
    }

    return totalPrice;
}
