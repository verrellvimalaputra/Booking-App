#ifndef TRAVEL_H
#define TRAVEL_H
#include "booking.h"
#include <vector>


class Travel
{
public:
    Travel(long, long);
    void addBooking(std::shared_ptr<Booking>);
    std::vector <std::shared_ptr<Booking>> getTravelBookings();
    std::pair<std::string, std::string> calculateTravelDates() const;
    long getId();

private:
    long id;
    long customerId;
    std::vector<std::shared_ptr<Booking>> travelBookings;

};

#endif // TRAVEL_H
