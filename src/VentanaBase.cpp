#include "VentanaBase.h"
#include <QPropertyAnimation>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

VentanaBase::VentanaBase(QWidget *parent) : QMainWindow(parent) {

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
    layoutPrincipal = new QVBoxLayout();
    layoutPrincipal->setAlignment(Qt::AlignCenter); // Centrar el contenido del layout
    
    // Asignar el layout al widget central
    central->setLayout(layoutPrincipal);

    //////////// Conexiones ////////////

}

VentanaBase::~VentanaBase() {}
