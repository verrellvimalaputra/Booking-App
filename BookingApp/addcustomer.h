#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include <QDialog>

namespace Ui {
class AddCustomer;
}

class AddCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomer(QWidget *parent = nullptr);
    ~AddCustomer();
    QString getCustomerName();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddCustomer *ui;
};

#endif // ADDCUSTOMER_H
