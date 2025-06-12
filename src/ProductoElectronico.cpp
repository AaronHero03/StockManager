#include "ProductoElectronico.h"
#include <iostream>

ProductoElectronico::ProductoElectronico(int id, const std::string& nombre, float precio, int stock, int garantia)
    : Producto(id, nombre, precio, stock), garantiaMeses(garantia) {}

void ProductoElectronico::mostrarInfo() const {
    Producto::mostrarInfo();
    std::cout << "Garantía: " << garantiaMeses << " meses" << std::endl;
}
