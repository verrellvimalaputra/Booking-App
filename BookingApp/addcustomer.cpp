#include "addcustomer.h"
#include "ui_addcustomer.h"

AddCustomer::AddCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCustomer)
{
    ui->setupUi(this);

    // Connect the accepted and rejected signals from the button box to the appropriate slots
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddCustomer::on_buttonBox_accepted);
}

AddCustomer::~AddCustomer()
{
    delete ui;
}

void AddCustomer::on_buttonBox_accepted()
{
    // Emit the accepted signal when the OK button is clicked
    accept();
}

QString AddCustomer::getCustomerName(){
    return ui->customerNameEdit->text();
}
