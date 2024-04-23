#include "travelagencyui.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "ui_travelagencyui.h"


TravelAgencyUI::TravelAgencyUI(TravelAgency* travelAgency, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::TravelAgencyUI),
      travelAgency(travelAgency)
{
    ui->setupUi(this);
    ui->cutomerGroupBox->setVisible(false); //hide the customerGroupBox
    ui->travelGroupBox->setVisible(false); //hide the travelGroupBox
    ui->bookingDetailsGroupBox->setVisible(false); //hide the bookingDetailsGroupBox

    ui->saveButton->setEnabled(false);
    ui->cancelButton->setEnabled(false);

    ui->readFileButton->setIcon(QIcon("read file.png"));
    ui->customerSearchButton->setIcon(QIcon("search.png"));
    ui->addNewCustomerButton->setIcon(QIcon("addCustomerIcon.png"));

    // Connect signals to slots for enabling buttons when line edits are clicked and edited
    connect(ui->startDateEdit, &QDateEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->endDateEdit, &QDateEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    // Connect signals to slots for enabling buttons when flight booking details are clicked and edited
    connect(ui->airlineEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->fromEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->fromCodeEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->toDestEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->toCodeEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->bookingClassEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    // Connect signals to slots for enabling buttons when car rental details are clicked and edited
    connect(ui->pickupLocEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->returnLocEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->companyEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->vehicleClassEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    // Connect signals to slots for enabling buttons when hotel booking details are clicked and edited
    connect(ui->hotelEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->townEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
    connect(ui->roomTypeEdit, &QLineEdit::editingFinished, this, &TravelAgencyUI::enableButtons);
}

TravelAgencyUI::~TravelAgencyUI()
{
    delete ui;
}

void TravelAgencyUI::on_actionKundenSuchen_triggered(){
    // Create an instance of the CustomerSearchDialog
    CustomerSearchDialog customerSearchDialog(this);

    // Show the dialog as a modal dialog
    int result = customerSearchDialog.exec();

    if (result == QDialog::Accepted) {
        // Handle the accepted result
        long customerId = customerSearchDialog.getCustomerId();
        // Perform the search with the customerId
        searchCustomer(customerId);
    } else {
        // Handle the rejected result or cancel action
        // ...
    }
}


void TravelAgencyUI::on_actionEinlesen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON Files (*.json)"));
    bool isFileValid = false;
    while(!isFileValid){
        try{
            travelAgency->readFile(fileName);
            travelAgency->readIataCodes("iatacodes.json");
            //addToList();
            isFileValid = true;
            QMessageBox::information(this,tr("Datei erfolgreich eingelesen"),travelAgency->getBookingsInfo());
        }
        catch (const std::exception& e) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText(e.what());
            msgBox.setInformativeText("Das Einlesen der Buchungen wurde in der betroffenen Zeile gestoppt. Die vorangehenden Buchungen wurden erfolgreich angelegt.");
            msgBox.setDetailedText("Wenn Sie die Datei bereits korrigiert haben, wählen Sie 'Retry'. Wählen Sie 'Discard' um alle Buchungen zu löschen und 'Cancel', "
                                   "um die vohandenen Buchungen stehenzulassen und diesen Dialog zu verlassen.");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Retry);
            int ret = msgBox.exec();


            switch (ret) {
            case QMessageBox::Retry:
                isFileValid = false;
                break;
            case QMessageBox::Discard:
                isFileValid = true;
                travelAgency->clearBookings();
                travelAgency->clearTravels();
                travelAgency->clearCustomers();
                break;
            case QMessageBox::Cancel:
                isFileValid = true;

                break;
            default:
                // Should not be reached
                break;
            }
        }
    }
}

void TravelAgencyUI::searchCustomer(long customerId)
{
    ui->cutomerGroupBox->setVisible(false); //hide the customerGroupBox
    ui->travelGroupBox->setVisible(false); //hide the travelGroupBox
    ui->bookingDetailsGroupBox->setVisible(false); //hide the bookingDetailsGroupBox

    std::shared_ptr<Customer> customer = travelAgency->findCustomer(customerId);
    if (customer != nullptr) {
        // Customer found, display the details

        //set the ID and Name
        long customerId = customer->getId();
        QString customerIdString = QString::number(customerId);
        ui->customerIDEdit->setText(customerIdString);
        QString customerName = QString::fromStdString(customer->getName());
        ui->customerNameEdit->setText(customerName);


        // Clear existing table contents
        ui->customerTravelTable->clearContents();
        ui->customerTravelTable->setRowCount(0);

        //get the travelList
        const std::vector<std::shared_ptr<Travel>>& travelList = customer->getTravelList();


        // Set the number of rows in the table
        int rowCount = travelList.size();
        ui->customerTravelTable->setRowCount(rowCount);

        //filling the table
        for (int row = 0; row < rowCount; row++) {
            std::shared_ptr<Travel> travel = travelList[row];

            QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(std::to_string(travel->getId())));
            std::pair<std::string, std::string> travelDates = travel->calculateTravelDates();

            // Convert earliest start date
            QDateTime earliestStartDateTime = QDateTime::fromString(QString::fromStdString(travelDates.first), "yyyyMMdd");
            QString formattedEarliestStartDate = QLocale("de_DE").toString(earliestStartDateTime, "dddd, d. MMMM yyyy");

            // Convert latest end date
            QDateTime latestEndDateTime = QDateTime::fromString(QString::fromStdString(travelDates.second), "yyyyMMdd");
            QString formattedLatestEndDate = QLocale("de_DE").toString(latestEndDateTime, "dddd, d. MMMM yyyy");

            QTableWidgetItem* earliestStartDateItem = new QTableWidgetItem(formattedEarliestStartDate);
            QTableWidgetItem* latestEndDateItem = new QTableWidgetItem(formattedLatestEndDate);

            ui->customerTravelTable->setItem(row, 0, idItem);
            ui->customerTravelTable->setItem(row, 1, earliestStartDateItem);
            ui->customerTravelTable->setItem(row, 2, latestEndDateItem);
        }

        //to make the table not editable
        ui->customerTravelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->customerIDEdit->setReadOnly(true);
        ui->customerNameEdit->setReadOnly(true);


        // Show the QTableWidget for travel history
        ui->cutomerGroupBox->setVisible(true);
        // clear the customerTravelTable selected items
        ui->customerTravelTable->selectedItems().clear();

    } else {
        // Customer not found, display an error message
        QMessageBox::critical(this, "Error", "Customer not found!");
        // hide the QTableWidget for travel history
        ui->cutomerGroupBox->setVisible(false);
    }
}

