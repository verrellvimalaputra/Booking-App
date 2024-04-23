/********************************************************************************
** Form generated from reading UI file 'addcustomer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMER_H
#define UI_ADDCUSTOMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddCustomer
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *customerNameEdit;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AddCustomer)
    {
        if (AddCustomer->objectName().isEmpty())
            AddCustomer->setObjectName("AddCustomer");
        AddCustomer->resize(367, 129);
        buttonBox = new QDialogButtonBox(AddCustomer);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        customerNameEdit = new QLineEdit(AddCustomer);
        customerNameEdit->setObjectName("customerNameEdit");
        customerNameEdit->setGeometry(QRect(80, 40, 261, 22));
        label = new QLabel(AddCustomer);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 171, 16));
        label_2 = new QLabel(AddCustomer);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 49, 16));

        retranslateUi(AddCustomer);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddCustomer, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddCustomer, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddCustomer);
    } // setupUi

    void retranslateUi(QDialog *AddCustomer)
    {
        AddCustomer->setWindowTitle(QCoreApplication::translate("AddCustomer", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddCustomer", "Neue Kunde hinzuf\303\274gen", nullptr));
        label_2->setText(QCoreApplication::translate("AddCustomer", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCustomer: public Ui_AddCustomer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMER_H
