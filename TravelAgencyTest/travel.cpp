#include "travel.h"

Travel::Travel(long id, long customerId) : id(id), customerId(customerId)
{

}

void Travel::addBooking(std::shared_ptr<Booking> booking){
    travelBookings.push_back(booking);
}

long Travel::getId(){
    return id;
}

std::vector <std::shared_ptr<Booking>> Travel::getTravelBookings(){
    return travelBookings;
}

std::pair<std::string, std::string> Travel::calculateTravelDates() const
{
    std::string earliestStartDate;
    std::string latestEndDate;

    for (std::shared_ptr<Booking> booking : travelBookings) {
        std::string startDate = booking->getFromDate();
        std::string endDate = booking->getToDate();

        if (earliestStartDate.empty() || startDate < earliestStartDate) {
            earliestStartDate = startDate;
        }

        if (latestEndDate.empty() || endDate > latestEndDate) {
            latestEndDate = endDate;
        }
    }

    return std::make_pair(earliestStartDate, latestEndDate);
}
