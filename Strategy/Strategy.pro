TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    customer.cpp \
    ipayment.cpp \
    paycash.cpp \
    paycard.cpp

HEADERS += \
    customer.h \
    ipayment.h \
    paycash.h \
    paycard.h

