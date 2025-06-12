#include "VentanaProducto.h"

VentanaProducto::VentanaProducto(QWidget *parent) : VentanaBase(parent) {
    configurarUI();    
    //conectarSlots();
}

VentanaProducto::~VentanaProducto(){}

void VentanaProducto::configurarUI() {
    // Titulo 
    QLabel* titulo = new QLabel("Gestión de Productos");
    titulo->setStyleSheet("color: white; font-size: 20px;");
    titulo->setAlignment(Qt::AlignCenter);

    // Formulario 
    campoNombre = new QLineEdit();
    campoNombre->setPlaceholderText("Nombre del Producto");
    campoNombre->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");

    campoCategoria = new QLineEdit();
    campoCategoria->setPlaceholderText("Categoría del Producto");
    campoCategoria->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");

    campoPrecio = new QDoubleSpinBox();
    campoPrecio->setPrefix("$");
    campoPrecio->setRange(0.0, 1000000.0);
    campoPrecio->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");

    campoStock = new QSpinBox();
    campoStock->setRange(0, 10000);
    campoStock->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");
    campoMinimo = new QSpinBox();
    campoMinimo->setRange(0, 10000);
    campoMinimo->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");

    // Crear un layout de formulario
    QFormLayout* formulario = new QFormLayout();
    formulario->addRow("Nombre:", campoNombre);
    formulario->addRow("Categoría:", campoCategoria);
    formulario->addRow("Precio:", campoPrecio);
    formulario->addRow("Stock:", campoStock);
    formulario->addRow("Stock mínimo:", campoMinimo);

    // Botones
    botonAgregar = new QPushButton("Agregar");
    botonActualizar = new QPushButton("Actualizar");
    botonEliminar = new QPushButton("Eliminar");

    botonAgregar->setStyleSheet("background-color: #4F48EC; color: white;");
    botonActualizar->setStyleSheet("background-color: #FFBF18; color: black;");
    botonEliminar->setStyleSheet("background-color: red; color: white;");

    QHBoxLayout* layoutBotones = new QHBoxLayout();
    layoutBotones->addWidget(botonAgregar);
    layoutBotones->addWidget(botonActualizar);
    layoutBotones->addWidget(botonEliminar);

    // Tabla
    tablaProductos = new QTableView();
    modeloProductos = new QStandardItemModel(this);

    modeloProductos->setHorizontalHeaderLabels({"ID", "Nombre", "Categoría", "Precio", "Stock", "Mínimo"});
    tablaProductos->setModel(modeloProductos);
    tablaProductos->setStyleSheet("color: white; background-color: #1E1E1E;");

    // Añadir todos los widgets al layout principal
    layoutPrincipal->addWidget(titulo);
    layoutPrincipal->addSpacing(20);
    layoutPrincipal->addLayout(formulario);
    layoutPrincipal->addLayout(layoutBotones);
    layoutPrincipal->addWidget(tablaProductos);

    layoutPrincipal->addStretch(); 

}


