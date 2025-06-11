#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    /* Paleta de Colores 
    primary_color = "#4F48EC";
    enphasis_color = "#FFBF18";
    dark_bg = "#141414";
    light_bg = "#FFFFFF";
    */

    // Crear el widget central
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Configurar la ventana principal
    this->setStyleSheet("background-color: #141414; font-family: Arial;");
    this->move(100, 100); // Mover la ventana a una posición específica
    this->resize(400, 600); // Redimensionar la ventana a un tamaño específico

    // Crear un botón
//    boton = new QPushButton("Haz clic aquí", this);

    // Layout vertical
    QVBoxLayout *layout = new QVBoxLayout();
//    layout->addWidget(boton);

    // Asignar el layout al widget central
    central->setLayout(layout);

    // Conectar el clic del botón a una función lambda
/*    connect(boton, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Mensaje", "¡Hola desde Qt sin Designer!");
    });*/
}

MainWindow::~MainWindow() {
    // Qt gestiona destrucción de widgets hijos automáticamente
}
