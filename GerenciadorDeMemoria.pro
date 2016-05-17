QT += core
QT -= gui

TARGET = GerenciadorDeMemoria
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    memoriafisica.cpp \
    memoriavirtual.cpp \
    paginas.cpp

HEADERS += \
    memoriafisica.h \
    memoriavirtual.h \
    paginas.h

