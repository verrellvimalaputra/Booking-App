#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QDateTime>
#include <QLocale>
#include <QByteArray>
#include "addcustomer.h"
#include "customersearchdialog.h"
#include "travelagency.h"
#include "addbooking.h"
#include "savetojson.h"
#include "testresult.h"
#include "abcdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TravelAgencyUI; }
QT_END_NAMESPACE

class TravelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    TravelAgencyUI(TravelAgency* travelAgency, QWidget *parent = nullptr);
    ~TravelAgencyUI();
    void addToList();
    void clearBookingDetails();
    void searchCustomer(long customerId);
    void openCustomerSearchDialog();
    void disableButtons();
    void enableButtons();
    void updateSelectedBooking();
    void updateDetailView();
    void updateTravelList();
    void updateBookingList(std::shared_ptr<Travel>);

private slots:
    void on_actionEinlesen_triggered();
    void on_actionKundenSuchen_triggered();
    void on_actionJSON_triggered();
    //    void on_bookingList_itemClicked(QListWidgetItem *item);


    void on_travelTable_itemClicked(QTableWidgetItem *item);

    void on_customerTravelTable_itemClicked(QTableWidgetItem *item);

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_showOnMapButton_clicked();

    void on_addNewCustomerButton_clicked();

    void on_addBookingButton_clicked();

    void handleBookingCreated(std::shared_ptr<Booking> booking, bool addToNewTravel);

    void handleSaveToJson(std::string criterion);

    void on_checkTestButton_clicked();

    void on_ABCButton_clicked();

private:
    Ui::TravelAgencyUI *ui;
    CustomerSearchDialog *customerSearchDialog;
    AddCustomer *addCustomer;
    SaveToJson *saveToJson;
    AddBooking *addBooking;
    TestResult *testResult;
    ABCDialog *abcDialog;
    TravelAgency* travelAgency;
};
#endif // TRAVELAGENCYUI_H
