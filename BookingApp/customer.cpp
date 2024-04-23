#include "customer.h"

Customer::Customer(long id, std::string name) : id(id), name(name)
{

}

void Customer::addTravel(std::shared_ptr<Travel> travel){
    travelList.push_back(travel);
}

long Customer::getId(){
    return id;
}

std::string Customer::getName(){
    return name;
}

std::vector <std::shared_ptr<Travel>> Customer::getTravelList(){
    return travelList;
}

double Customer::getTotalCustomerPrice()
{
    double totalCustomerPrice = 0;

    for (unsigned int i = 0; i < travelList.size(); i++) {
        totalCustomerPrice = totalCustomerPrice + travelList[i]->getTotalTravelPrice();
    }
    return totalCustomerPrice;
}
