#-------------------------------------------------
#
# Project created by QtCreator 2018-12-12T12:53:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IntersectionTesterGUI
TEMPLATE = app


SOURCES += main.cpp\
        maininterfacewindow.cpp \
    canvas.cpp \
    IntersectTester/IntersectTester.cpp \
    IntersectTester/AABB.cpp

HEADERS  += maininterfacewindow.h \
    canvas.h \
    IntersectTester/IntersectTester.h \
    IntersectTester/AABB.h

FORMS    += maininterfacewindow.ui
