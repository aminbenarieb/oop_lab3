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
    concreteiostreamservice.cpp \
    concretecommand.cpp \
    concretescene.cpp \
    compositeobject.cpp \
    concretecamera.cpp \
    point.cpp \
    matrix.cpp \
    edge.cpp \
    concretemodel.cpp \
    scenemanager.cpp \
    loadmanager.cpp \
    filestream.cpp \
    concretefactory.cpp \
    tester.cpp \
    concretetransformer.cpp \
    paintmanager.cpp \
    concretecanvas.cpp \
    concretepainter.cpp \
    transformmanager.cpp

HEADERS  += mainwindow.h \
    concreteexception.h \
    baseexception.h \
    ListContainer/_iterator.h \
    ListContainer/_iterator_const.h \
    ListContainer/_list.h \
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
    basescene.h \
    basewindow.h \
    facade.h \
    basecommand.h \
    action.h \
    iostreamservice.h \
    concreteiostreamservice.h \
    concretecommand.h \
    compositeobject.h \
    concretescene.h \
    concretecamera.h \
    point.h \
    basetransformer.h \
    matrix.h \
    edge.h \
    concretemodel.h \
    scenemanager.h \
    loadmanager.h \
    basestream.h \
    abstractfactory.h \
    filestream.h \
    concretefactory.h \
    tester.h \
    concretetransformer.h \
    basepainter.h \
    basecanvas.h \
    paintmanager.h \
    concretecanvas.h \
    concretepainter.h \
    transformmanager.h

FORMS    += mainwindow.ui

DISTFILES += \
    diagram.qmodel \
    camera.txt \
    model.txt
