#-------------------------------------------------
#
# Project created by QtCreator 2014-10-30T22:37:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShapeDrawn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scribblearea.cpp \
    customdialog.cpp \
    shape.cpp \
    line.cpp \
    oval.cpp \
    rectangle.cpp

HEADERS  += mainwindow.h \
    scribblearea.h \
    customdialog.h \
    shape.h \
    line.h \
    oval.h \
    rectangle.h

FORMS    += mainwindow.ui
