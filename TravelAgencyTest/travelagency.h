#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QUrl>
//#include <QDesktopServices>
#include "booking.h"
#include "travel.h"
#include "customer.h"
#include "airport.h"



class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    std::vector<std::shared_ptr<Booking>> getBookings() const;
    void displayBookings();
    void readFile(QString);
    void readIataCodes(QString);
    QString getBookingsInfo();
    void clearBookings();
    void clearTravels();
    void clearCustomers();
//    void displayBookingsOnMap(const std::shared_ptr<Travel>& travel);

    std::shared_ptr<Booking> findBooking (std::string);
    std::shared_ptr<Travel> findTravel (long);
    std::shared_ptr<Customer> findCustomer (long);
    std::shared_ptr<Airport> findAirport (std::string);
    //    void readBinaryFile();

private:
    std::vector<std::shared_ptr<Booking>> allBookings;
    std::vector<std::shared_ptr<Travel>> allTravels;
    std::vector<std::shared_ptr<Customer>> allCustomers;
    std::vector<std::shared_ptr<Airport>> allAirports;
};

#endif // TRAVELAGENCY_H

