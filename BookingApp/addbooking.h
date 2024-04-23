#ifndef ADDBOOKING_H
#define ADDBOOKING_H
#include "booking.h"
#include <QDialog>
#include <QUuid>
#include <QMessageBox>

namespace Ui {
class AddBooking;
}

class AddBooking : public QDialog
{
    Q_OBJECT

public:
    explicit AddBooking(QWidget *parent = nullptr);
    ~AddBooking();
    std::shared_ptr<Booking> makeRentalCarReservation();
    std::shared_ptr<Booking> makeFlightBooking();
    std::shared_ptr<Booking> makeHotelBooking();

signals:
    void bookingCreated(std::shared_ptr<Booking> booking, bool addToNewTravel);

private slots:
    void on_buttonBox_accepted();

    void on_rentalCarReservationButton_clicked();

    void on_flightBookingButton_clicked();

    void on_hotelBookingButton_clicked();



    void on_addToNewTravel_clicked();

    void on_addToSelectedTravel_clicked();

private:
    bool addToNewTravel;
    Ui::AddBooking *ui;
};

#endif // ADDBOOKING_H
