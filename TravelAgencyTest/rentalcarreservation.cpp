#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(std::string id, double price, std::string fromDate, std::string toDate,
                                           std::string pickupLocation, std::string returnLocation, std::string company, std::string vehicleClass,
                                           double pickupLatitude, double pickupLongitude, double returnLatitude, double returnLongitude) :
    Booking(id, price, fromDate, toDate), pickupLocation(pickupLocation),
    returnLocation(returnLocation), company(company), vehicleClass(vehicleClass), pickupLatitude(pickupLatitude),
    pickupLongitude(pickupLongitude), returnLatitude(returnLatitude), returnLongitude(returnLongitude)
{
}

RentalCarReservation::~RentalCarReservation()
{
}
std::string RentalCarReservation::showDetails(){
    return "Mietwagenreservierung mit Europcar. Abholung am "
            + fromDate + " in " + pickupLocation + ". "
            + "Rueckgabe am " + toDate + " in " + returnLocation + ". "
            + "Vehicle Class :" + vehicleClass
            + "Preis: " + std::to_string(price) + " Euro";
}

std::string RentalCarReservation::getPickupLocation(){
    return pickupLocation;
}
std::string RentalCarReservation::getReturnLocation(){
    return returnLocation;
}
std::string RentalCarReservation::getCompany(){
    return company;
}
std::string RentalCarReservation::getVehicleClass(){
    return vehicleClass;
}
double RentalCarReservation::getPickupLatitude(){
    return pickupLatitude;
}
double RentalCarReservation::getPickupLongitude(){
    return pickupLongitude;
}
double RentalCarReservation::getReturnLatitude(){
    return returnLatitude;
}
double RentalCarReservation::getReturnLongitude(){
    return returnLongitude;
}

void RentalCarReservation::setPickupLocation(std::string pickupLocation){
    this->pickupLocation = pickupLocation;
}
void RentalCarReservation::setReturnLocation(std::string returnLocation){
    this->returnLocation = returnLocation;
}
void RentalCarReservation::setCompany(std::string company){
    this->company = company;
}
void RentalCarReservation::setVehicleClass(std::string vehicleClass){
    this->vehicleClass = vehicleClass;
}
void RentalCarReservation::setPickupLatitude(double pickupLatitude){
    this->pickupLatitude = pickupLatitude;
}
void RentalCarReservation::setPickupLongitude(double pickupLongitude){
    this->pickupLongitude = pickupLongitude;
}
void RentalCarReservation::setReturnLatitude(double returnLatitude){
    this->returnLatitude = returnLatitude;
}
void RentalCarReservation::setReturnLongitude(double returnLongitude){
    this->returnLongitude = returnLongitude;
}
