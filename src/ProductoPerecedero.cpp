#include "ProductoPerecedero.h"
#include <iostream>

ProductoPerecedero::ProductoPerecedero(int id, const std::string& nombre, float precio, int stock, const std::string& caducidad)
    : Producto(id, nombre, precio, stock), fechaCaducidad(caducidad) {}

void ProductoPerecedero::mostrarInfo() const {
    Producto::mostrarInfo();
    std::cout << "Caduca el: " << fechaCaducidad << std::endl;
}
