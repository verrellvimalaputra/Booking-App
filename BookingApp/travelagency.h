#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QUrl>
#include <QDesktopServices>
#include "booking.h"
#include "travel.h"
#include "customer.h"
#include "airport.h"
#include "sortfunktor.h"



class TravelAgency
{
public:
    TravelAgency();
    ~TravelAgency();
    std::vector<std::shared_ptr<Booking>> getBookings() const;
    std::vector<std::shared_ptr<Travel>> getTravels() const;
    std::vector<std::shared_ptr<Customer>> getCustomers() const;
    void displayBookings();
    void readFile(QString);
    void readIataCodes(QString);
    QString getBookingsInfo();
    void clearBookings();
    void clearTravels();
    void clearCustomers();
    void displayBookingsOnMap(const std::shared_ptr<Travel>& travel);
    long addNewCustomer(QString);
    void addNewBooking(std::shared_ptr<Booking>);
    long addBookingtoNewTravel(long, std::shared_ptr<Booking>);
    void sortBookings(const std::string& sortCriterion);
    void saveToJSON(const std::string& filename);
    double getTotalPrice();
    void abcAnalyse();

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

