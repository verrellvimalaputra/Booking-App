#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <QDate>

class Booking
{
public:
    Booking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1, std::string predecessor2);
    virtual ~Booking();
    virtual std::string showDetails() = 0; //pure virtual function
    std::string getId();
    double getPrice();
    std::string getFromDate();
    std::string getToDate();
    long getTravelId();
    std::string getPredecessor1();
    std::string getPredecessor2();

    void setPrice(double);
    void setFromDate(std::string);
    void setToDate(std::string);
    void setTravelId(long);

protected:
    std::string id;
    long travelId;
    double price;
    std::string fromDate;
    std::string toDate;
    std::string predecessor1;
    std::string predecessor2;

};

#endif // BOOKING_H

