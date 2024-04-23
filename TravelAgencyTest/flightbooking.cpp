#include "flightbooking.h"

FlightBooking::FlightBooking(std::string id, double price, std::string fromDate, std::string toDate,
                             std::string airline, std::string toDestination, std::string fromDestination, char bookingClass,
                             double fromDestLatitude, double fromDestLongitude, double toDestLatitude, double toDestLongitude):
    Booking(id, price, fromDate, toDate), fromDestination(fromDestination), toDestination(toDestination), airline(airline), bookingClass(bookingClass),
    fromDestLatitude(fromDestLatitude), fromDestLongitude(fromDestLongitude), toDestLatitude(toDestLatitude), toDestLongitude(toDestLongitude)
{
}

FlightBooking::~FlightBooking()
{
}

std::string FlightBooking::showDetails(){
    return "Flugbuchung von " + fromDestination + " nach "
            + toDestination + " mit " + airline + " am " + fromDate
            + "Booking Class " + getBookingClass()
            + "Preis: " + std::to_string(price) + " Euro";
}

std::string FlightBooking::getFromDestination(){
    return fromDestination;
}

std::string FlightBooking::getToDestination(){
    return toDestination;
}

std::string FlightBooking::getAirline(){
    return airline;
}

std::string FlightBooking::getBookingClass(){

    switch(bookingClass){
    case 'Y':
        return "Economy class";
    case 'W':
        return "Premium Economy class";
    case 'J' :
        return "Business class";
    case 'F' :
        return "First class";
    default :               //should not be reached
        return "";
    }
}

double FlightBooking::getFromDestLatitude(){
    return fromDestLatitude;
}

double FlightBooking::getFromDestLongitude(){
    return fromDestLongitude;
}

double FlightBooking::getToDestLatitude() {
    return toDestLatitude;
}

double FlightBooking::getToDestLongitude(){
    return toDestLongitude;
}

void FlightBooking::setFromDestination(std::string fromDestination){
    this->fromDestination = fromDestination;
}
void FlightBooking::setToDestination(std::string toDestination){
    this->toDestination = toDestination;
}
void FlightBooking::setAirline(std::string airline){
    this->airline = airline;
}
void FlightBooking::setBookingClass(char bookingClass){
    this->bookingClass = bookingClass;
}
void FlightBooking::setFromDestLatitude(double fromDestLatitude){
    this->fromDestLatitude = fromDestLatitude;
}
void FlightBooking::setFromDestLongitude(double fromDestLongitude){
    this->fromDestLongitude = fromDestLongitude;
}
void FlightBooking::setToDestLatitude(double toDestLatitude){
    this->toDestLatitude = toDestLatitude;
}
void FlightBooking::setToDestLongitude(double toDestLongitude){
    this->toDestLongitude = toDestLongitude;
}
