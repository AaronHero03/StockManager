#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include "VentanaBase.h"

class VentanaProveedor : public VentanaBase
{
    Q_OBJECT

public:
    explicit VentanaProveedor(QWidget *parent = nullptr);
    ~VentanaProveedor();

private:
    // Métodos
    void configurarUI();
    void conectarSlots();
    void limpiarFormulario();

    // Widgets
    QLineEdit* campoNombreEmpresa;
    QLineEdit* campoTelefono;
    QLineEdit* campoEmail;

    QPushButton* botonAgregar;
    QPushButton* botonEliminar;

    QListWidget* listaProveedores;


};