void TravelAgencyUI::on_customerTravelTable_itemClicked(QTableWidgetItem *item)
{
    QIcon carIcon("Car.png");
    QIcon planeIcon("plane.png");
    QIcon hotelIcon("hotel.png");
    //retrieve the customer id from the customerIDEdit
    QString customerIdString = ui->customerIDEdit->text();
    long customerId = customerIdString.toLong();
    std::shared_ptr<Customer> customer = travelAgency->findCustomer(customerId);

    int selectedRow = ui->customerTravelTable->row(item);

    std::shared_ptr<Travel> selectedTravel = customer->getTravelList()[selectedRow];

    //set ID
    long travelId = selectedTravel->getId();
    QString travelIdString = QString::number(travelId);
    ui->travelIDEdit->setText(travelIdString);

    //get the travelBookings
    const std::vector<std::shared_ptr<Booking>> & travelBookings = selectedTravel->getTravelBookings();


    // Set the number of rows in the table
    int rowCount = travelBookings.size();
    ui->travelTable->setRowCount(rowCount);

    //filling the table
    for (int row = 0; row < rowCount; row++) {
        std::shared_ptr<Booking> booking = travelBookings[row];

        // Convert earliest start date
        QDateTime StartDateTime = QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
        QString formattedStartDate = QLocale("de_DE").toString(StartDateTime, "dddd, d. MMMM yyyy");

        // Convert latest end date
        QDateTime EndDateTime = QDateTime::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");
        QString formattedEndDate = QLocale("de_DE").toString(EndDateTime, "dddd, d. MMMM yyyy");

        QTableWidgetItem* startDateItem = new QTableWidgetItem(formattedStartDate);
        QTableWidgetItem* endDateItem = new QTableWidgetItem(formattedEndDate);

        QTableWidgetItem* travelPreis = new QTableWidgetItem(QString::number(booking->getPrice()));

        //set the icons
        if (std::dynamic_pointer_cast<FlightBooking>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(planeIcon);
            ui->travelTable->setItem(row, 0, icon);
        }
        else if (std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(carIcon);
            ui->travelTable->setItem(row, 0, icon);
        }
        else if (std::dynamic_pointer_cast<HotelBooking>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(hotelIcon);
            ui->travelTable->setItem(row, 0, icon);
        }

        ui->travelTable->setItem(row, 1, startDateItem);
        ui->travelTable->setItem(row, 2, endDateItem);
        ui->travelTable->setItem(row, 3, travelPreis);
    }

    //to make the table not editable
    ui->travelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->travelIDEdit->setReadOnly(true);


    // Show the QTableWidget for travel history
    ui->travelGroupBox->setVisible(true);
}

