#include "testresult.h"
#include "ui_testresult.h"

TestResult::TestResult(TravelAgency* travelAgency, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestResult),
    travelAgency(travelAgency)
{
    ui->setupUi(this);
    ui->examResultTable->clear();

    std::vector<std::shared_ptr<Travel>> travels = travelAgency->getTravels();
    ui->examResultTable->setRowCount(travels.size());

    QStringList headers;
    headers << "Travel" << "Fehlendes Hotel" << "Überflüssige Hotel" << "Überflüssiger Mietwagen" << "kein RoundTrip";
    ui->examResultTable->setHorizontalHeaderLabels(headers);
    ui->examResultTable->verticalHeader()->setVisible(false);

    QPixmap pm_no_round_trip("no_round_trip.png");
    QPixmap pm_missing_hotel("MissingHotel.png");
    QPixmap pm_needless_hotel("hotel.png");
    QPixmap pm_ok("correct.png");
    QPixmap pm_needless_car("Car.png");

    QIcon iconMissingHotel = QIcon(pm_missing_hotel);
    QIcon iconNeedlessHotel = QIcon(pm_needless_hotel);
    QIcon iconNoRoundtrip =  QIcon(pm_no_round_trip);
    QIcon iconNeedlessCar = QIcon(pm_needless_car);
    QIcon iconOk =  QIcon(pm_ok);

    for (std::size_t i=0; i < travels.size();i++){
        QTableWidgetItem* tableWidgetItem = new QTableWidgetItem(0);
        QTableWidgetItem* tableWidgetItem1 = new QTableWidgetItem(0);
        QTableWidgetItem* tableWidgetItem2 = new QTableWidgetItem(0);
        QTableWidgetItem* tableWidgetItem3 = new QTableWidgetItem(0);


        ui->examResultTable->setItem(i,0,new QTableWidgetItem(QString::number(travels.at(i)->getId())));
        travels.at(i)->createGraph();
        // Spalte 1: checkMissingHotel
        if (travels.at(i)->checkEnoughHotels())
            tableWidgetItem->setIcon(iconOk);
        else{
            tableWidgetItem->setIcon(iconMissingHotel);
        }
        tableWidgetItem->setTextAlignment(Qt::AlignCenter);
        ui->examResultTable->setItem(i,1,tableWidgetItem);

        // Spalte 2: checkNoNeedlessHotel
        if (travels.at(i)->checkNoUselessHotels())
            tableWidgetItem1->setIcon(iconOk);
        else{
            tableWidgetItem1->setIcon(iconNeedlessHotel);
        }
        tableWidgetItem1->setTextAlignment(Qt::AlignCenter);
        ui->examResultTable->setItem(i,2,tableWidgetItem1);

        // Spalte 3: checkNoNeedlessRentalCar
        if (travels.at(i)->checkNoUselessRentalCars()){
            tableWidgetItem2->setIcon(iconOk);
        }
        else{
            tableWidgetItem2->setIcon(iconNeedlessCar);
        }
        tableWidgetItem2->setTextAlignment(Qt::AlignCenter);
        ui->examResultTable->setItem(i,3,tableWidgetItem2);

        // Spalte 4: checkRoundtrip
        if (travels.at(i)->checkRoundtrip()){
            tableWidgetItem3->setIcon(iconNoRoundtrip);
        }
        else{
            tableWidgetItem3->setIcon(iconOk);
            tableWidgetItem3->setText("Kunde: " + QString::number(travels.at(i)->getCustomerId()));
        }
        tableWidgetItem3->setTextAlignment(Qt::AlignCenter);
        ui->examResultTable->setItem(i,4,tableWidgetItem3);
    }
}

TestResult::~TestResult()
{
    delete ui;
}
