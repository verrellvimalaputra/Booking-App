#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H
#include <iostream>
#include <string>
#include "booking.h"


class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1, std::string predecessor2,
                         std::string pickupLocation, std::string returnLocation, std::string company, std::string vehicleClass,
                         double pickupLatitude, double pickupLongitude, double returnLatitude, double returnLongitude);
    ~RentalCarReservation();

    std::string showDetails();
    std::string getPickupLocation();
    std::string getReturnLocation();
    std::string getCompany();
    std::string getVehicleClass();
    double getPickupLatitude();
    double getPickupLongitude();
    double getReturnLatitude();
    double getReturnLongitude();

    void setPickupLocation(std::string);
    void setReturnLocation(std::string);
    void setCompany(std::string);
    void setVehicleClass(std::string);
    void setPickupLatitude(double);
    void setPickupLongitude(double);
    void setReturnLatitude(double);
    void setReturnLongitude(double);

private:
    std::string pickupLocation;
    std::string returnLocation;
    std::string company;
    std::string vehicleClass;
    double pickupLatitude;
    double pickupLongitude;
    double returnLatitude;
    double returnLongitude;
};

#endif // RENTALCARRESERVATION_H