void TravelAgencyUI::on_travelTable_itemClicked(QTableWidgetItem *item)
{
    //retrieve the travel id from the travelIDEdit
    QString travelIdString = ui->travelIDEdit->text();
    long travelId = travelIdString.toLong();
    std::shared_ptr<Travel> travel = travelAgency->findTravel(travelId);

    int selectedRow = ui->travelTable->row(item);

    std::shared_ptr<Booking> selectedBooking = travel->getTravelBookings()[selectedRow];

    //set id text
    ui->bookingIDEdit->setText(QString::fromStdString(selectedBooking->getId()));

    //set date
    QDate startDate = QDate::fromString(QString::fromStdString(selectedBooking->getFromDate()), "yyyyMMdd");
    ui->startDateEdit->setDate(startDate);
    QDate endDate = QDate::fromString(QString::fromStdString(selectedBooking->getToDate()), "yyyyMMdd");
    ui->endDateEdit->setDate(endDate);

    //set price
    ui->priceSpinBox->setValue(selectedBooking->getPrice());

    if (std::dynamic_pointer_cast<FlightBooking>(selectedBooking)) {
        //Pop the tab Flight Booking up
        ui->bookingTabs->setCurrentWidget(ui->FlightBooking);
        //clear others details
        clearBookingDetails();
        //casting selectedBooking to FlightBooking
        std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(selectedBooking);
        ui->airlineEdit->setText(QString::fromStdString(flightBooking->getAirline()));
        std::shared_ptr<Airport> departureAirport = travelAgency->findAirport(flightBooking->getFromDestination());
        ui->fromEdit->setText(QString::fromStdString(departureAirport->getName()));
        ui->fromEdit->setReadOnly(true);
        ui->fromCodeEdit->setText(QString::fromStdString(flightBooking->getFromDestination()));
        std::shared_ptr<Airport> arrivalAirport = travelAgency->findAirport(flightBooking->getToDestination());
        ui->toDestEdit->setText(QString::fromStdString(arrivalAirport->getName()));
        ui->toDestEdit->setReadOnly(true);
        ui->toCodeEdit->setText(QString::fromStdString(flightBooking->getToDestination()));
        ui->bookingClassEdit->setText(QString::fromStdString(flightBooking->getBookingClass()));

    }
    else if (std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking)) {
        //Pop the tab Car Rental up
        ui->bookingTabs->setCurrentWidget(ui->CarRental);
        //clear others details
        clearBookingDetails();

        //casting selectedBooking to RentalCarReservation
        std::shared_ptr<RentalCarReservation> rentalCarReservation = std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking);
        ui->pickupLocEdit->setText(QString::fromStdString(rentalCarReservation->getPickupLocation()));
        ui->returnLocEdit->setText(QString::fromStdString(rentalCarReservation->getReturnLocation()));
        ui->companyEdit->setText(QString::fromStdString(rentalCarReservation->getCompany()));
        ui->vehicleClassEdit->setText(QString::fromStdString(rentalCarReservation->getVehicleClass()));

    }
    else if (std::dynamic_pointer_cast<HotelBooking>(selectedBooking)) {
        //Pop the tab HotelBooking up
        ui->bookingTabs->setCurrentWidget(ui->HotelBooking);
        //clear others details
        clearBookingDetails();

        //casting selectedBooking to HotelBooking
        std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(selectedBooking);
        ui->hotelEdit->setText(QString::fromStdString(hotelBooking->getHotel()));
        ui->townEdit->setText(QString::fromStdString(hotelBooking->getTown()));
        ui->roomTypeEdit->setText(QString::fromStdString(hotelBooking->getRoomType()));

    }
    ui->bookingDetailsGroupBox->setVisible(true);
    ui->bookingIDEdit->setReadOnly(true);
}

