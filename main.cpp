#include "mainwindow.h"
#include "addanewflight.h"
#include "login.h"
#include "listsofpassengers.h"
#include "adminhomepage.h"
#include<createaccount.h>
#include <QApplication>
#include<iostream>
#include<QString>
#include<QTextEdit>
#include<iostream>
#include "userhomepage.h"
#include "adminhomepage.h"
#include "costoftickets.h"
using namespace std;
int code=0;
struct passenger
{
    int ID;
    string FN;
    string LN;
    string email;
    string password;
    string birthdate;
    int phonenumber;
    int passportnumber;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    costoftickets w;
    w.show();
    return a.exec();
}
