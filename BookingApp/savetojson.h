#ifndef SAVETOJSON_H
#define SAVETOJSON_H
#include <string>
#include <QDialog>

namespace Ui {
class SaveToJson;
}

class SaveToJson : public QDialog
{
    Q_OBJECT

public:
    explicit SaveToJson(QWidget *parent = nullptr);
    ~SaveToJson();
signals:
    void saveToJson(std::string criterion);
private slots:
    void on_priceCheckBox_clicked();

    void on_fromDateCheckBox_clicked();

    void on_toDateCheckBox_clicked();

    void on_travelIdCheckBox_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SaveToJson *ui;
};

#endif // SAVETOJSON_H