void TravelAgencyUI::clearBookingDetails()
{
    ui->airlineEdit->clear();
    ui->fromEdit->clear();
    ui->toDestEdit->clear();
    ui->bookingClassEdit->clear();

    ui->pickupLocEdit->clear();
    ui->returnLocEdit->clear();
    ui->companyEdit->clear();

    ui->hotelEdit->clear();
    ui->townEdit->clear();
    ui->roomTypeEdit->clear();
}


void TravelAgencyUI::on_saveButton_clicked()
{
    // Update the selected booking with the edited values
    updateSelectedBooking();

    // Disable the buttons
    disableButtons();

    // Update the detail view
    updateDetailView();
}


void TravelAgencyUI::on_cancelButton_clicked()
{
    // Disable the buttons
    disableButtons();

    // Update the detail view
    updateDetailView();
}

// Function to enable the buttons
void TravelAgencyUI::enableButtons()
{
    // Enable the save and cancel buttons
    ui->saveButton->setEnabled(true);
    ui->cancelButton->setEnabled(true);
}

// Function to disable the buttons
void TravelAgencyUI::disableButtons()
{
    // Disable the save and cancel buttons
    ui->saveButton->setEnabled(false);
    ui->cancelButton->setEnabled(false);
}

void TravelAgencyUI::updateSelectedBooking(){
    //retrieve the customer id from the customerIDEdit
    QString bookingId = ui->bookingIDEdit->text();
    std::shared_ptr<Booking> selectedBooking = travelAgency->findBooking(bookingId.toStdString());

    //convert the from Date to std::string
    QDate fromDate = ui->startDateEdit->date();
    QString fromDateString = fromDate.toString("yyyyMMdd");
    std::string fromDateStdString = fromDateString.toStdString();

    // set the changes to the booking
    selectedBooking->setFromDate(fromDateStdString);

    QDate toDate = ui->endDateEdit->date();
    QString toDateString = toDate.toString("yyyyMMdd");
    std::string toDateStdString = toDateString.toStdString();

    selectedBooking->setToDate(toDateStdString);

    double price = ui->priceSpinBox->value();
    selectedBooking->setPrice(price);

    if (std::dynamic_pointer_cast<FlightBooking>(selectedBooking)) {
        //casting selectedBooking to FlightBooking
        std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(selectedBooking);
        flightBooking->setAirline(ui->airlineEdit->text().toStdString());
        //check if the iata code exists
        if(travelAgency->findAirport(ui->fromCodeEdit->text().toStdString()) && travelAgency->findAirport(ui->toCodeEdit->text().toStdString())){
            flightBooking->setFromDestination(ui->fromCodeEdit->text().toStdString());
            flightBooking->setToDestination(ui->toCodeEdit->text().toStdString());
        }
        else {QMessageBox msgBox;
            msgBox.setWindowTitle("Error");
            msgBox.setText("Ungültiger Iata-Code");
            msgBox.setStyleSheet("QLabel{ color : red; }");
            msgBox.exec();}

        QString bookingClass = ui->bookingClassEdit->text();
        if(bookingClass == "Economy class"){
            flightBooking->setBookingClass('Y');
        }
        else if(bookingClass == "Premium Economy class"){
            flightBooking->setBookingClass('W');
        }
        else if(bookingClass == "Business class"){
            flightBooking->setBookingClass('J');
        }
        else if(bookingClass == "First class"){
            flightBooking->setBookingClass('F');
        }
        else QMessageBox::critical(this, "Error", "Unknown Booking Class type!");
    }
    else if (std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking)) {
        //casting selectedBooking to RentalCarReservation
        std::shared_ptr<RentalCarReservation> rentalCarReservation = std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking);
        rentalCarReservation->setPickupLocation(ui->pickupLocEdit->text().toStdString());
        rentalCarReservation->setReturnLocation(ui->returnLocEdit->text().toStdString());
        rentalCarReservation->setCompany(ui->companyEdit->text().toStdString());
        rentalCarReservation->setVehicleClass(ui->vehicleClassEdit->text().toStdString());
    }
    else if (std::dynamic_pointer_cast<HotelBooking>(selectedBooking)) {
        //casting selectedBooking to HotelBooking
        std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(selectedBooking);
        hotelBooking->setHotel(ui->hotelEdit->text().toStdString());
        hotelBooking->setTown(ui->townEdit->text().toStdString());

        QString roomType = ui->roomTypeEdit->text();
        if(roomType == "Einzelzimmer"){
            hotelBooking->setRoomType("EZ");
        }
        else if(roomType == "Doppelzimmer"){
            hotelBooking->setRoomType("DZ");
        }
        else if(roomType == "Apartment"){
            hotelBooking->setRoomType("AP");
        }
        else if(roomType == "Suite"){
            hotelBooking->setRoomType("SU");
        }
        else QMessageBox::critical(this, "Error", "Unknown Hotel Room type!");
    }
}

