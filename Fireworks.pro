QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fireworks
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    firework.cpp

HEADERS  += mainwindow.h \
    firework.h

FORMS    += mainwindow.ui
