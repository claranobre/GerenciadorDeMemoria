QT += core
QT -= gui

TARGET = GerenciadorDeMemoria
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    memoriavirtual.cpp \
    paginas.cpp \
    mainwindow.cpp \
    dialog.cpp \
    lista.inl \
    memoriafisica.cpp

HEADERS += \
    memoriavirtual.h \
    paginas.h \
    mainwindow.h \
    dialog.h \
    lista.h \
    memoriafisica.h

FORMS += \
    dialog.ui \
    mainwindow.ui