void TravelAgencyUI::updateDetailView(){
    //retrieve the customer id from the customerIDEdit
    QString bookingId = ui->bookingIDEdit->text();
    std::shared_ptr<Booking> selectedBooking = travelAgency->findBooking(bookingId.toStdString());

    //set id text
    ui->bookingIDEdit->setText(QString::fromStdString(selectedBooking->getId()));

    //set date
    QDate startDate = QDate::fromString(QString::fromStdString(selectedBooking->getFromDate()), "yyyyMMdd");
    ui->startDateEdit->setDate(startDate);
    QDate endDate = QDate::fromString(QString::fromStdString(selectedBooking->getToDate()), "yyyyMMdd");
    ui->endDateEdit->setDate(endDate);

    //set price
    ui->priceSpinBox->setValue(selectedBooking->getPrice());

    if (std::dynamic_pointer_cast<FlightBooking>(selectedBooking)) {
        //Pop the tab Flight Booking up
        ui->bookingTabs->setCurrentWidget(ui->FlightBooking);
        //clear others details
        clearBookingDetails();
        //casting selectedBooking to FlightBooking
        std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(selectedBooking);
        ui->airlineEdit->setText(QString::fromStdString(flightBooking->getAirline()));
        ui->fromCodeEdit->setText(QString::fromStdString(flightBooking->getFromDestination()));
        std::shared_ptr<Airport> departureAirport = travelAgency->findAirport(flightBooking->getFromDestination());
        ui->fromEdit->setText(QString::fromStdString(departureAirport->getName()));
        std::shared_ptr<Airport> arrivalAirport = travelAgency->findAirport(flightBooking->getToDestination());
        ui->toDestEdit->setText(QString::fromStdString(arrivalAirport->getName()));
        ui->toCodeEdit->setText(QString::fromStdString(flightBooking->getToDestination()));
        ui->bookingClassEdit->setText(QString::fromStdString(flightBooking->getBookingClass()));

    }
    else if (std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking)) {
        //Pop the tab Car Rental up
        ui->bookingTabs->setCurrentWidget(ui->CarRental);
        //clear others details
        clearBookingDetails();

        //casting selectedBooking to RentalCarReservation
        std::shared_ptr<RentalCarReservation> rentalCarReservation = std::dynamic_pointer_cast<RentalCarReservation>(selectedBooking);
        ui->pickupLocEdit->setText(QString::fromStdString(rentalCarReservation->getPickupLocation()));
        ui->returnLocEdit->setText(QString::fromStdString(rentalCarReservation->getReturnLocation()));
        ui->companyEdit->setText(QString::fromStdString(rentalCarReservation->getCompany()));
        ui->vehicleClassEdit->setText(QString::fromStdString(rentalCarReservation->getVehicleClass()));

    }
    else if (std::dynamic_pointer_cast<HotelBooking>(selectedBooking)) {
        //Pop the tab HotelBooking up
        ui->bookingTabs->setCurrentWidget(ui->HotelBooking);
        //clear others details
        clearBookingDetails();

        //casting selectedBooking to HotelBooking
        std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(selectedBooking);
        ui->hotelEdit->setText(QString::fromStdString(hotelBooking->getHotel()));
        ui->townEdit->setText(QString::fromStdString(hotelBooking->getTown()));
        ui->roomTypeEdit->setText(QString::fromStdString(hotelBooking->getRoomType()));

    }

}


