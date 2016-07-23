#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T20:59:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hospital
TEMPLATE = app

CONFIG += c++11
SOURCES += main.cpp\
        mainwindow.cpp \
    sqlist.cpp \
    patient.cpp \
    heap.cpp \
    priority_queue.cpp \
    inputdialog.cpp \
    generatedialog.cpp \
    wtdialog.cpp

HEADERS  += mainwindow.h \
    sqlist.h \
    patient.h \
    heap.h \
    priority_queue.h \
    inputdialog.h \
    generatedialog.h \
    wtdialog.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    generatedialog.ui \
    wtdialog.ui
