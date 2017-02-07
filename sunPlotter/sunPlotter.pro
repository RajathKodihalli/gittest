#-------------------------------------------------
#
# Project created by QtCreator 2017-01-22T21:14:25
#
#-------------------------------------------------

QT       += core gui
QT  +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sunPlotter
TEMPLATE = app


SOURCES += main.cpp\
        plotgraph.cpp \
    qcustomplot.cpp \
    tempcolorgraph.cpp \
    channelselector.cpp \
    channeldatamanager.cpp \
    plotwindow.cpp \
    tcsettings.cpp \
    showdataatcursor.cpp \
    histplotgraph.cpp \
    plotterlabels.cpp

HEADERS  += plotgraph.h \
    qcustomplot.h \
    tempcolorgraph.h \
    channelselector.h \
    channeldatamanager.h \
    plotwindow.h \
    tcsettings.h \
    showdataatcursor.h \
    histplotgraph.h \
    plotterlabels.h
