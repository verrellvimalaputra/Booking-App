#include "travelagencyui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create an instance of TravelAgency
    TravelAgency travelAgency;

    // Create an instance of TravelAgencyUI and pass the TravelAgency object to its constructor
    TravelAgencyUI travelAgencyUI(&travelAgency);

    // Show the main window
    travelAgencyUI.show();

    // Start the application event loop
    return app.exec();
}
