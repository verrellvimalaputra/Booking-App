#include <QtTest>
#include "travelagency.h"
#include "rentalcarreservation.h"
#include "flightbooking.h"
#include "hotelbooking.h"

// add necessary includes herea

class TravelAgencyTest : public QObject
{
    Q_OBJECT

public:
    TravelAgencyTest();
    ~TravelAgencyTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testEuropcarBookings();
    void testAirFranceBookings();
    void testSuiteOrApartmentBookings();

private:
    TravelAgency travelAgency;  // Member variable to store the TravelAgency instance

};

TravelAgencyTest::TravelAgencyTest()
{

}

TravelAgencyTest::~TravelAgencyTest()
{

}

void TravelAgencyTest::initTestCase()
{
    // Perform any setup actions before the tests start
    travelAgency.readFile("bookingsPraktikum4.json");
}

void TravelAgencyTest::cleanupTestCase()
{
    // Perform any cleanup actions after all the tests are completed
}

void TravelAgencyTest::testEuropcarBookings()
{
    int count = 0;

    for (std::shared_ptr<Booking> booking : travelAgency.getBookings()) {
        if (std::shared_ptr<RentalCarReservation> rentalCar = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            if (rentalCar->getCompany() == "Europcar") {
                count++;
            }
        }
    }

    QCOMPARE(count, 7);
}

void TravelAgencyTest::testAirFranceBookings()
{
    int count = 0;

    for (std::shared_ptr<Booking> booking : travelAgency.getBookings()) {
        if (std::shared_ptr<FlightBooking> flight = std::dynamic_pointer_cast<FlightBooking>(booking)) {
            if (flight->getAirline() == "Air France") {
                count++;
            }
        }
    }

    QCOMPARE(count, 4);
}

void TravelAgencyTest::testSuiteOrApartmentBookings()
{
    int count = 0;

    for (std::shared_ptr<Booking> booking : travelAgency.getBookings()) {
        if (std::shared_ptr<HotelBooking> hotel = std::dynamic_pointer_cast<HotelBooking>(booking)) {
            if (hotel->getRoomType() == "Suite" || hotel->getRoomType() == "Apartment") {
                count++;
            }
        }
    }

    QCOMPARE(count, 14);
}

QTEST_APPLESS_MAIN(TravelAgencyTest)

#include "tst_travelagencytest.moc"
