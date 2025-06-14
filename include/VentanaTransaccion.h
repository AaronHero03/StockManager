// Alexander Luna
// ventanaTransaccion.h

#pragma once

#include "VentanaBase.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Oferta.h"
#include "Transaccion.h"
#include "Inventario.h"

#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStandardItemModel>
#include <QFormLayout>
#include <QMessageBox>
#include <vector>

class VentanaTransaccion : public VentanaBase {
    Q_OBJECT

public:
    ~VentanaTransaccion() override;
    explicit VentanaTransaccion(Inventario* inventario, QWidget *parent = nullptr);
    
    void configurarUI() override;
    void conectarSlots() override;

private:
    QLineEdit* campoProducto;
    QLineEdit* campoProveedor;
    QLineEdit* campoFecha;
    QSpinBox* campoCantidad;

    QPushButton* botonComprar;
    QPushButton* botonVender;

    QTableView* tablaTransacciones;
    QStandardItemModel* modeloTransacciones;

    std::vector<Transaccion> listaTransacciones;

    Inventario* inventario;

    void limpiarFormulario();
    void registrarCompra();
    void registrarVenta();
};