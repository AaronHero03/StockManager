#pragma once

#include "VentanaBase.h"

#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStandardItemModel>
#include <QFormLayout>

class QPushButton;

class VentanaProducto : public VentanaBase {
    Q_OBJECT

public:
    // Constructor
    explicit VentanaProducto(QWidget *parent = nullptr);
    
    // Destructor
    ~VentanaProducto() override;

    // Métodos virtuales heredados de VentanaBase
    void configurarUI() override; // Configura la interfaz de usuario
//    void conectarSlots() override; // Conecta señales y slots

//    void mostrarProducto(int idProducto); // Muestra los detalles del producto

private:
    // Widgets
    QLineEdit* campoNombre;
    QLineEdit* campoCategoria;
    QDoubleSpinBox* campoPrecio;
    QSpinBox* campoStock;
    QSpinBox* campoMinimo;

    QPushButton* botonAgregar;
    QPushButton* botonActualizar;
    QPushButton* botonEliminar;

    QTableView* tablaProductos;
    QStandardItemModel* modeloProductos;

    // Métodos auxiliares
    //void limpiarFormulario();
    //void cargarProductos();
    //void actualizarTabla();
};