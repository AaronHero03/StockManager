// Alexander Luna
// Proveedor.cpp

#include "Proveedor.h"
#include <iostream>

Proveedor::Proveedor(int id, const std::string& nombre) : id(id), nombre(nombre) {}

Proveedor::~Proveedor() {}

void Proveedor::mostrarProductos() const {
    std::cout << "Proveedor: " << nombre << "\nProductos:" << std::endl;
    for (const auto& p : productosSuministrados) {
        p->mostrarInfo();
    }
}

void Proveedor::agregarProducto(Producto* producto) {
    productosSuministrados.push_back(producto);
}

Proveedor& Proveedor::operator+=(Producto* producto) {
    agregarProducto(producto);
    return *this;
}
