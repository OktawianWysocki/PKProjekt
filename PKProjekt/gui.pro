QT       += core gui
QT       += charts
FORMS    += \
    gui.ui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    Arx.cpp \
    PID.cpp \
    Sprzezenie.cpp \
    Sygnal.cpp \
    Symulacja.cpp \
    main.cpp \
    gui.cpp

HEADERS += \
    Arx.h \
    PID.h \
    Sprzezenie.h \
    Sygnal.h \
    Symulacja.h \
    gui.h

FORMS +=
