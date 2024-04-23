QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abcdialog.cpp \
    addbooking.cpp \
    addcustomer.cpp \
    airport.cpp \
    algorithmen.cpp \
    booking.cpp \
    customer.cpp \
    customersearchdialog.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    main.cpp \
    rentalcarreservation.cpp \
    savetojson.cpp \
    sortfunktor.cpp \
    testresult.cpp \
    travel.cpp \
    travelagency.cpp \
    travelagencyui.cpp

HEADERS += \
    ../Programmieren 2/Kapitel 7/Vorlesungsuebung_Graphendurchlauf_Ausgangspunkt/digraph.h \
    abcdialog.h \
    addbooking.h \
    addcustomer.h \
    airport.h \
    booking.h \
    customer.h \
    customersearchdialog.h \
    digraph.h \
    flightbooking.h \
    hotelbooking.h \
    rentalcarreservation.h \
    savetojson.h \
    sortfunktor.h \
    testresult.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    abcdialog.ui \
    addbooking.ui \
    addcustomer.ui \
    customersearchdialog.ui \
    savetojson.ui \
    testresult.ui \
    travelagencyui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
