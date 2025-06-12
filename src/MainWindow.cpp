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

    // Layout vertical
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter); // Centrar el contenido del layout
    

    //////////// Layout horizontal ////////////

    // Crear un botón
    boton = new QPushButton("Haz clic aquí", this);
    
    // Establece la altura del boton a 100px
    boton->setFixedHeight(50);
    boton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    
    boton->setStyleSheet("background-color: #4F48EC; color: white; font-size: 16px; border-radius: 10px;");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch(1);
    hLayout->addWidget(boton, 8);
    hLayout->addStretch(1);

    //////////////// Fin del Layout horizontal ////////////

    // Añadir el layout horizontal al layout principal
    layout->addLayout(hLayout);
    layout->addStretch(); // Añadir espacio flexible para centrar el botón verticalmente

    // Asignar el layout al widget central
    central->setLayout(layout);



    //////////// Conexiones ////////////

    // Conectar el clic del botón a una función lambda
    connect(boton, &QPushButton::clicked, this, []() {
        QMessageBox::information(nullptr, "Mensaje", "¡Hola desde Qt sin Designer!");
    });
}

MainWindow::~MainWindow() {
    
}
