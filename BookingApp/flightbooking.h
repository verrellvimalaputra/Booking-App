#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include "booking.h"
#include <string>

class FlightBooking : public Booking
{
public:
    FlightBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1, std::string predecessor2,
                  std::string airline, std::string toDestination, std::string fromDestination, char bookingClass,
                  double fromDestLatitude, double fromDestLongitude, double toDestLatitude, double toDestLongitude);
    ~FlightBooking();
    std::string showDetails();

    std::string getFromDestination();
    std::string getToDestination();
    std::string getAirline();
    std::string getBookingClass();
    char getBookingClassCode();
    double getFromDestLatitude();
    double getFromDestLongitude();
    double getToDestLatitude();
    double getToDestLongitude();

    void setFromDestination(std::string);
    void setToDestination(std::string);
    void setAirline(std::string);
    void setBookingClass(char);
    void setFromDestLatitude(double);
    void setFromDestLongitude(double);
    void setToDestLatitude(double);
    void setToDestLongitude(double);

private:
    std::string fromDestination;
    std::string toDestination;
    std::string airline;
    char bookingClass;
    double fromDestLatitude;
    double fromDestLongitude;
    double toDestLatitude;
    double toDestLongitude;
};


#endif // FLIGHTBOOKING_H

