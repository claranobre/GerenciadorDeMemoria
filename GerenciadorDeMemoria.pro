QT += core
QT -= gui

TARGET = GerenciadorDeMemoria
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    memoriafisica.cpp \
    memoriavirtual.cpp \
    paginas.cpp \
    mainwindow.cpp \
    dialog.cpp \
    lista.inl

HEADERS += \
    memoriafisica.h \
    memoriavirtual.h \
    paginas.h \
    mainwindow.h \
    dialog.h \
    lista.h

FORMS += \
    dialog.ui

