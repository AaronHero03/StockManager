// Aaron hernandez
// ventanaProducto.cpp

#include "VentanaProducto.h"

VentanaProducto::VentanaProducto(Inventario* inventario, QWidget *parent)
    : VentanaBase(parent), inventario(inventario) {
    configurarUI();
    conectarSlots();
}

VentanaProducto::~VentanaProducto(){}

void VentanaProducto::configurarUI() {
    // Modificaciones a la ventana base
    this->resize(700, 400); // Redimensionar la ventana a un tamaño específico


    // Titulo 
    QLabel* titulo = new QLabel("Gestión de Productos");
    titulo->setStyleSheet("color: white; font-size: 20px;");
    titulo->setAlignment(Qt::AlignCenter);

    // Formulario 
    campoNombre = new QLineEdit();
    campoNombre->setPlaceholderText("Nombre del Producto");
    campoNombre->setStyleSheet("background-color: #FFFFFF; color: #000000; padding: 5px; border-radius: 5px;");

    campoCategoria = new QComboBox();
    campoCategoria->addItem("Producto");
    campoCategoria->addItem("Producto electrónico");
    campoCategoria->addItem("Producto perecedero");
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
    botonEliminar = new QPushButton("Eliminar");

    botonAgregar->setStyleSheet("background-color: #4F48EC; color: white;");
    botonEliminar->setStyleSheet("background-color: red; color: white;");

    QHBoxLayout* layoutBotones = new QHBoxLayout();
    layoutBotones->addWidget(botonAgregar);
    layoutBotones->addWidget(botonEliminar);

    // Tabla
    tablaProductos = new QTableView();
    modeloProductos = new QStandardItemModel(this);

    modeloProductos->setHorizontalHeaderLabels({"ID", "Nombre", "Categoría", "Precio", "Stock", "Mínimo"});
    tablaProductos->setModel(modeloProductos);
    tablaProductos->setStyleSheet("color: white; background-color: #1E1E1E; border: 1px solid #FFBF18;");
    tablaProductos->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tablaProductos->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Añadir todos los widgets al layout principal
    layoutPrincipal->addWidget(titulo);
    layoutPrincipal->addSpacing(20);
    layoutPrincipal->addLayout(formulario);
    layoutPrincipal->addLayout(layoutBotones);
    layoutPrincipal->addWidget(tablaProductos);

    layoutPrincipal->addStretch(); 

}

// Conexión de señales y slots
void VentanaProducto::conectarSlots() {
    connect(botonAgregar, &QPushButton::clicked, this, [=]() {
        // Validar campos
        QString nombre = campoNombre->text();
        if (nombre.isEmpty()) {
            QMessageBox::warning(this, "Error", "El nombre del producto no puede estar vacío.");
            return;
        }

        static int idCounter = 1; // Contador para IDs de productos
        std::string categoria = campoCategoria->currentText().toStdString();

        Producto* nuevoProducto = nullptr;

        if (categoria == "Producto") {
            nuevoProducto = new Producto(idCounter, nombre.toStdString(), campoPrecio->value(), campoStock->value());
        } else if (categoria == "Producto electrónico") {
            nuevoProducto = new ProductoElectronico(idCounter, nombre.toStdString(), campoPrecio->value(), campoStock->value());
        } else if (categoria == "Producto perecedero") {
            nuevoProducto = new ProductoPerecedero(idCounter, nombre.toStdString(), campoPrecio->value(), campoStock->value());
        }
        
    if (nuevoProducto) {
        listaProductos.push_back(*nuevoProducto);  // guardas una copia
        // Agregar fila a la tabla
        QList<QStandardItem*> fila;
        fila << new QStandardItem(QString::number(nuevoProducto->getId()));
        fila << new QStandardItem(nombre);
        fila << new QStandardItem(campoCategoria->currentText());
        fila << new QStandardItem(QString::number(campoPrecio->value(), 'f', 2));
        fila << new QStandardItem(QString::number(campoStock->value()));
        fila << new QStandardItem(QString::number(campoMinimo->value()));
        modeloProductos->appendRow(fila);
        inventario->agregarProducto(*nuevoProducto);

        delete nuevoProducto;  // liberamos memoria si se usó new
        idCounter++;
    }
        limpiarFormulario();
    });

    connect(botonEliminar, &QPushButton::clicked, this, [=]() {
        QModelIndex index = tablaProductos->currentIndex();
        if (index.isValid()) {
            modeloProductos->removeRow(index.row());
        } else {
            QMessageBox::information(this, "Info", "Selecciona una fila para eliminar.");
        }
    });

    // Los demás botones puedes conectarlos aquí también
}

// Método auxiliar
void VentanaProducto::limpiarFormulario() {
    campoNombre->clear();
    campoCategoria->setCurrentIndex(0);
    campoPrecio->setValue(0.0);
    campoStock->setValue(0);
    campoMinimo->setValue(0);
}