void TravelAgencyUI::on_showOnMapButton_clicked()
{
    //retreive travel id from travel id edit
    std::shared_ptr<Travel> selectedTravel = travelAgency->findTravel(ui->travelIDEdit->text().toLong());
    travelAgency->displayBookingsOnMap(selectedTravel);
}

void TravelAgencyUI::on_addNewCustomerButton_clicked()
{
    // Create an instance of the CustomerSearchDialog
    AddCustomer addCustomer(this);

    // Show the dialog as a modal dialog
    int result = addCustomer.exec();

    if (result == QDialog::Accepted) {
        // Handle the accepted result
        QString customerName = addCustomer.getCustomerName();
        // Add a new customer and retrieve the assigned ID
        long customerId = travelAgency->addNewCustomer(customerName);

        QMessageBox msgBox;
        msgBox.setWindowTitle("Erfolgreich!");
        msgBox.setText("ein neue Kunde mit ID :" + QString::number(customerId) + " wurde hinzugefügt.");
        msgBox.exec();

    } else {
        // Handle the rejected result or cancel action
        // ...
    }
}


void TravelAgencyUI::on_addBookingButton_clicked()
{
    // Create an instance of the AddBooking dialog
    AddBooking addBookingDialog(this);
    connect(&addBookingDialog, SIGNAL(bookingCreated(std::shared_ptr<Booking>, bool)), this, SLOT(handleBookingCreated(std::shared_ptr<Booking>, bool)));
    // Show the dialog as a modal dialog
    addBookingDialog.exec();
}

void TravelAgencyUI::handleBookingCreated(std::shared_ptr<Booking> booking, bool addToNewTravel)
{
    if (addToNewTravel)
    {
        booking->setTravelId(ui->customerIDEdit->text().toLong());
        travelAgency->addNewBooking(booking);
        travelAgency->addBookingtoNewTravel(ui->customerIDEdit->text().toLong(), booking);
        updateTravelList();
    }
    else
    {
        if (!ui->customerTravelTable->selectedItems().isEmpty())
        {
            // Get the selected travel ID from the travelCustomerTable
            long selectedTravelId = ui->customerTravelTable->selectedItems().first()->text().toLong();
            std::shared_ptr<Travel> selectedTravel = travelAgency->findTravel(selectedTravelId);;
            if (selectedTravel)
            {
                selectedTravel->addBooking(booking);
                updateBookingList(selectedTravel);
                updateTravelList();
            }
            else
            {
                QMessageBox::critical(this, "Error", "Selected travel not found.");
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "No travel selected.");
        }
    }
}


void TravelAgencyUI::updateTravelList()
{
    std::shared_ptr<Customer> customer = travelAgency->findCustomer(ui->customerIDEdit->text().toLong());
    if (customer != nullptr) {
        // Customer found, display the details

        //set the ID and Name
        long customerId = customer->getId();
        QString customerIdString = QString::number(customerId);
        ui->customerIDEdit->setText(customerIdString);
        QString customerName = QString::fromStdString(customer->getName());
        ui->customerNameEdit->setText(customerName);


        // Clear existing table contents
        ui->customerTravelTable->clearContents();
        ui->customerTravelTable->setRowCount(0);

        //get the travelList
        const std::vector<std::shared_ptr<Travel>>& travelList = customer->getTravelList();


        // Set the number of rows in the table
        int rowCount = travelList.size();
        ui->customerTravelTable->setRowCount(rowCount);

        //filling the table
        for (int row = 0; row < rowCount; row++) {
            std::shared_ptr<Travel> travel = travelList[row];

            QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(std::to_string(travel->getId())));
            std::pair<std::string, std::string> travelDates = travel->calculateTravelDates();

            // Convert earliest start date
            QDateTime earliestStartDateTime = QDateTime::fromString(QString::fromStdString(travelDates.first), "yyyyMMdd");
            QString formattedEarliestStartDate = QLocale("de_DE").toString(earliestStartDateTime, "dddd, d. MMMM yyyy");

            // Convert latest end date
            QDateTime latestEndDateTime = QDateTime::fromString(QString::fromStdString(travelDates.second), "yyyyMMdd");
            QString formattedLatestEndDate = QLocale("de_DE").toString(latestEndDateTime, "dddd, d. MMMM yyyy");

            QTableWidgetItem* earliestStartDateItem = new QTableWidgetItem(formattedEarliestStartDate);
            QTableWidgetItem* latestEndDateItem = new QTableWidgetItem(formattedLatestEndDate);

            ui->customerTravelTable->setItem(row, 0, idItem);
            ui->customerTravelTable->setItem(row, 1, earliestStartDateItem);
            ui->customerTravelTable->setItem(row, 2, latestEndDateItem);
        }

        //to make the table not editable
        ui->customerTravelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->customerIDEdit->setReadOnly(true);
        ui->customerNameEdit->setReadOnly(true);


        // Show the QTableWidget for travel history
        ui->cutomerGroupBox->setVisible(true);

    } else {
        // Customer not found, display an error message
        QMessageBox::critical(this, "Error", "Customer not found!");
        // hide the QTableWidget for travel history
        ui->cutomerGroupBox->setVisible(false);
    }
}

