##########################################################
# Nombre del ejecutable y configuración de Qt
##########################################################
TEMPLATE = app
TARGET = main

QT += core gui widgets
CONFIG += c++17 console

##########################################################
# Indicamos la ruta de include/ (para MainWindow.h, etc.)
##########################################################
INCLUDEPATH += $$PWD/include

##########################################################
# Listado de fuentes y cabeceras de nuestro proyecto
##########################################################
SOURCES += \
    src/main.cpp \
    src/VentanaBase.cpp \
    src/VentanaProducto.cpp

HEADERS += \
    include/VentanaBase.h \ 
    include/VentanaProducto.h
