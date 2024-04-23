#include "savetojson.h"
#include "ui_savetojson.h"

SaveToJson::SaveToJson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveToJson)
{
    ui->setupUi(this);
}

SaveToJson::~SaveToJson()
{
    delete ui;
}

void SaveToJson::on_priceCheckBox_clicked()
{
    ui->fromDateCheckBox->setChecked(false);
    ui->toDateCheckBox->setChecked(false);
    ui->travelIdCheckBox->setChecked(false);
}


void SaveToJson::on_fromDateCheckBox_clicked()
{
    ui->priceCheckBox->setChecked(false);
    ui->toDateCheckBox->setChecked(false);
    ui->travelIdCheckBox->setChecked(false);
}


void SaveToJson::on_toDateCheckBox_clicked()
{
    ui->priceCheckBox->setChecked(false);
    ui->fromDateCheckBox->setChecked(false);
    ui->travelIdCheckBox->setChecked(false);
}


void SaveToJson::on_travelIdCheckBox_clicked()
{
    ui->priceCheckBox->setChecked(false);
    ui->fromDateCheckBox->setChecked(false);
    ui->toDateCheckBox->setChecked(false);
}


void SaveToJson::on_buttonBox_accepted()
{
    std::string criterion;
    if (ui->priceCheckBox->isChecked()){
        criterion = "price";
    }
    else if (ui->fromDateCheckBox->isChecked()){
        criterion = "fromDate";
    }
    else if(ui->toDateCheckBox->isChecked()){
        criterion = "toDate";
    }
    else if(ui->travelIdCheckBox->isChecked()){
        criterion = "travelId";
    }

    emit saveToJson(criterion);
}

