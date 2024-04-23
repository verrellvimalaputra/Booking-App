/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyUI
{
public:
    QAction *actionEinlesen;
    QAction *actionKundenSuchen;
    QAction *actionJSON;
    QWidget *centralwidget;
    QGroupBox *cutomerGroupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *customerIDEdit;
    QLineEdit *customerNameEdit;
    QTableWidget *customerTravelTable;
    QPushButton *addBookingButton;
    QGroupBox *travelGroupBox;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *travelIDEdit;
    QTableWidget *travelTable;
    QPushButton *showOnMapButton;
    QGroupBox *bookingDetailsGroupBox;
    QLabel *label_5;
    QLineEdit *bookingIDEdit;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QTabWidget *bookingTabs;
    QWidget *CarRental;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_23;
    QLineEdit *pickupLocEdit;
    QLineEdit *companyEdit;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *vehicleClassEdit;
    QLineEdit *returnLocEdit;
    QLabel *label_26;
    QWidget *FlightBooking;
    QLabel *label_10;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *bookingClassEdit;
    QLineEdit *airlineEdit;
    QLineEdit *fromEdit;
    QLabel *label_24;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *toDestEdit;
    QLineEdit *fromCodeEdit;
    QLineEdit *toCodeEdit;
    QWidget *HotelBooking;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *hotelEdit;
    QLabel *label_30;
    QLineEdit *roomTypeEdit;
    QLabel *label_31;
    QLineEdit *townEdit;
    QLabel *label_32;
    QDoubleSpinBox *priceSpinBox;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *readFileButton;
    QPushButton *customerSearchButton;
    QPushButton *addNewCustomerButton;
    QPushButton *checkTestButton;
    QPushButton *ABCButton;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuSave_as;
    QMenu *menuKund_innen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TravelAgencyUI)
    {
        if (TravelAgencyUI->objectName().isEmpty())
            TravelAgencyUI->setObjectName("TravelAgencyUI");
        TravelAgencyUI->resize(1189, 807);
        actionEinlesen = new QAction(TravelAgencyUI);
        actionEinlesen->setObjectName("actionEinlesen");
        actionEinlesen->setCheckable(false);
        actionKundenSuchen = new QAction(TravelAgencyUI);
        actionKundenSuchen->setObjectName("actionKundenSuchen");
        actionJSON = new QAction(TravelAgencyUI);
        actionJSON->setObjectName("actionJSON");
        centralwidget = new QWidget(TravelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        cutomerGroupBox = new QGroupBox(centralwidget);
        cutomerGroupBox->setObjectName("cutomerGroupBox");
        cutomerGroupBox->setGeometry(QRect(10, 50, 611, 371));
        label = new QLabel(cutomerGroupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 16, 16));
        label_2 = new QLabel(cutomerGroupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 41, 16));
        label_3 = new QLabel(cutomerGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 41, 16));
        customerIDEdit = new QLineEdit(cutomerGroupBox);
        customerIDEdit->setObjectName("customerIDEdit");
        customerIDEdit->setGeometry(QRect(60, 30, 41, 22));
        customerNameEdit = new QLineEdit(cutomerGroupBox);
        customerNameEdit->setObjectName("customerNameEdit");
        customerNameEdit->setGeometry(QRect(60, 60, 251, 22));
        customerTravelTable = new QTableWidget(cutomerGroupBox);
        if (customerTravelTable->columnCount() < 3)
            customerTravelTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        customerTravelTable->setObjectName("customerTravelTable");
        customerTravelTable->setGeometry(QRect(60, 90, 521, 231));
        customerTravelTable->setAutoFillBackground(false);
        customerTravelTable->horizontalHeader()->setVisible(true);
        customerTravelTable->horizontalHeader()->setCascadingSectionResizes(false);
        customerTravelTable->horizontalHeader()->setDefaultSectionSize(173);
        customerTravelTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        customerTravelTable->horizontalHeader()->setStretchLastSection(false);
        customerTravelTable->verticalHeader()->setVisible(false);
        customerTravelTable->verticalHeader()->setStretchLastSection(false);
        addBookingButton = new QPushButton(cutomerGroupBox);
        addBookingButton->setObjectName("addBookingButton");
        addBookingButton->setGeometry(QRect(480, 330, 101, 24));
        travelGroupBox = new QGroupBox(centralwidget);
        travelGroupBox->setObjectName("travelGroupBox");
        travelGroupBox->setGeometry(QRect(10, 430, 611, 321));
        label_4 = new QLabel(travelGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 51, 16));
        label_6 = new QLabel(travelGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 60, 41, 16));
        travelIDEdit = new QLineEdit(travelGroupBox);
        travelIDEdit->setObjectName("travelIDEdit");
        travelIDEdit->setGeometry(QRect(60, 30, 41, 22));
        travelTable = new QTableWidget(travelGroupBox);
        if (travelTable->columnCount() < 4)
            travelTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        travelTable->setObjectName("travelTable");
        travelTable->setGeometry(QRect(60, 60, 531, 221));
        travelTable->setAutoFillBackground(false);
        travelTable->horizontalHeader()->setVisible(true);
        travelTable->horizontalHeader()->setCascadingSectionResizes(false);
        travelTable->horizontalHeader()->setDefaultSectionSize(129);
        travelTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        travelTable->horizontalHeader()->setStretchLastSection(false);
        travelTable->verticalHeader()->setVisible(false);
        travelTable->verticalHeader()->setStretchLastSection(false);
        showOnMapButton = new QPushButton(travelGroupBox);
        showOnMapButton->setObjectName("showOnMapButton");
        showOnMapButton->setGeometry(QRect(490, 290, 101, 24));
        bookingDetailsGroupBox = new QGroupBox(centralwidget);
        bookingDetailsGroupBox->setObjectName("bookingDetailsGroupBox");
        bookingDetailsGroupBox->setGeometry(QRect(640, 50, 531, 701));
        label_5 = new QLabel(bookingDetailsGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 30, 71, 16));
        bookingIDEdit = new QLineEdit(bookingDetailsGroupBox);
        bookingIDEdit->setObjectName("bookingIDEdit");
        bookingIDEdit->setGeometry(QRect(110, 30, 361, 22));
        startDateEdit = new QDateEdit(bookingDetailsGroupBox);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setGeometry(QRect(110, 60, 110, 22));
        endDateEdit = new QDateEdit(bookingDetailsGroupBox);
        endDateEdit->setObjectName("endDateEdit");
        endDateEdit->setGeometry(QRect(110, 90, 110, 22));
        label_7 = new QLabel(bookingDetailsGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 60, 49, 16));
        label_8 = new QLabel(bookingDetailsGroupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 90, 49, 16));
        label_9 = new QLabel(bookingDetailsGroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 120, 49, 16));
        bookingTabs = new QTabWidget(bookingDetailsGroupBox);
        bookingTabs->setObjectName("bookingTabs");
        bookingTabs->setGeometry(QRect(10, 160, 511, 331));
        CarRental = new QWidget();
        CarRental->setObjectName("CarRental");
        layoutWidget_2 = new QWidget(CarRental);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 10, 491, 151));
        gridLayout_2 = new QGridLayout(layoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget_2);
        label_23->setObjectName("label_23");

        gridLayout_2->addWidget(label_23, 0, 0, 1, 1);

        pickupLocEdit = new QLineEdit(layoutWidget_2);
        pickupLocEdit->setObjectName("pickupLocEdit");

        gridLayout_2->addWidget(pickupLocEdit, 0, 1, 1, 1);

        companyEdit = new QLineEdit(layoutWidget_2);
        companyEdit->setObjectName("companyEdit");

        gridLayout_2->addWidget(companyEdit, 2, 1, 1, 1);

        label_21 = new QLabel(layoutWidget_2);
        label_21->setObjectName("label_21");

        gridLayout_2->addWidget(label_21, 1, 0, 1, 1);

        label_22 = new QLabel(layoutWidget_2);
        label_22->setObjectName("label_22");

        gridLayout_2->addWidget(label_22, 2, 0, 1, 1);

        vehicleClassEdit = new QLineEdit(layoutWidget_2);
        vehicleClassEdit->setObjectName("vehicleClassEdit");

        gridLayout_2->addWidget(vehicleClassEdit, 3, 1, 1, 1);

        returnLocEdit = new QLineEdit(layoutWidget_2);
        returnLocEdit->setObjectName("returnLocEdit");

        gridLayout_2->addWidget(returnLocEdit, 1, 1, 1, 1);

        label_26 = new QLabel(layoutWidget_2);
        label_26->setObjectName("label_26");

        gridLayout_2->addWidget(label_26, 3, 0, 1, 1);

        bookingTabs->addTab(CarRental, QString());
        FlightBooking = new QWidget();
        FlightBooking->setObjectName("FlightBooking");
        label_10 = new QLabel(FlightBooking);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 70, 31, 16));
        layoutWidget = new QWidget(FlightBooking);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 431, 171));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bookingClassEdit = new QLineEdit(layoutWidget);
        bookingClassEdit->setObjectName("bookingClassEdit");

        gridLayout->addWidget(bookingClassEdit, 3, 1, 1, 1);

        airlineEdit = new QLineEdit(layoutWidget);
        airlineEdit->setObjectName("airlineEdit");

        gridLayout->addWidget(airlineEdit, 0, 1, 1, 1);

        fromEdit = new QLineEdit(layoutWidget);
        fromEdit->setObjectName("fromEdit");

        gridLayout->addWidget(fromEdit, 1, 1, 1, 1);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName("label_24");

        gridLayout->addWidget(label_24, 3, 0, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");

        gridLayout->addWidget(label_15, 2, 0, 1, 1);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName("label_16");

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        toDestEdit = new QLineEdit(layoutWidget);
        toDestEdit->setObjectName("toDestEdit");

        gridLayout->addWidget(toDestEdit, 2, 1, 1, 1);

        fromCodeEdit = new QLineEdit(FlightBooking);
        fromCodeEdit->setObjectName("fromCodeEdit");
        fromCodeEdit->setGeometry(QRect(450, 60, 51, 22));
        toCodeEdit = new QLineEdit(FlightBooking);
        toCodeEdit->setObjectName("toCodeEdit");
        toCodeEdit->setGeometry(QRect(450, 100, 51, 22));
        bookingTabs->addTab(FlightBooking, QString());
        HotelBooking = new QWidget();
        HotelBooking->setObjectName("HotelBooking");
        layoutWidget_3 = new QWidget(HotelBooking);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(10, 10, 491, 121));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        hotelEdit = new QLineEdit(layoutWidget_3);
        hotelEdit->setObjectName("hotelEdit");

        gridLayout_3->addWidget(hotelEdit, 0, 1, 1, 1);

        label_30 = new QLabel(layoutWidget_3);
        label_30->setObjectName("label_30");

        gridLayout_3->addWidget(label_30, 0, 0, 1, 1);

        roomTypeEdit = new QLineEdit(layoutWidget_3);
        roomTypeEdit->setObjectName("roomTypeEdit");

        gridLayout_3->addWidget(roomTypeEdit, 2, 1, 1, 1);

        label_31 = new QLabel(layoutWidget_3);
        label_31->setObjectName("label_31");

        gridLayout_3->addWidget(label_31, 1, 0, 1, 1);

        townEdit = new QLineEdit(layoutWidget_3);
        townEdit->setObjectName("townEdit");

        gridLayout_3->addWidget(townEdit, 1, 1, 1, 1);

        label_32 = new QLabel(layoutWidget_3);
        label_32->setObjectName("label_32");

        gridLayout_3->addWidget(label_32, 2, 0, 1, 1);

        bookingTabs->addTab(HotelBooking, QString());
        priceSpinBox = new QDoubleSpinBox(bookingDetailsGroupBox);
        priceSpinBox->setObjectName("priceSpinBox");
        priceSpinBox->setGeometry(QRect(110, 120, 131, 22));
        priceSpinBox->setMaximum(9999999999.000000000000000);
        saveButton = new QPushButton(bookingDetailsGroupBox);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(360, 660, 75, 21));
        cancelButton = new QPushButton(bookingDetailsGroupBox);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(440, 660, 75, 21));
        readFileButton = new QPushButton(centralwidget);
        readFileButton->setObjectName("readFileButton");
        readFileButton->setGeometry(QRect(10, 10, 51, 41));
        customerSearchButton = new QPushButton(centralwidget);
        customerSearchButton->setObjectName("customerSearchButton");
        customerSearchButton->setGeometry(QRect(70, 10, 51, 41));
        addNewCustomerButton = new QPushButton(centralwidget);
        addNewCustomerButton->setObjectName("addNewCustomerButton");
        addNewCustomerButton->setGeometry(QRect(130, 10, 51, 41));
        checkTestButton = new QPushButton(centralwidget);
        checkTestButton->setObjectName("checkTestButton");
        checkTestButton->setGeometry(QRect(190, 10, 71, 41));
        ABCButton = new QPushButton(centralwidget);
        ABCButton->setObjectName("ABCButton");
        ABCButton->setGeometry(QRect(270, 10, 81, 41));
        TravelAgencyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TravelAgencyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1189, 22));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuSave_as = new QMenu(menuDatei);
        menuSave_as->setObjectName("menuSave_as");
        menuKund_innen = new QMenu(menubar);
        menuKund_innen->setObjectName("menuKund_innen");
        TravelAgencyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TravelAgencyUI);
        statusbar->setObjectName("statusbar");
        TravelAgencyUI->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuKund_innen->menuAction());
        menuDatei->addAction(actionEinlesen);
        menuDatei->addAction(menuSave_as->menuAction());
        menuSave_as->addAction(actionJSON);
        menuKund_innen->addAction(actionKundenSuchen);

        retranslateUi(TravelAgencyUI);
        QObject::connect(readFileButton, &QPushButton::clicked, actionEinlesen, qOverload<>(&QAction::trigger));
        QObject::connect(customerSearchButton, &QPushButton::clicked, actionKundenSuchen, qOverload<>(&QAction::trigger));

        bookingTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TravelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyUI)
    {
        TravelAgencyUI->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "MainWindow", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("TravelAgencyUI", "Einlesen", nullptr));
