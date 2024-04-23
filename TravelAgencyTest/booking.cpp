#include "booking.h"

Booking::Booking(std::string id, double price, std::string fromDate, std::string toDate) :
    id(id), price(price), fromDate(fromDate), toDate(toDate)
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

void Booking::setFromDate(std::string fromDate) {
    this->fromDate = fromDate;
}

void Booking::setToDate(std::string toDate) {
    this->toDate = toDate;
}

void Booking::setPrice(double price) {
    this->price = price;
}
