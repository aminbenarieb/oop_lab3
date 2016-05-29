#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T21:32:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    command.h \
    concreteexception.h \
    baseexception.h \
    ListContainer/_iterator.h \
    ListContainer/_iterator_const.h \
    ListContainer/_list.h \
    ListContainer/base_error.h \
    ListContainer/base_list.h \
    ListContainer/error_iterator.h \
    ListContainer/error_list.h \
    ListContainer/iterator.h \
    ListContainer/iterator_const.h \
    ListContainer/list.h \
    ListContainer/node.h \
    concretecommand.h \
    baseexception.h

FORMS    += mainwindow.ui

DISTFILES += \
    diagram.qmodel