#if QT_CONFIG(shortcut)
        actionEinlesen->setShortcut(QCoreApplication::translate("TravelAgencyUI", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionKundenSuchen->setText(QCoreApplication::translate("TravelAgencyUI", "Suchen", nullptr));
        actionJSON->setText(QCoreApplication::translate("TravelAgencyUI", "JSON", nullptr));
        cutomerGroupBox->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*in", nullptr));
        label->setText(QCoreApplication::translate("TravelAgencyUI", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("TravelAgencyUI", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("TravelAgencyUI", "Reisen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = customerTravelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = customerTravelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TravelAgencyUI", "Beginn der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = customerTravelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TravelAgencyUI", "Ende der Reise", nullptr));
        addBookingButton->setText(QCoreApplication::translate("TravelAgencyUI", "Add Booking", nullptr));
        travelGroupBox->setTitle(QCoreApplication::translate("TravelAgencyUI", "Reise", nullptr));
        label_4->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        label_6->setText(QCoreApplication::translate("TravelAgencyUI", "Reisen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = travelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungstyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = travelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TravelAgencyUI", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = travelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TravelAgencyUI", "Ende", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = travelTable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TravelAgencyUI", "Preis", nullptr));
        showOnMapButton->setText(QCoreApplication::translate("TravelAgencyUI", "Show on Map", nullptr));
        bookingDetailsGroupBox->setTitle(QCoreApplication::translate("TravelAgencyUI", "Buchungsdetails", nullptr));
        label_5->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungs-ID", nullptr));
        label_7->setText(QCoreApplication::translate("TravelAgencyUI", "Start", nullptr));
        label_8->setText(QCoreApplication::translate("TravelAgencyUI", "Ende", nullptr));
        label_9->setText(QCoreApplication::translate("TravelAgencyUI", "Preis", nullptr));
        label_23->setText(QCoreApplication::translate("TravelAgencyUI", "Pickup Location", nullptr));
        label_21->setText(QCoreApplication::translate("TravelAgencyUI", "Return Location", nullptr));
        label_22->setText(QCoreApplication::translate("TravelAgencyUI", "Company", nullptr));
        label_26->setText(QCoreApplication::translate("TravelAgencyUI", "Vehicle Class", nullptr));
        bookingTabs->setTabText(bookingTabs->indexOf(CarRental), QCoreApplication::translate("TravelAgencyUI", "Mietwagenreservierung", nullptr));
        label_10->setText(QString());
        label_24->setText(QCoreApplication::translate("TravelAgencyUI", "Booking Class", nullptr));
        label_13->setText(QCoreApplication::translate("TravelAgencyUI", "Airline", nullptr));
        label_15->setText(QCoreApplication::translate("TravelAgencyUI", "To", nullptr));
        label_16->setText(QCoreApplication::translate("TravelAgencyUI", "From", nullptr));
        bookingTabs->setTabText(bookingTabs->indexOf(FlightBooking), QCoreApplication::translate("TravelAgencyUI", "Flug Buchung", nullptr));
        label_30->setText(QCoreApplication::translate("TravelAgencyUI", "Hotelname", nullptr));
        label_31->setText(QCoreApplication::translate("TravelAgencyUI", "Stadt", nullptr));
        label_32->setText(QCoreApplication::translate("TravelAgencyUI", "Zimmertyp", nullptr));
        bookingTabs->setTabText(bookingTabs->indexOf(HotelBooking), QCoreApplication::translate("TravelAgencyUI", "Hotel Buchung", nullptr));
        saveButton->setText(QCoreApplication::translate("TravelAgencyUI", "Speichern", nullptr));
        cancelButton->setText(QCoreApplication::translate("TravelAgencyUI", "Abbrechen", nullptr));
        readFileButton->setText(QString());
        customerSearchButton->setText(QString());
        addNewCustomerButton->setText(QString());
        checkTestButton->setText(QCoreApplication::translate("TravelAgencyUI", "Check Test", nullptr));
        ABCButton->setText(QCoreApplication::translate("TravelAgencyUI", "ABC Analyse", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("TravelAgencyUI", "Datei", nullptr));
        menuSave_as->setTitle(QCoreApplication::translate("TravelAgencyUI", "Save as", nullptr));
        menuKund_innen->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*innen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyUI: public Ui_TravelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
