#include "travel.h"
#include "algorithmen.cpp"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"

Travel::Travel(long id, long customerId) : id(id), customerId(customerId)
{

}

void Travel::addBooking(std::shared_ptr<Booking> booking){
    travelBookings.push_back(booking);
}

long Travel::getId(){
    return id;
}

long Travel::getCustomerId(){
    return customerId;
}

std::vector <std::shared_ptr<Booking>> Travel::getTravelBookings(){
    return travelBookings;
}

std::pair<std::string, std::string> Travel::calculateTravelDates() const
{
    std::string earliestStartDate;
    std::string latestEndDate;

    for (std::shared_ptr<Booking> booking : travelBookings) {
        std::string startDate = booking->getFromDate();
        std::string endDate = booking->getToDate();

        if (earliestStartDate.empty() || startDate < earliestStartDate) {
            earliestStartDate = startDate;
        }

        if (latestEndDate.empty() || endDate > latestEndDate) {
            latestEndDate = endDate;
        }
    }

    return std::make_pair(earliestStartDate, latestEndDate);
}

void Travel::createGraph() {
    //delete old graph
    // Reset all the shared pointers in the vertices, this will release the Booking objects
    for (int i = 0; i < travelGraph.getNumVertices(); ++i) {
        travelGraph.getVertexValue(i).reset(); // This will reset the shared pointer and deallocate the Booking object if it's the last reference
    }

    // Add a dummy vertex as the first booking in the graph
    travelGraph.insertVertex(-1, nullptr); // Assuming -1 is not a valid booking ID and nullptr is not a valid booking object
    // Clear the graph using the deleteDigraph function (doesnt work)
    //travelGraph.deleteDigraph();

    // Add vertices (bookings) to the graph
    int index = 0;
    for (auto booking : travelBookings) {
        travelGraph.insertVertex(index, booking);
        index++;
    }

    // Connect bookings based on predecessors
    int numBookings = travelBookings.size();
    for (int i = 0; i < numBookings; ++i) {
        for (int j = 0; j < numBookings; ++j) {
            auto booking1 = travelBookings[i];
            auto booking2 = travelBookings[j];
            if ((booking1->getPredecessor1() == booking2->getId() || booking1->getPredecessor2() == booking2->getId())){
                travelGraph.insertArc(j,i);
            }
        }
    }
}

// Helper function to print booking details
void printBookingDetails(std::shared_ptr<Booking> booking) {
    std::cout << "Booking ID: " << booking->getId() << ", From: " << booking->getFromDate() << ", To: " << booking->getToDate() << std::endl;
}

// Helper function to perform topological sorting
//std::vector<int> topologicalSort(Digraph<std::shared_ptr<Booking>, 100> &graph) {
//    std::vector<int> sortedVertices;
//    std::vector<bool> visited(graph.getNumVertices(), false);

//    std::function<void(int)> dfsTopological = [&](int v) {
//        visited[v] = true;
//        int w = graph.firstArc(v);
//        while (w != -1) {
//            if (!visited[w]) {
//                dfsTopological(w);
//            }
//            w = graph.nextArc(w, v);
//        }
//        sortedVertices.push_back(v);
//    };

//    int v = graph.firstVertex();
//    while (v != -1) {
//        if (!visited[v]) {
//            dfsTopological(v);
//        }
//        v = graph.nextVertex(v);
//    }

//    std::reverse(sortedVertices.begin(), sortedVertices.end());
//    return sortedVertices;
//}

void Travel::sortGraph(std::vector<VertexData> &data)
{
    DepthFirstSearch(travelGraph);

    VertexData vertexData;
    for (int i = 0; i < travelBookings.size(); i++){

        vertexData.booking = travelGraph.getVertexValue(i);
        vertexData.endtime = travelGraph.getEnd(i);

        data.push_back(vertexData);
    }

    for (unsigned int step = 0; step < data.size() - 1; step++) {
        int max = step;
        for (unsigned int i = step + 1; i < data.size(); i++) {

            if(data[i].endtime > data[max].endtime)
                max = i;
        }
        VertexData temp = data[max];
        data[max] = data[step];
        data[step] = temp;
    }
}

bool Travel::checkRoundtrip()
{
    bool isRoundtrip = false;

    std::vector<VertexData> data;

    sortGraph(data);

    int i = 0;

    while (std::dynamic_pointer_cast<FlightBooking>(data[i].booking) == nullptr) {
        i++;
    }

    std::shared_ptr<FlightBooking> firstFlight = std::dynamic_pointer_cast<FlightBooking>(data[i].booking);


    i = data.size() - 1;

    while (std::dynamic_pointer_cast<FlightBooking>(data[i].booking) == nullptr) {
        i--;
    }

    std::shared_ptr<FlightBooking> lastFlight = std::dynamic_pointer_cast<FlightBooking>(data[i].booking);

    if (firstFlight->getFromDestination() == lastFlight->getToDestination())
        isRoundtrip = true;


    return isRoundtrip;
}

