#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <QDate>

class Booking
{
public:
    Booking(std::string id, double price, std::string fromDate, std::string toDate);
    virtual ~Booking();
    virtual std::string showDetails() = 0; //pure virtual function
    std::string getId();
    double getPrice();
    std::string getFromDate();
    std::string getToDate();

    void setPrice(double);
    void setFromDate(std::string);
    void setToDate(std::string);

protected:
    std::string id;
    double price;
    std::string fromDate;
    std::string toDate;
};

#endif // BOOKING_H

