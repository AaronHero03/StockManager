#pragma once

#include "VentanaBase.h"
#include "VentanaProducto.h"
#include "Producto.h"
#include "ProductoElectronico.h"
#include "ProductoPerecedero.h"

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
#include <QMessageBox>
#include <QComboBox>

#include <vector>


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
    void conectarSlots() override; // Conecta señales y slots

//    void mostrarProducto(int idProducto); // Muestra los detalles del producto

private:
    // Widgets
    QLineEdit* campoNombre;
    QComboBox* campoCategoria;
    QDoubleSpinBox* campoPrecio;
    QSpinBox* campoStock;
    QSpinBox* campoMinimo;

    QPushButton* botonAgregar;
    QPushButton* botonActualizar;
    QPushButton* botonEliminar;

    QTableView* tablaProductos;
    QStandardItemModel* modeloProductos;

    std::vector<Producto> listaProductos; // Almacena los IDs de los productos

    // Métodos auxiliares
    void limpiarFormulario();
    //void cargarProductos();
    //void actualizarTabla();
};