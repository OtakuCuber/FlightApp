#ifndef ADDANEWFLIGHT_H
#define ADDANEWFLIGHT_H

#include <QDialog>

namespace Ui {
class AddANewFlight;
}

class AddANewFlight : public QDialog
{
    Q_OBJECT

public:
    explicit AddANewFlight(QWidget *parent = nullptr);
    ~AddANewFlight();

private:
    Ui::AddANewFlight *ui;
};

#endif // ADDANEWFLIGHT_H
