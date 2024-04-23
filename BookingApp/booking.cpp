#include "booking.h"

Booking::Booking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1= "", std::string predecessor2= "") :
    id(id), travelId(travelId), price(price), fromDate(fromDate), toDate(toDate), predecessor1(predecessor1), predecessor2(predecessor2)
{
}

Booking::~Booking()
{
}

std::string Booking::getId(){
    return id;
}

double Booking::getPrice(){
    return price;
}

std::string Booking::getFromDate(){
    return fromDate;
}

std::string Booking::getToDate(){
    return toDate;
}
std::string Booking::getPredecessor1(){
    return predecessor1;
}

std::string Booking::getPredecessor2(){
    return predecessor2;
}

long Booking::getTravelId(){
    return travelId;
}

void Booking::setFromDate(std::string fromDate) {
    this->fromDate = fromDate;
}

void Booking::setToDate(std::string toDate) {
    this->toDate = toDate;
}

void Booking::setPrice(double price) {
    this->price = price;
}

void Booking::setTravelId(long travelId){
    this->travelId = travelId;
}


