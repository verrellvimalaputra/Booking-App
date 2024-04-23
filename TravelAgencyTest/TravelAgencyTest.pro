QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_travelagencytest.cpp \
    booking.cpp \
    customer.cpp \
    flightbooking.cpp \
    hotelbooking.cpp \
    rentalcarreservation.cpp \
    travel.cpp \
    travelagency.cpp \
    airport.cpp

HEADERS += \
    booking.h \
    customer.h \
    flightbooking.h \
    hotelbooking.h \
    rentalcarreservation.h \
    travel.h \
    travelagency.h \
    airport.h
