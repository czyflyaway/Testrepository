#-------------------------------------------------
#
# Project created by QtCreator 2017-03-19T11:08:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bitmap
TEMPLATE = app
LIBS += zint.dll

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