// Prüfung auf gleichen Abflug- und Ankunftsort
//bool Travel::checkRoundtrip() {
//    // Step 1: Perform topological sorting
//    std::vector<int> sortedVertices = topologicalSort(travelGraph);

//    // Find the first flight booking to start the DFS
//    int numBookings = travelBookings.size();
//    int firstFlightBookingIndex = -1;
//    for (int vertex : sortedVertices) {
//        if (std::dynamic_pointer_cast<FlightBooking>(travelBookings[vertex])) {
//            firstFlightBookingIndex = vertex;
//            break;
//        }
//    }

//    if (firstFlightBookingIndex == -1) {
//        // No flight bookings, cannot form a roundtrip
//        return false;
//    }

//    Digraph<std::shared_ptr<Booking>, 100> tempGraph = travelGraph;
//    std::vector<bool> visited(numBookings, false);
//    std::vector<int> stack;

//    std::function<void(int)> dfs = [&](int v) {
//        stack.push_back(v);
//        visited[v] = true;

//        int a = tempGraph.firstArc(v);
//        while (a != -1) {
//            int w = tempGraph.getEnd(a);
//            if (!visited[w]) {
//                dfs(w);
//            }
//            a = tempGraph.nextArc(v, a); // Use v as the first argument here
//        }
//    };

//    // Starting DFS from the first flight booking
//    dfs(firstFlightBookingIndex);

//    // Check if the start airport of the first flight is the same as the destination airport of the last flight
//    std::shared_ptr<FlightBooking> firstBooking = std::dynamic_pointer_cast<FlightBooking>(travelBookings[stack.front()]);
//    std::shared_ptr<FlightBooking> lastBooking = std::dynamic_pointer_cast<FlightBooking>(travelBookings[stack.back()]);

//    std::string startAirportFirst = firstBooking->getFromDestination();
//    std::string destinationAirportLast = lastBooking->getToDestination();

//    return startAirportFirst == destinationAirportLast;
//}

// Adjust the printVertex function to work with shared_ptr<Booking>
void printVertex(Digraph<std::shared_ptr<Booking>, 100> &g, int n) {
    printBookingDetails(g.getVertexValue(n));
}

bool Travel::checkEnoughHotels()
{
    bool enoughHotels = true;

    std::vector<VertexData> data;

    sortGraph(data);

    for (unsigned int i = 0; i < data.size() - 1; i++) {
        if (std::dynamic_pointer_cast<RentalCarReservation>(data[i].booking) == nullptr) {

            for (unsigned int j = i +1; j < data.size(); j++) {
                if (std::dynamic_pointer_cast<RentalCarReservation>(data[j].booking) == nullptr) {
                    QDate toDate = QDate::fromString(QString::fromStdString(data[i].booking->getToDate()), "yyyyMMdd");
                    QDate fromDate = QDate::fromString(QString::fromStdString(data[j].booking->getFromDate()), "yyyyMMdd");
                    if(toDate < fromDate) {
                        enoughHotels = false;
                    }
                    break;
                }
            }
        }
    }
    return enoughHotels;
}

// Function to check if there are enough hotels for the travel
//bool Travel::checkEnoughHotels() {
//    int numBookings = travelBookings.size();

//    // Check if there are no bookings (empty graph)
//    if (numBookings == 0) {
//        return false;
//    }

//    // Step 1: Perform topological sorting
//    std::vector<int> sortedVertices = topologicalSort(travelGraph);

//    // Step 2: Ignore car rental bookings (ArcType::CAR_RENTAL)
//    std::vector<bool> isCarRental(numBookings, false);
//    for (int v : sortedVertices) {
//        std::shared_ptr<Booking> booking = travelBookings[v];
//        if (std::shared_ptr<RentalCarReservation> carBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
//            isCarRental[v] = true;
//        }
//    }

//    // Step 3: Check for continuous dates of hotel and flight bookings
//    QDate currentDate;
//    for (int v : sortedVertices) {
//        if (!isCarRental[v]) {
//            std::shared_ptr<Booking> booking = travelBookings[v];
//            QDate fromDate = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
//            QDate toDate = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");
//            if (fromDate > currentDate) {
//                // There is a gap between current booking and the previous one
//                return false;
//            }
//            currentDate = std::max(currentDate, toDate);
//        }
//    }

//    return true;
//}

