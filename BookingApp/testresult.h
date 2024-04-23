#ifndef TESTRESULT_H
#define TESTRESULT_H
#include "travelagency.h"
#include <QDialog>

namespace Ui {
class TestResult;
}

class TestResult : public QDialog
{
    Q_OBJECT

public:
    explicit TestResult(TravelAgency* travelAgency, QWidget *parent = nullptr);
    ~TestResult();

private:
    Ui::TestResult *ui;
    TravelAgency* travelAgency;
};

#endif // TESTRESULT_H
