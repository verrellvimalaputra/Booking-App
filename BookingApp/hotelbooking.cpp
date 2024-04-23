#include "hotelbooking.h"

HotelBooking::HotelBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1, std::string predecessor2,
                           std::string hotel, std::string town, std::string roomType, double hotelLatitude, double hotelLongitude) :
    Booking(id, travelId,price, fromDate, toDate, predecessor1, predecessor2), hotel(hotel), town(town), roomType(roomType), hotelLatitude(hotelLatitude), hotelLongitude(hotelLongitude)
{
}

HotelBooking::~HotelBooking()
{
}

std::string HotelBooking::showDetails(){
    return "Hotelreservierung " + hotel + " in "
            + town + " vom " + fromDate + ". "
            + " bis zum " + toDate + "Room Type : " + getRoomType()
            + "Preis: " + std::to_string(price) + " Euro";
}

std::string HotelBooking::getHotel(){
    return hotel;
}

std::string HotelBooking::getTown(){
    return town;
}

std::string HotelBooking::getRoomType(){

    if(roomType == "EZ")
        return "Einzelzimmer";
    else if(roomType == "DZ")
        return "Doppelzimmer";
    else if (roomType == "AP")
        return "Apartment";
    else if(roomType == "SU")
        return "Suite";
    else               //should not be reached
        return "";
}
double HotelBooking::getHotelLatitude(){
    return hotelLatitude;
}
double HotelBooking::getHotelLongitude(){
    return hotelLongitude;
}

void HotelBooking::setHotel(std::string hotel){
    this->hotel = hotel;
}
void HotelBooking::setTown(std::string town){
    this->town = town;
}
void HotelBooking::setRoomType(std::string roomType){
    this->roomType = roomType;
}
void HotelBooking::setHotelLatitude(double hotelLatitude){
    this->hotelLatitude = hotelLatitude;
}
void HotelBooking::setHotelLongitude(double hotelLongitude){
    this->hotelLongitude = hotelLongitude;
}
