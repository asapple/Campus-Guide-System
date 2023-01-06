#-------------------------------------------------
#
# Project created by QtCreator 2021-04-07T10:17:01
#
#-------------------------------------------------
CONFIG += c++11
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CampusNagivationSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    form.cpp \
    querywidget.cpp \
    findTheWay.cpp \
    map.cpp \
    navigation.cpp \
    aboutTime.cpp \
    QIchange.cpp \
    IOfunction.cpp \
    setPaint.cpp \
    buttonEvent.cpp \
    Record.cpp \
    recordwidget.cpp \
    selectCanteen.cpp \
    mappainter.cpp

HEADERS  += widget.h \
    form.h \
    querywidget.h \
    map.h \
    recordwidget.h \
    mappainter.h

FORMS    += widget.ui \
    form.ui \
    querywidget.ui \
    recordwidget.ui \
    mappainter.ui

CONFIG+=C++11
