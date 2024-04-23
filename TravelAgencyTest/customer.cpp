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
