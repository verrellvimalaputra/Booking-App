#include "customersearchdialog.h"
#include <QVBoxLayout>
#include "ui_customersearchdialog.h"

CustomerSearchDialog::CustomerSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerSearchDialog)
{
    ui->setupUi(this);

    // Connect the accepted and rejected signals from the button box to the appropriate slots
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &CustomerSearchDialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &CustomerSearchDialog::on_buttonBox_rejected);
}

CustomerSearchDialog::~CustomerSearchDialog()
{
    delete ui;
}


void CustomerSearchDialog::on_buttonBox_accepted()
{
   // Emit the accepted signal when the OK button is clicked
   accept();
}

void CustomerSearchDialog::on_buttonBox_rejected()
{
    // Emit the rejected signal when the Cancel button is clicked
    reject();
}

long CustomerSearchDialog::getCustomerId()
{
    // Retrieve the customer ID from the spin box
    return ui->customerIdSpinBox->value();
}
