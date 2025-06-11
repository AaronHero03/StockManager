#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Crear el widget central
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Crear un botón
    boton = new QPushButton("Haz clic aquí", this);

    // Layout vertical
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(boton);

    // Asignar el layout al widget central
    central->setLayout(layout);

    // Conectar el clic del botón a una función lambda
    connect(boton, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Mensaje", "¡Hola desde Qt sin Designer!");
    });
}

MainWindow::~MainWindow() {
    // Qt gestiona destrucción de widgets hijos automáticamente
}
