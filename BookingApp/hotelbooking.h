#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
#include <string>
#include "booking.h"


class HotelBooking : public Booking
{
public:
    HotelBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string predecessor1, std::string predecessor2,
                 std::string hotel, std::string town, std::string roomType, double hotelLatitude, double hoteLongitude);
    ~HotelBooking();
    std::string showDetails();

    std::string getHotel();
    std::string getTown();
    std::string getRoomType();
    double getHotelLatitude();
    double getHotelLongitude();

    void setHotel(std::string);
    void setTown(std::string);
    void setRoomType(std::string);
    void setHotelLatitude(double);
    void setHotelLongitude(double);

private:
    std::string hotel;
    std::string town;
    std::string roomType;
    double hotelLatitude;
    double hotelLongitude;
};

#endif // HOTELBOOKING_H

