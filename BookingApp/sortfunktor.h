#ifndef SORTFUNKTOR_H
#define SORTFUNKTOR_H

#include "booking.h"
#include <functional>

class SortFunktor
{
public:
    SortFunktor(const std::string& sortKey);

    bool operator()(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) const;

private:
    std::function<bool(const std::shared_ptr<Booking>&, const std::shared_ptr<Booking>&)> compareFunction;
};

#endif // SORTFUNKTOR_H
