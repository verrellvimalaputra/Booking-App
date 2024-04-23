#ifndef ABCDIALOG_H
#define ABCDIALOG_H
#include "travelagency.h"

#include <QDialog>

namespace Ui {
class ABCDialog;
}

class ABCDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ABCDialog(TravelAgency* pTravelAgency, QWidget *parent = nullptr);
    ~ABCDialog();

    void showABCAnalyse();

private:
    Ui::ABCDialog *ui;
    TravelAgency* travelagency;
};

#endif // ABCDIALOG_H
