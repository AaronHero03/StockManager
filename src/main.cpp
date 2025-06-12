#include <QApplication>

#include "VentanaProducto.h"

int main(int argc, char *argv[]) {
    // 1. Crear el objeto QApplication
    QApplication app(argc, argv);

    // 2. Crear la ventana principal
    VentanaProducto ventanaProducto;
    ventanaProducto.show();

    // 3. Ejecutar el bucle de eventos
    return app.exec();
}
