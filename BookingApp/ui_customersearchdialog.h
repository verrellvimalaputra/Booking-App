/********************************************************************************
** Form generated from reading UI file 'customersearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSEARCHDIALOG_H
#define UI_CUSTOMERSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CustomerSearchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *customerIdSpinBox;

    void setupUi(QDialog *CustomerSearchDialog)
    {
        if (CustomerSearchDialog->objectName().isEmpty())
            CustomerSearchDialog->setObjectName("CustomerSearchDialog");
        CustomerSearchDialog->resize(364, 159);
        buttonBox = new QDialogButtonBox(CustomerSearchDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CustomerSearchDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 101, 16));
        label_2 = new QLabel(CustomerSearchDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 40, 101, 16));
        customerIdSpinBox = new QSpinBox(CustomerSearchDialog);
        customerIdSpinBox->setObjectName("customerIdSpinBox");
        customerIdSpinBox->setGeometry(QRect(30, 70, 281, 22));

        retranslateUi(CustomerSearchDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CustomerSearchDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CustomerSearchDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CustomerSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerSearchDialog)
    {
        CustomerSearchDialog->setWindowTitle(QCoreApplication::translate("CustomerSearchDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CustomerSearchDialog", "Kund*innensuche", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerSearchDialog", "ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerSearchDialog: public Ui_CustomerSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSEARCHDIALOG_H
