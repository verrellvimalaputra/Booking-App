#include "addbooking.h"
#include "travelagency.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "ui_addbooking.h"

AddBooking::AddBooking(QWidget *parent) :
    QDialog(parent),
    addToNewTravel(false),
    ui(new Ui::AddBooking)
{
    ui->setupUi(this);
    ui->bookingAttributePages->setVisible(false);
    ui->rentalCarReservationButton->setIcon(QIcon("Car.png"));
    ui->flightBookingButton->setIcon(QIcon("plane.png"));
    ui->hotelBookingButton->setIcon(QIcon("hotel.png"));
}

AddBooking::~AddBooking()
{
    delete ui;
}

std::shared_ptr<Booking> AddBooking::makeRentalCarReservation(){
    std::string id = QUuid::createUuid().toString().toStdString();
    double price = ui->PriceCarEdit->value();
    long travelId = 0; //will be sett later

    //convert the from Date to std::string
    QDate fromDate = ui->startDateCarEdit->date();
    QString fromDateString = fromDate.toString("yyyyMMdd");
    std::string fromDateStdString = fromDateString.toStdString();

    QDate toDate = ui->endDateCarEdit->date();
    QString toDateString = toDate.toString("yyyyMMdd");
    std::string toDateStdString = toDateString.toStdString();

    std::string company = ui->companyEdit->text().toStdString();
    std::string pickupLocation = ui->pickupLocEdit->text().toStdString();
    std::string returnLocation = ui->returnLocEdit->text().toStdString();
    std::string vehicleClass = ui->vehicleClassEdit->text().toStdString();
    std::string pred1 = ui->pred1CarEdit->text().toStdString();
    std::string pred2 = ui->pred2CarEdit->text().toStdString();
    double pickupLatitude = 0.0;
    double pickupLongitude = 0.0;
    double returnLatitude = 0.0;
    double returnLongitude = 0.0;
    std::shared_ptr<Booking> booking = std::make_shared<RentalCarReservation>(id, travelId, price, fromDateStdString, toDateStdString, pred1, pred2, pickupLocation, returnLocation, company, vehicleClass,
                                                                              pickupLatitude, pickupLongitude, returnLatitude, returnLongitude);
    return booking;
}

std::shared_ptr<Booking> AddBooking::makeFlightBooking(){
    std::string id = QUuid::createUuid().toString().toStdString();
    double price = ui->priceFlightSpinbox->value();
    long travelId = 0; //will be set later

    //convert the from Date to std::string
    QDate fromDate = ui->startDateFlightEdit->date();
    QString fromDateString = fromDate.toString("yyyyMMdd");
    std::string fromDateStdString = fromDateString.toStdString();

    QDate toDate = ui->endDateFlightEdit->date();
    QString toDateString = toDate.toString("yyyyMMdd");
    std::string toDateStdString = toDateString.toStdString();

    std::string airline = ui->airlineEdit->text().toStdString();
    std::string toDestination = ui->toCodeEdit->text().toStdString();
    std::string fromDestination = ui->fromCodeEdit->text().toStdString();
    QString bookingClass = ui->bookingClassEdit->text();
    char setBookingClass;
    if(bookingClass == "Economy class"){
        setBookingClass = 'Y';
    }
    else if(bookingClass == "Premium Economy class"){
        setBookingClass = 'W';
    }
    else if(bookingClass == "Business class"){
        setBookingClass = 'J';
    }
    else if(bookingClass == "First class"){
        setBookingClass = 'F';
    }
    else QMessageBox::critical(this, "Error", "Unknown Booking Class type!");

    std::string pred1 = ui->pred1FlightEdit->text().toStdString();
    std::string pred2 = ui->pred2FlightEdit->text().toStdString();


    double fromDestLatitude = 0.0;
    double fromDestLongitude = 0.0;
    double toDestLatitude = 0.0;
    double toDestLongitude = 0.0;
    std::shared_ptr<Booking> booking = std::make_shared<FlightBooking>(id, travelId, price, fromDateStdString, toDateStdString, pred1, pred2, airline, toDestination, fromDestination, setBookingClass,
                                                                       fromDestLatitude, fromDestLongitude, toDestLatitude, toDestLongitude);
    return booking;
}

std::shared_ptr<Booking> AddBooking::makeHotelBooking(){
    std::string id = QUuid::createUuid().toString().toStdString();
    double price = ui->priceHotelEdit->value();
    long travelId = 0; //will be set later

    //convert the from Date to std::string
    QDate fromDate = ui->startDateHotelEdit->date();
    QString fromDateString = fromDate.toString("yyyyMMdd");
    std::string fromDateStdString = fromDateString.toStdString();

    QDate toDate = ui->endDateHotelEdit->date();
    QString toDateString = toDate.toString("yyyyMMdd");
    std::string toDateStdString = toDateString.toStdString();

    std::string hotel = ui->hotelEdit->text().toStdString();
    std::string town = ui->townEdit->text().toStdString();
    std::string roomType = ui->roomTypeEdit->text().toStdString();
    if(roomType == "Einzelzimmer"){
        roomType = "EZ";
    }
    else if(roomType == "Doppelzimmer"){
        roomType = "DZ";
    }
    else if(roomType == "Apartment"){
        roomType = "AP";
    }
    else if(roomType == "Suite"){
        roomType = "SU";
    }
    else QMessageBox::critical(this, "Error", "Unknown Hotel Room type!");

    std::string pred1 = ui->pred1HotelEdit->text().toStdString();
    std::string pred2 = ui->pred2HotelEdit->text().toStdString();

    double hotelLatitude = 0.0;
    double hotelLongitude = 0.0;
    std::shared_ptr<Booking> booking = std::make_shared<HotelBooking>(id, travelId, price, fromDateStdString, toDateStdString, pred1, pred2, hotel, town, roomType, hotelLatitude, hotelLongitude);
    return booking;
}


void AddBooking::on_rentalCarReservationButton_clicked()
{
    ui->bookingAttributePages->setVisible(true);
    ui->bookingAttributePages->setCurrentIndex(0);
}

void AddBooking::on_flightBookingButton_clicked()
{
    ui->bookingAttributePages->setVisible(true);
    ui->bookingAttributePages->setCurrentIndex(1);
}


void AddBooking::on_hotelBookingButton_clicked()
{
    ui->bookingAttributePages->setVisible(true);
    ui->bookingAttributePages->setCurrentIndex(2);
}

void AddBooking::on_buttonBox_accepted()
{
    std::shared_ptr<Booking> booking;
    // Create the booking based on user input
    if (ui->bookingAttributePages->currentIndex() == 0)
        booking = makeRentalCarReservation();
    else if (ui->bookingAttributePages->currentIndex() == 1)
        booking = makeFlightBooking();
    else if (ui->bookingAttributePages->currentIndex() == 2)
        booking = makeHotelBooking();

    if(ui->addToNewTravel->isChecked() == true || ui->addToSelectedTravel->isChecked() == true)
        emit bookingCreated(booking, addToNewTravel);
    else{
        // Display an error dialog indicating that no travel option was selected
        QMessageBox::critical(this, "Error", "Please select a travel option.");
    }
}


void AddBooking::on_addToNewTravel_clicked()
{
    ui->addToSelectedTravel->setChecked(false);
    addToNewTravel = true;
}


void AddBooking::on_addToSelectedTravel_clicked()
{
    ui->addToNewTravel->setChecked(false);
    addToNewTravel = false;
}



