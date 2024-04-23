#ifndef TRAVEL_H
#define TRAVEL_H
#include "booking.h"
#include "digraph.h"
#include <vector>
#include <memory>

struct VertexData {
    int endtime;
    std::shared_ptr<Booking> booking;
};


class Travel
{
public:
    Travel(long, long);
    void addBooking(std::shared_ptr<Booking>);
    std::vector <std::shared_ptr<Booking>> getTravelBookings();
    std::pair<std::string, std::string> calculateTravelDates() const;
    long getId();
    long getCustomerId();
    void createGraph();
    void sortGraph(std::vector<VertexData> &data);
    double getTotalTravelPrice();

    bool checkRoundtrip(); // Function to check if the travel is a round trip
    bool checkEnoughHotels();
    bool checkNoUselessHotels();
    bool checkNoUselessRentalCars();

private:
    long id;
    long customerId;
    std::vector<std::shared_ptr<Booking>> travelBookings;
    Digraph<std::shared_ptr<Booking>, 100> travelGraph;

};

#endif // TRAVEL_H
