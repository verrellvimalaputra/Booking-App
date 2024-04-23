#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include "travel.h"


class Customer
{
public:
    Customer(long, std::string);
    void addTravel(std::shared_ptr<Travel>);
    std::vector <std::shared_ptr<Travel>> getTravelList();
    long getId();
    std::string getName();

private:
    long id;
    std::string name;
    std::vector <std::shared_ptr<Travel>> travelList;
};

#endif // CUSTOMER_H