bool Travel::checkNoUselessHotels()
{
    bool noUselessHotel = true;

    std::vector<VertexData> data;

    sortGraph(data);

    for (unsigned int i = 0; i < data.size() - 1; i++) {
        if (std::dynamic_pointer_cast<RentalCarReservation>(data[i].booking) == nullptr) {

            for (unsigned int j = i +1; j < data.size(); j++) {
                if (std::dynamic_pointer_cast<RentalCarReservation>(data[j].booking) == nullptr) {
                    QDate toDate = QDate::fromString(QString::fromStdString(data[i].booking->getToDate()), "yyyyMMdd");
                    QDate fromDate = QDate::fromString(QString::fromStdString(data[j].booking->getFromDate()), "yyyyMMdd");
                    if(toDate > fromDate) {
                        noUselessHotel = false;
                    }
                    break;
                }
            }
        }
    }

    return noUselessHotel;
}

// Function to check for overlaps between hotel bookings and other bookings
//bool Travel::checkNoUselessHotels() {
//    int numBookings = travelBookings.size();

//    // Check if there are no bookings (empty graph)
//    if (numBookings == 0) {
//        return false;
//    }

//    // Step 1: Perform topological sorting
//    std::vector<int> sortedVertices = topologicalSort(travelGraph);

//    // Step 2: Ignore car rental bookings (ArcType::CAR_RENTAL)
//    std::vector<bool> isCarRental(numBookings, false);
//    for (int v : sortedVertices) {
//        std::shared_ptr<Booking> booking = travelBookings[v];
//        if (std::shared_ptr<RentalCarReservation> carBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
//            isCarRental[v] = true;
//        }
//    }

//    // Step 3: Check for overlaps between hotel bookings and other bookings
//    QDate currentDate;
//    for (int v : sortedVertices) {
//        if (!isCarRental[v]) {
//            std::shared_ptr<Booking> booking = travelBookings[v];
//            QDate fromDate = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
//            QDate toDate = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");

//            // Check for overlap with hotel bookings only
//            if (std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
//                if (fromDate < currentDate) {
//                    // There is an overlap between hotel bookings and other bookings
//                    return false;
//                }
//            }
//            currentDate = std::max(currentDate, toDate);
//        }
//    }

//    return true; // No overlaps found, all hotels are used effectively
//}

bool Travel::checkNoUselessRentalCars()
{
    bool noUselessRentalCar = true;

    std::vector<VertexData> data;
    sortGraph(data);

    for (unsigned int i = 0; i < data.size(); i++) {
        if (std::dynamic_pointer_cast<HotelBooking>(data[i].booking) == nullptr) {
            QDate toDate_i = QDate::fromString(QString::fromStdString(data[i].booking->getToDate()), "yyyyMMdd");

            for (unsigned int j = i + 1; j < data.size(); j++) {
                if (std::dynamic_pointer_cast<HotelBooking>(data[j].booking) == nullptr) {
                    QDate fromDate_j = QDate::fromString(QString::fromStdString(data[j].booking->getFromDate()), "yyyyMMdd");

                    if (toDate_i > fromDate_j) {
                        // There is an overlap between the rental car and flight bookings
                        noUselessRentalCar = false;
                        break; // No need to continue checking for this rental car booking
                    }
                }
            }

            if (!noUselessRentalCar)
                break; // No need to continue checking if there is already an overlap
        }
    }

    return noUselessRentalCar;
}

// Function to check for overlaps between rental car bookings and other bookings
//bool Travel::checkNoUselessRentalCars() {
//    int numBookings = travelBookings.size();

//    // Check if there are no bookings (empty graph)
//    if (numBookings == 0) {
//        return false;
//    }

//    // Step 1: Perform topological sorting
//    std::vector<int> sortedVertices = topologicalSort(travelGraph);

//    // Step 2: Ignore hotel bookings
//    std::vector<bool> isHotelBooking(numBookings, false);
//    for (int v : sortedVertices) {
//        std::shared_ptr<Booking> booking = travelBookings[v];
//        if (std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
//            isHotelBooking[v] = true;
//        }
//    }

//    // Step 3: Check for overlaps between rental car bookings and other bookings
//    QDate currentDate;
//    for (int v : sortedVertices) {
//        if (!isHotelBooking[v]) {
//            std::shared_ptr<Booking> booking = travelBookings[v];
//            QDate fromDate = QDate::fromString(QString::fromStdString(booking->getFromDate()), "yyyyMMdd");
//            QDate toDate = QDate::fromString(QString::fromStdString(booking->getToDate()), "yyyyMMdd");

//            // Check for overlap with rental car bookings only
//            if (std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
//                if (fromDate < currentDate) {
//                    // There is an overlap between rental car bookings and other bookings
//                    return false;
//                }
//            }
//            currentDate = std::max(currentDate, toDate);
//        }
//    }

//    return true; // No overlaps found, all rental cars are used effectively
//}

double Travel::getTotalTravelPrice()
{
    double totalTravelPrice = 0;

    for (unsigned int i = 0; i < travelBookings.size(); i++) {
        totalTravelPrice = totalTravelPrice + travelBookings[i]->getPrice();
    }
    return totalTravelPrice;
}
