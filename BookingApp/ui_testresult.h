/********************************************************************************
** Form generated from reading UI file 'testresult.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTRESULT_H
#define UI_TESTRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TestResult
{
public:
    QTableWidget *examResultTable;

    void setupUi(QDialog *TestResult)
    {
        if (TestResult->objectName().isEmpty())
            TestResult->setObjectName("TestResult");
        TestResult->resize(864, 718);
        examResultTable = new QTableWidget(TestResult);
        if (examResultTable->columnCount() < 5)
            examResultTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        examResultTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        examResultTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        examResultTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        examResultTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        examResultTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        examResultTable->setObjectName("examResultTable");
        examResultTable->setGeometry(QRect(20, 20, 841, 691));
        examResultTable->horizontalHeader()->setCascadingSectionResizes(false);
        examResultTable->horizontalHeader()->setMinimumSectionSize(80);
        examResultTable->horizontalHeader()->setDefaultSectionSize(167);
        examResultTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        examResultTable->horizontalHeader()->setStretchLastSection(false);

        retranslateUi(TestResult);

        QMetaObject::connectSlotsByName(TestResult);
    } // setupUi

    void retranslateUi(QDialog *TestResult)
    {
        TestResult->setWindowTitle(QCoreApplication::translate("TestResult", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = examResultTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TestResult", "Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = examResultTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TestResult", "Fehlendes Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = examResultTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TestResult", "\303\234berfl\303\274ssiges Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = examResultTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TestResult", "\303\234berfl\303\274ssiger Mietwagen", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = examResultTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TestResult", "Kein Roundtrip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestResult: public Ui_TestResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTRESULT_H
