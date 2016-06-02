#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T21:32:48
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    facade.cpp \
    action.cpp \
    concreteiostreamservice.cpp

HEADERS  += mainwindow.h \
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
    baseexception.h \
    baseobject.h \
    basemodel.h \
    basecamera.h \
    basemanager.h \
    basepoint.h \
    baseedge.h \
    abstractfactory.h \
    basescene.h \
    basecomposite.h \
    basecanvas.h \
    basewindow.h \
    facade.h \
    basecommand.h \
    action.h \
    iostreamservice.h \
    concreteiostreamservice.h

FORMS    += mainwindow.ui

DISTFILES += \
    diagram.qmodel
