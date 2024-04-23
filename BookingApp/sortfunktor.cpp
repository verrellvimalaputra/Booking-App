#include "sortfunktor.h"

SortFunktor::SortFunktor(const std::string& sortKey)
{
    if (sortKey == "price")
    {
        compareFunction = [](const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) {
            return booking1->getPrice() < booking2->getPrice();
        };
    }
    else if (sortKey == "fromDate")
    {
        compareFunction = [](const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) {
            QDate fromDate1 = QDate::fromString(QString::fromStdString(booking1->getFromDate()), "yyyyMMdd");
            QDate fromDate2 = QDate::fromString(QString::fromStdString(booking2->getFromDate()), "yyyyMMdd");
            return fromDate1 < fromDate2;
        };
    }
    else if (sortKey == "toDate")
    {
        compareFunction = [](const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) {
            QDate toDate1 = QDate::fromString(QString::fromStdString(booking1->getToDate()), "yyyyMMdd");
            QDate toDate2 = QDate::fromString(QString::fromStdString(booking2->getToDate()), "yyyyMMdd");
            return toDate1 < toDate2;
        };
    }
    else if (sortKey == "travelId")
    {
        compareFunction = [](const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) {
            return booking1->getTravelId() < booking2->getTravelId();
        };
    }
    else
    {
        // Default sort key if an invalid value is provided
        compareFunction = [](const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) {
            return booking1->getPrice() < booking2->getPrice();
        };
    }
}

bool SortFunktor::operator()(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) const
{
    return compareFunction(booking1, booking2);
}
