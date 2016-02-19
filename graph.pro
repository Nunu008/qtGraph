#-------------------------------------------------
#
# Project created by QtCreator 2016-02-08T20:40:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graph
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    node.cpp \
    nodeset.cpp \
    customitem.cpp \
    graph.cpp

HEADERS  += dialog.h \
    node.h \
    nodeset.h \
    customitem.h \
    graph.h

FORMS    += dialog.ui
