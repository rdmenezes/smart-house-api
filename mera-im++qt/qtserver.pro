#-------------------------------------------------
#
# Project created by QtCreator 2012-06-01T12:16:22
#
#-------------------------------------------------

QT       += core gui network

TARGET = qtserver
TEMPLATE = app

HEADERS += ./cClient.h \
    ./cClientsList.h \
    ./cEvent.h \
    ./cList.h \
    ./cMessageManager.h \
    ./cUtils.h \
    ./Definitions.h \
    ./qtserver.h \
    ./cQServer.h \
    ui_qtserver.h
SOURCES += ./cClient.cpp \
    ./cClientsList.cpp \
    ./cEvent.cpp \
    ./cMessageManager.cpp \
    ./cQServer.cpp \
    ./cUtils.cpp \
    ./main.cpp \
    ./qtserver.cpp
FORMS += ./qtserver.ui
