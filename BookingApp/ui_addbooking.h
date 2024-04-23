/********************************************************************************
** Form generated from reading UI file 'addbooking.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKING_H
#define UI_ADDBOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBooking
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QPushButton *rentalCarReservationButton;
    QCheckBox *addToNewTravel;
    QPushButton *hotelBookingButton;
    QPushButton *flightBookingButton;
    QStackedWidget *bookingAttributePages;
    QWidget *rentalCarReservierungPage;
    QDoubleSpinBox *PriceCarEdit;
    QLabel *label_7;
    QLabel *label_8;
    QDateEdit *startDateCarEdit;
    QLabel *label_9;
    QDateEdit *endDateCarEdit;
    QLineEdit *returnLocEdit;
    QLabel *label_21;
    QLineEdit *companyEdit;
    QLineEdit *pickupLocEdit;
    QLabel *label_23;
    QLabel *label_26;
    QLabel *label_22;
    QLineEdit *vehicleClassEdit;
    QLineEdit *pred1CarEdit;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *pred2CarEdit;
    QWidget *flightBookingPage;
    QLabel *label_2;
    QDateEdit *startDateFlightEdit;
    QLabel *label_3;
    QDateEdit *endDateFlightEdit;
    QDoubleSpinBox *priceFlightSpinbox;
    QLabel *label_6;
    QLineEdit *toCodeEdit;
    QLineEdit *bookingClassEdit;
    QLineEdit *fromCodeEdit;
    QLineEdit *airlineEdit;
    QLabel *label_24;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *pred1FlightEdit;
    QLineEdit *pred2FlightEdit;
    QLabel *label_25;
    QLabel *label_27;
    QWidget *hotelBookingPage;
    QDoubleSpinBox *priceHotelEdit;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDateEdit *startDateHotelEdit;
    QDateEdit *endDateHotelEdit;
    QLabel *label_31;
    QLabel *label_30;
    QLineEdit *hotelEdit;
    QLineEdit *roomTypeEdit;
    QLineEdit *townEdit;
    QLabel *label_32;
    QLineEdit *pred1HotelEdit;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *pred2HotelEdit;
    QCheckBox *addToSelectedTravel;

    void setupUi(QDialog *AddBooking)
    {
        if (AddBooking->objectName().isEmpty())
            AddBooking->setObjectName("AddBooking");
        AddBooking->resize(495, 500);
        buttonBox = new QDialogButtonBox(AddBooking);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(90, 450, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddBooking);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 81, 20));
        rentalCarReservationButton = new QPushButton(AddBooking);
        rentalCarReservationButton->setObjectName("rentalCarReservationButton");
        rentalCarReservationButton->setGeometry(QRect(10, 20, 61, 51));
        addToNewTravel = new QCheckBox(AddBooking);
        addToNewTravel->setObjectName("addToNewTravel");
        addToNewTravel->setGeometry(QRect(10, 420, 121, 20));
        hotelBookingButton = new QPushButton(AddBooking);
        hotelBookingButton->setObjectName("hotelBookingButton");
        hotelBookingButton->setGeometry(QRect(350, 20, 61, 51));
        flightBookingButton = new QPushButton(AddBooking);
        flightBookingButton->setObjectName("flightBookingButton");
        flightBookingButton->setGeometry(QRect(180, 20, 61, 51));
        bookingAttributePages = new QStackedWidget(AddBooking);
        bookingAttributePages->setObjectName("bookingAttributePages");
        bookingAttributePages->setGeometry(QRect(10, 80, 431, 301));
        rentalCarReservierungPage = new QWidget();
        rentalCarReservierungPage->setObjectName("rentalCarReservierungPage");
        PriceCarEdit = new QDoubleSpinBox(rentalCarReservierungPage);
        PriceCarEdit->setObjectName("PriceCarEdit");
        PriceCarEdit->setGeometry(QRect(90, 70, 96, 22));
        PriceCarEdit->setMaximum(9999999999.000000000000000);
        label_7 = new QLabel(rentalCarReservierungPage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(12, 40, 47, 16));
        label_8 = new QLabel(rentalCarReservierungPage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(12, 68, 26, 16));
        startDateCarEdit = new QDateEdit(rentalCarReservierungPage);
        startDateCarEdit->setObjectName("startDateCarEdit");
        startDateCarEdit->setGeometry(QRect(90, 10, 79, 22));
        label_9 = new QLabel(rentalCarReservierungPage);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(12, 12, 51, 16));
        endDateCarEdit = new QDateEdit(rentalCarReservierungPage);
        endDateCarEdit->setObjectName("endDateCarEdit");
        endDateCarEdit->setGeometry(QRect(90, 40, 79, 22));
        returnLocEdit = new QLineEdit(rentalCarReservierungPage);
        returnLocEdit->setObjectName("returnLocEdit");
        returnLocEdit->setGeometry(QRect(92, 145, 133, 22));
        label_21 = new QLabel(rentalCarReservierungPage);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(1, 145, 84, 16));
        companyEdit = new QLineEdit(rentalCarReservierungPage);
        companyEdit->setObjectName("companyEdit");
        companyEdit->setGeometry(QRect(92, 181, 133, 22));
        pickupLocEdit = new QLineEdit(rentalCarReservierungPage);
        pickupLocEdit->setObjectName("pickupLocEdit");
        pickupLocEdit->setGeometry(QRect(92, 109, 133, 22));
        label_23 = new QLabel(rentalCarReservierungPage);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(1, 109, 85, 16));
        label_26 = new QLabel(rentalCarReservierungPage);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(1, 217, 67, 16));
        label_22 = new QLabel(rentalCarReservierungPage);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(1, 181, 52, 16));
        vehicleClassEdit = new QLineEdit(rentalCarReservierungPage);
        vehicleClassEdit->setObjectName("vehicleClassEdit");
        vehicleClassEdit->setGeometry(QRect(92, 217, 133, 22));
        pred1CarEdit = new QLineEdit(rentalCarReservierungPage);
        pred1CarEdit->setObjectName("pred1CarEdit");
        pred1CarEdit->setGeometry(QRect(90, 250, 133, 22));
        label_28 = new QLabel(rentalCarReservierungPage);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(0, 250, 74, 16));
        label_29 = new QLabel(rentalCarReservierungPage);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(0, 280, 74, 16));
        pred2CarEdit = new QLineEdit(rentalCarReservierungPage);
        pred2CarEdit->setObjectName("pred2CarEdit");
        pred2CarEdit->setGeometry(QRect(90, 280, 133, 22));
        bookingAttributePages->addWidget(rentalCarReservierungPage);
        flightBookingPage = new QWidget();
        flightBookingPage->setObjectName("flightBookingPage");
        label_2 = new QLabel(flightBookingPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 20, 51, 16));
        startDateFlightEdit = new QDateEdit(flightBookingPage);
        startDateFlightEdit->setObjectName("startDateFlightEdit");
        startDateFlightEdit->setGeometry(QRect(120, 20, 79, 22));
        label_3 = new QLabel(flightBookingPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 50, 47, 16));
        endDateFlightEdit = new QDateEdit(flightBookingPage);
        endDateFlightEdit->setObjectName("endDateFlightEdit");
        endDateFlightEdit->setGeometry(QRect(120, 50, 79, 22));
        priceFlightSpinbox = new QDoubleSpinBox(flightBookingPage);
        priceFlightSpinbox->setObjectName("priceFlightSpinbox");
        priceFlightSpinbox->setGeometry(QRect(120, 80, 96, 22));
        priceFlightSpinbox->setMaximum(9999999999.000000000000000);
        label_6 = new QLabel(flightBookingPage);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 80, 26, 16));
        toCodeEdit = new QLineEdit(flightBookingPage);
        toCodeEdit->setObjectName("toCodeEdit");
        toCodeEdit->setGeometry(QRect(120, 170, 133, 22));
        bookingClassEdit = new QLineEdit(flightBookingPage);
        bookingClassEdit->setObjectName("bookingClassEdit");
        bookingClassEdit->setGeometry(QRect(120, 200, 133, 22));
        fromCodeEdit = new QLineEdit(flightBookingPage);
        fromCodeEdit->setObjectName("fromCodeEdit");
        fromCodeEdit->setGeometry(QRect(120, 140, 133, 22));
        airlineEdit = new QLineEdit(flightBookingPage);
        airlineEdit->setObjectName("airlineEdit");
        airlineEdit->setGeometry(QRect(120, 110, 133, 22));
        label_24 = new QLabel(flightBookingPage);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(1, 201, 74, 16));
        label_13 = new QLabel(flightBookingPage);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1, 105, 34, 16));
        label_15 = new QLabel(flightBookingPage);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(1, 169, 91, 16));
        label_16 = new QLabel(flightBookingPage);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(1, 137, 111, 16));
        pred1FlightEdit = new QLineEdit(flightBookingPage);
        pred1FlightEdit->setObjectName("pred1FlightEdit");
        pred1FlightEdit->setGeometry(QRect(120, 230, 133, 22));
        pred2FlightEdit = new QLineEdit(flightBookingPage);
        pred2FlightEdit->setObjectName("pred2FlightEdit");
        pred2FlightEdit->setGeometry(QRect(120, 260, 133, 22));
        label_25 = new QLabel(flightBookingPage);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(0, 230, 74, 16));
        label_27 = new QLabel(flightBookingPage);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(0, 260, 74, 16));
        bookingAttributePages->addWidget(flightBookingPage);
        hotelBookingPage = new QWidget();
        hotelBookingPage->setObjectName("hotelBookingPage");
        priceHotelEdit = new QDoubleSpinBox(hotelBookingPage);
        priceHotelEdit->setObjectName("priceHotelEdit");
        priceHotelEdit->setGeometry(QRect(80, 60, 96, 22));
        priceHotelEdit->setMaximum(9999999999.000000000000000);
        label_10 = new QLabel(hotelBookingPage);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(2, 30, 47, 16));
        label_11 = new QLabel(hotelBookingPage);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(2, 58, 26, 16));
        label_12 = new QLabel(hotelBookingPage);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(2, 2, 51, 16));
        startDateHotelEdit = new QDateEdit(hotelBookingPage);
        startDateHotelEdit->setObjectName("startDateHotelEdit");
        startDateHotelEdit->setGeometry(QRect(80, 0, 79, 22));
        endDateHotelEdit = new QDateEdit(hotelBookingPage);
        endDateHotelEdit->setObjectName("endDateHotelEdit");
        endDateHotelEdit->setGeometry(QRect(80, 30, 79, 22));
        label_31 = new QLabel(hotelBookingPage);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(0, 120, 27, 16));
        label_30 = new QLabel(hotelBookingPage);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(0, 90, 59, 16));
        hotelEdit = new QLineEdit(hotelBookingPage);
        hotelEdit->setObjectName("hotelEdit");
        hotelEdit->setGeometry(QRect(80, 90, 311, 22));
        roomTypeEdit = new QLineEdit(hotelBookingPage);
        roomTypeEdit->setObjectName("roomTypeEdit");
        roomTypeEdit->setGeometry(QRect(80, 150, 311, 22));
        townEdit = new QLineEdit(hotelBookingPage);
        townEdit->setObjectName("townEdit");
        townEdit->setGeometry(QRect(80, 120, 311, 22));
        label_32 = new QLabel(hotelBookingPage);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(0, 150, 59, 16));
        pred1HotelEdit = new QLineEdit(hotelBookingPage);
        pred1HotelEdit->setObjectName("pred1HotelEdit");
        pred1HotelEdit->setGeometry(QRect(80, 180, 133, 22));
        label_33 = new QLabel(hotelBookingPage);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(0, 180, 74, 16));
        label_34 = new QLabel(hotelBookingPage);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(0, 210, 74, 16));
        pred2HotelEdit = new QLineEdit(hotelBookingPage);
        pred2HotelEdit->setObjectName("pred2HotelEdit");
        pred2HotelEdit->setGeometry(QRect(80, 210, 133, 22));
        bookingAttributePages->addWidget(hotelBookingPage);
        addToSelectedTravel = new QCheckBox(AddBooking);
        addToSelectedTravel->setObjectName("addToSelectedTravel");
        addToSelectedTravel->setGeometry(QRect(150, 420, 191, 20));

        retranslateUi(AddBooking);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBooking, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBooking, qOverload<>(&QDialog::reject));

        bookingAttributePages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AddBooking);
    } // setupUi

    void retranslateUi(QDialog *AddBooking)
    {
        AddBooking->setWindowTitle(QCoreApplication::translate("AddBooking", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddBooking", "Booking Type", nullptr));
        rentalCarReservationButton->setText(QString());
        addToNewTravel->setText(QCoreApplication::translate("AddBooking", "Add to a new travel", nullptr));
        hotelBookingButton->setText(QString());
        flightBookingButton->setText(QString());
        label_7->setText(QCoreApplication::translate("AddBooking", "End Date", nullptr));
        label_8->setText(QCoreApplication::translate("AddBooking", "Price", nullptr));
        label_9->setText(QCoreApplication::translate("AddBooking", "Start Date", nullptr));
        label_21->setText(QCoreApplication::translate("AddBooking", "Return Location", nullptr));
        label_23->setText(QCoreApplication::translate("AddBooking", "Pickup Location", nullptr));
        label_26->setText(QCoreApplication::translate("AddBooking", "Vehicle Class", nullptr));
        label_22->setText(QCoreApplication::translate("AddBooking", "Company", nullptr));
        label_28->setText(QCoreApplication::translate("AddBooking", "Predecessor 1", nullptr));
        label_29->setText(QCoreApplication::translate("AddBooking", "Predecessor 2", nullptr));
        label_2->setText(QCoreApplication::translate("AddBooking", "Start Date", nullptr));
        label_3->setText(QCoreApplication::translate("AddBooking", "End Date", nullptr));
        label_6->setText(QCoreApplication::translate("AddBooking", "Price", nullptr));
        label_24->setText(QCoreApplication::translate("AddBooking", "Booking Class", nullptr));
        label_13->setText(QCoreApplication::translate("AddBooking", "Airline", nullptr));
        label_15->setText(QCoreApplication::translate("AddBooking", "To (Airport Code)", nullptr));
        label_16->setText(QCoreApplication::translate("AddBooking", "From (Airport Code)", nullptr));
        label_25->setText(QCoreApplication::translate("AddBooking", "Predecessor 1", nullptr));
        label_27->setText(QCoreApplication::translate("AddBooking", "Predecessor 2", nullptr));
        label_10->setText(QCoreApplication::translate("AddBooking", "End Date", nullptr));
        label_11->setText(QCoreApplication::translate("AddBooking", "Price", nullptr));
        label_12->setText(QCoreApplication::translate("AddBooking", "Start Date", nullptr));
        label_31->setText(QCoreApplication::translate("AddBooking", "Stadt", nullptr));
        label_30->setText(QCoreApplication::translate("AddBooking", "Hotelname", nullptr));
        label_32->setText(QCoreApplication::translate("AddBooking", "Zimmertyp", nullptr));
        label_33->setText(QCoreApplication::translate("AddBooking", "Predecessor 1", nullptr));
        label_34->setText(QCoreApplication::translate("AddBooking", "Predecessor 2", nullptr));
        addToSelectedTravel->setText(QCoreApplication::translate("AddBooking", "Add to current selected travel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBooking: public Ui_AddBooking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKING_H
