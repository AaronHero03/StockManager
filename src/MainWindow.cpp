#include "MainWindow.h"
#include "VentanaProducto.h"
#include "VentanaProveedor.h"
#include "VentanaTransaccion.h"
#include "Inventario.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    inventario = new Inventario();  // inicializar el inventario compartido
    configurarUI();
    conectarSlots();
}

MainWindow::~MainWindow() {
    delete inventario;  // liberar memoria si no usas smart pointers
}

void MainWindow::configurarUI() {
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    this->setWindowTitle("StockManager - Menú Principal");
    this->resize(400, 500);
    this->setStyleSheet("background-color: #141414; font-family: Arial;");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QLabel* titulo = new QLabel("STOCKMANAGER");
    titulo->setStyleSheet("color: white; font-size: 24px; font-weight: bold;");
    titulo->setAlignment(Qt::AlignCenter);
    layout->addWidget(titulo);

    // Botones
    botonProductos = new QPushButton("Productos");
    botonProveedores = new QPushButton("Proveedores");
    botonTransacciones = new QPushButton("Transacciones");

    QList<QPushButton*> botones = {botonProductos, botonProveedores, botonTransacciones};
    for (QPushButton* boton : botones) {
        boton->setFixedHeight(40);
        boton->setStyleSheet("background-color: #4F48EC; color: white; font-size: 16px;");
        layout->addWidget(boton);
    }

    central->setLayout(layout);
}

void MainWindow::conectarSlots() {
    connect(botonProductos, &QPushButton::clicked, this, [=]() {
        auto* ventana = new VentanaProducto(inventario, this);
        ventana->show();
    });

    connect(botonProveedores, &QPushButton::clicked, this, [=]() {
        auto* ventana = new VentanaProveedor(this);
        ventana->show();
    });

    connect(botonTransacciones, &QPushButton::clicked, this, [=]() {
        auto* ventana = new VentanaTransaccion(inventario, this);
        ventana->show();
    });
}
