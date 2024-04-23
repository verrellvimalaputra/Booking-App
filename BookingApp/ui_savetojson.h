/********************************************************************************
** Form generated from reading UI file 'savetojson.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVETOJSON_H
#define UI_SAVETOJSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SaveToJson
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *priceCheckBox;
    QCheckBox *fromDateCheckBox;
    QCheckBox *toDateCheckBox;
    QCheckBox *travelIdCheckBox;
    QLabel *label;

    void setupUi(QDialog *SaveToJson)
    {
        if (SaveToJson->objectName().isEmpty())
            SaveToJson->setObjectName("SaveToJson");
        SaveToJson->resize(359, 129);
        buttonBox = new QDialogButtonBox(SaveToJson);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        priceCheckBox = new QCheckBox(SaveToJson);
        priceCheckBox->setObjectName("priceCheckBox");
        priceCheckBox->setGeometry(QRect(20, 50, 76, 20));
        fromDateCheckBox = new QCheckBox(SaveToJson);
        fromDateCheckBox->setObjectName("fromDateCheckBox");
        fromDateCheckBox->setGeometry(QRect(100, 50, 76, 20));
        toDateCheckBox = new QCheckBox(SaveToJson);
        toDateCheckBox->setObjectName("toDateCheckBox");
        toDateCheckBox->setGeometry(QRect(200, 50, 76, 20));
        travelIdCheckBox = new QCheckBox(SaveToJson);
        travelIdCheckBox->setObjectName("travelIdCheckBox");
        travelIdCheckBox->setGeometry(QRect(280, 50, 76, 20));
        label = new QLabel(SaveToJson);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 281, 16));

        retranslateUi(SaveToJson);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SaveToJson, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SaveToJson, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SaveToJson);
    } // setupUi

    void retranslateUi(QDialog *SaveToJson)
    {
        SaveToJson->setWindowTitle(QCoreApplication::translate("SaveToJson", "Dialog", nullptr));
        priceCheckBox->setText(QCoreApplication::translate("SaveToJson", "Price", nullptr));
        fromDateCheckBox->setText(QCoreApplication::translate("SaveToJson", "from date", nullptr));
        toDateCheckBox->setText(QCoreApplication::translate("SaveToJson", "to date", nullptr));
        travelIdCheckBox->setText(QCoreApplication::translate("SaveToJson", "travel ID", nullptr));
        label->setText(QCoreApplication::translate("SaveToJson", "Choose the sort criterion to save the json file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveToJson: public Ui_SaveToJson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVETOJSON_H
