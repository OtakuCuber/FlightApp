#include "addanewflight.h"
#include "ui_addanewflight.h"
#include "adminhomepage.h"
#include "listofflights.h"
#include <iostream>
#include <QString>
#include <fstream>
#include <string>
#include<QListWidget>
using namespace std;
extern char departurecountry[20];
extern char destinationcountry[20];
extern char departuredate[20];
extern char arrivaldate[20];
extern char departuretime[20];
extern char arrivaltime[20];
extern char planenumber[20];
extern char travelcompany[20];
extern char duration[20];
extern char economy[20];
extern char business[20];
extern char adult[20];
extern char child[20];

extern int ifedit;
extern string choice_planeid;
//extern string choice_destcountry;
struct flights
{
    char depcountry[20];
    char destcountry[20];
    char depdate[20];
    char arrdate[20];
    char deptime[20];
    char arrtime[20];
    char planenum[20];
    char travcompany[20];
    char duration[20];
    char economy[20];
    char business[20];
    char adult[20];
    char child[20];
};
AddANewFlight::AddANewFlight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddANewFlight)
{
    ui->setupUi(this);
    if(ifedit==0)
    {
        flights x;
        ifstream infile;
        infile.open("C:\\FlightApp\\FlightApp\\flights.bin");
        while(infile.read((char*)&x,sizeof(x)))
        {
            if(choice_planeid==x.planenum)
            {
                ui->depcountry->setText(x.depcountry);
                ui->destcountry->setText(x.destcountry);
                ui->depdate->setText(x.depdate);
                ui->arrivaldate->setText(x.arrdate);
                ui->deptime->setText(x.deptime);
                ui->arrivaltime_2->setText(x.arrtime);
                ui->planenumber->setText(x.planenum);
                ui->travelcompany->setText(x.travcompany);
                ui->duration->setText(x.duration);
                ui->economy->setText(x.economy);
                ui->business->setText(x.business);
                ui->adult->setText(x.adult);
                ui->child->setText(x.child);
            }
        }
        infile.close();
    }
}

AddANewFlight::~AddANewFlight()
{
    delete ui;
}

void AddANewFlight::on_add_clicked()
{
    flights x;

        ofstream output;
        output.open("C:\\FlightApp\\FlightApp\\flights.bin",ios::app);
        strncpy(x.depcountry,ui->depcountry->toPlainText().toStdString().c_str(),sizeof(x.depcountry));
        strncpy(x.destcountry,ui->destcountry->toPlainText().toStdString().c_str(),sizeof(x.destcountry));
        strncpy(x.depdate,ui->depdate->toPlainText().toStdString().c_str(),sizeof(x.depdate));
        strncpy(x.arrdate,ui->arrivaldate->toPlainText().toStdString().c_str(),sizeof(x.arrdate));
        strncpy(x.deptime,ui->deptime->toPlainText().toStdString().c_str(),sizeof(x.deptime));
        strncpy(x.arrtime,ui->arrivaltime_2->toPlainText().toStdString().c_str(),sizeof(x.arrtime));
        strncpy(x.planenum,ui->planenumber->toPlainText().toStdString().c_str(),sizeof(x.planenum));
        strncpy(x.travcompany,ui->travelcompany->toPlainText().toStdString().c_str(),sizeof(x.travcompany));
        strncpy(x.duration,ui->duration->toPlainText().toStdString().c_str(),sizeof(x.duration));
        strncpy(x.economy,ui->economy->toPlainText().toStdString().c_str(),sizeof(x.economy));
        strncpy(x.business,ui->business->toPlainText().toStdString().c_str(),sizeof(x.business));
        strncpy(x.adult,ui->adult->toPlainText().toStdString().c_str(),sizeof(x.adult));
        strncpy(x.child,ui->child->toPlainText().toStdString().c_str(),sizeof(x.child));
        output.write((char *)&x,sizeof (x));
        output.close();


    hide();
    listofflights admin;
    admin.setModal(true);
    admin.exec();
}

void AddANewFlight::on_back_clicked()
{
    hide();
    listofflights admin;
    admin.setModal(true);
    admin.exec();
}
/*
void AddANewFlight::on_delete_2_clicked()
{
    flights x,y;
       strncpy(x.depcountry,ui->depcountry->toPlainText().toStdString().c_str(),sizeof (x.depcountry));
       strncpy(x.destcountry,ui->destcountry->toPlainText().toStdString().c_str(),sizeof (x.destcountry));
       strncpy(x.depdate,ui->depdate->toPlainText().toStdString().c_str(),sizeof (x.depdate));
       strncpy(x.arrdate,ui->arrivaldate->toPlainText().toStdString().c_str(),sizeof(x.arrdate));
       strncpy(x.deptime,ui->deptime->toPlainText().toStdString().c_str(),sizeof(x.deptime));
       strncpy(x.arrtime,ui->arrivaltime_2->toPlainText().toStdString().c_str(),sizeof(x.arrtime));
       strncpy(x.planenum,ui->planenumber->toPlainText().toStdString().c_str(),sizeof(x.planenum));
       strncpy(x.travcompany,ui->travelcompany->toPlainText().toStdString().c_str(),sizeof(x.travcompany));
       strncpy(x.duration,ui->duration->toPlainText().toStdString().c_str(),sizeof(x.duration));
       strncpy(x.economy,ui->economy->toPlainText().toStdString().c_str(),sizeof(x.economy));
       strncpy(x.business,ui->business->toPlainText().toStdString().c_str(),sizeof(x.business));
       strncpy(x.adult,ui->adult->toPlainText().toStdString().c_str(),sizeof(x.adult));
       strncpy(x.child,ui->child->toPlainText().toStdString().c_str(),sizeof(x.child));

       ifstream infile;
       infile.open("C:\\FlightApp\\FlightApp\\flights.bin");
       ofstream temp;
       temp.open("C:\\FlightApp\\FlightApp\\temp.bin");
       while(infile.read((char*)&y,sizeof(y)))
       {
           if(x.adult==y.adult)
               continue;
           else
           {
               temp.write((char*)&y,sizeof(y));
           }
       }
       infile.close();
       temp.close();

       ofstream outfile1;
       outfile1.open("C:\\FlightApp\\FlightApp\\flights.bin");
       ifstream temp1;
       temp1.open("C:\\FlightApp\\FlightApp\\temp.bin");
       while(temp1.read((char*)&y,sizeof(y)))
       {
           outfile1.write((char*)&y,sizeof(y));
       }
       temp1.close();
       outfile1.close();

       hide();
       listofflights admin;
       admin.setModal(true);
       admin.exec();
}
*/
