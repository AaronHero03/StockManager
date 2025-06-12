#include "VentanaProveedor.h"
#include <QFormLayout>
#include <QMessageBox>

VentanaProveedor::VentanaProveedor(QWidget *parent) : VentanaBase(parent) {
    configurarUI();
    conectarSlots();
}

VentanaProveedor::~VentanaProveedor() {}

void VentanaProveedor::configurarUI() {
    QLabel* titulo = new QLabel("Gestión de Proveedores");
    titulo->setStyleSheet("color: white; font-size: 20px;");
    titulo->setAlignment(Qt::AlignCenter);
    layoutPrincipal->addWidget(titulo);

    // Campos
    campoNombreEmpresa = new QLineEdit();
    campoNombreEmpresa->setPlaceholderText("Nombre de la empresa");

    campoTelefono = new QLineEdit();
    campoTelefono->setPlaceholderText("Teléfono");

    campoEmail = new QLineEdit();
    campoEmail->setPlaceholderText("Correo electrónico");

    QFormLayout* formulario = new QFormLayout();
    formulario->addRow("Empresa:", campoNombreEmpresa);
    formulario->addRow("Teléfono:", campoTelefono);
    formulario->addRow("Correo:", campoEmail);

    layoutPrincipal->addLayout(formulario);

    // Botones
    botonAgregar = new QPushButton("Agregar");
    botonEliminar = new QPushButton("Eliminar");

    botonAgregar->setStyleSheet("background-color: #4F48EC; color: white;");
    botonEliminar->setStyleSheet("background-color: red; color: white;");

    QHBoxLayout* botones = new QHBoxLayout();
    botones->addWidget(botonAgregar);
    botones->addWidget(botonEliminar);

    layoutPrincipal->addLayout(botones);

    // Lista de proveedores
    listaProveedores = new QListWidget();
    listaProveedores->setStyleSheet("background-color: #1E1E1E; color: white;");
    layoutPrincipal->addWidget(listaProveedores);
}

void VentanaProveedor::conectarSlots() {
    connect(botonAgregar, &QPushButton::clicked, this, [=]() {
        QString nombre = campoNombreEmpresa->text();
        QString telefono = campoTelefono->text();
        QString email = campoEmail->text();

        if (nombre.isEmpty() || telefono.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Error", "Todos los campos deben estar completos.");
            return;
        }

        QString proveedorInfo = nombre + " | " + telefono + " | " + email;
        listaProveedores->addItem(proveedorInfo);
        limpiarFormulario();
    });

    connect(botonEliminar, &QPushButton::clicked, this, [=]() {
        QListWidgetItem* item = listaProveedores->currentItem();
        if (item) {
            delete item;
        } else {
            QMessageBox::information(this, "Info", "Selecciona un proveedor para eliminar.");
        }
    });
}

void VentanaProveedor::limpiarFormulario() {
    campoNombreEmpresa->clear();
    campoTelefono->clear();
    campoEmail->clear();
}
