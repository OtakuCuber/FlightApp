QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addanewflight.cpp \
    editanewflight.cpp \
    editnewpassenger.cpp \
    main.cpp \
    mainwindow.cpp \
    costoftickets.cpp \
    edittickets.cpp \
    receipt.cpp \
    planeseats.cpp \
    listsofpassengers.cpp


HEADERS += \
    addanewflight.h \
    editanewflight.h \
    editnewpassenger.h \
    mainwindow.h \
    costoftickets.h \
    edittickets.h \
    receipt.h \
    planeseats.h \
    listsofpassengers.h

FORMS += \
    addanewflight.ui \
    addnewpassenger.ui \
    editanewflight.ui \
    editnewpassenger.ui \
    mainwindow.ui \
    costoftickets.ui \
    edittickets.ui \
    receipt.ui \
    planeseats.ui \
    listsofpassengers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
