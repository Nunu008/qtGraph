#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T18:49:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graph
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    graph.cpp \
    nodeset.cpp \
    node.cpp \
    customitem.cpp

HEADERS  += dialog.h \
    graph.h \
    nodeset.h \
    node.h \
    customitem.h

FORMS    += dialog.ui