void TravelAgencyUI::updateBookingList(std::shared_ptr<Travel> selectedTravel){
    QIcon carIcon("Car.png");
    QIcon planeIcon("plane.png");
    QIcon hotelIcon("hotel.png");

    //set ID
    long travelId = selectedTravel->getId();
    QString travelIdString = QString::number(travelId);
    ui->travelIDEdit->setText(travelIdString);

    //get the travelBookings
    const std::vector<std::shared_ptr<Booking>> & travelBookings = selectedTravel->getTravelBookings();


    // Set the number of rows in the table
    int rowCount = travelBookings.size();
    ui->travelTable->setRowCount(rowCount);

    //filling the table
    for (int row = 0; row < rowCount; row++) {
        std::shared_ptr<Booking> booking = travelBookings[row];

        // Convert earliest start date
        QDateTime StartDateTime = QDateTime::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
        QString formattedStartDate = QLocale("de_DE").toString(StartDateTime, "dddd, d. MMMM yyyy");

        // Convert latest end date
        QDateTime EndDateTime = QDateTime::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");
        QString formattedEndDate = QLocale("de_DE").toString(EndDateTime, "dddd, d. MMMM yyyy");

        QTableWidgetItem* startDateItem = new QTableWidgetItem(formattedStartDate);
        QTableWidgetItem* endDateItem = new QTableWidgetItem(formattedEndDate);

        QTableWidgetItem* travelPreis = new QTableWidgetItem(QString::number(booking->getPrice()));

        //set the icons
        if (std::dynamic_pointer_cast<FlightBooking>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(planeIcon);
            ui->travelTable->setItem(row, 0, icon);
        }
        else if (std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(carIcon);
            ui->travelTable->setItem(row, 0, icon);
        }
        else if (std::dynamic_pointer_cast<HotelBooking>(booking)) {
            QTableWidgetItem* icon = new QTableWidgetItem;
            icon->setIcon(hotelIcon);
            ui->travelTable->setItem(row, 0, icon);
        }

        ui->travelTable->setItem(row, 1, startDateItem);
        ui->travelTable->setItem(row, 2, endDateItem);
        ui->travelTable->setItem(row, 3, travelPreis);
    }

    //to make the table not editable
    ui->travelTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->travelIDEdit->setReadOnly(true);


    // Show the QTableWidget for travel history
    ui->travelGroupBox->setVisible(true);
}

void TravelAgencyUI::on_actionJSON_triggered(){
    // Create an instance of the AddBooking dialog
    SaveToJson saveToJsonDialog(this);
    connect(&saveToJsonDialog, SIGNAL(saveToJson(std::string)), this, SLOT(handleSaveToJson(std::string)));
    // Show the dialog as a modal dialog
    saveToJsonDialog.exec();
}

void TravelAgencyUI::handleSaveToJson(std::string criterion){
    travelAgency->sortBookings(criterion);
    travelAgency->saveToJSON("newBookingData.json");
}

void TravelAgencyUI::on_checkTestButton_clicked()
{
    TestResult testResult(travelAgency, this);
    testResult.exec();
}


void TravelAgencyUI::on_ABCButton_clicked()
{
    travelAgency->abcAnalyse();
    ABCDialog abcDialog(travelAgency, this);
    abcDialog.exec();
}

