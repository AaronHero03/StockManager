#include "Producto.h"
#include <iostream>

Producto::Producto(int id, const std::string& nombre, float precio, int stock)
    : id(id), nombre(nombre), precio(precio), stock(stock) {}

Producto::~Producto() {}

void Producto::mostrarInfo() const {
    std::cout << "Producto: " << nombre << " | Precio: $" << precio << " | Stock: " << stock << std::endl;
}

void Producto::actualizarStock(int cantidad) {
    stock += cantidad;
}

bool Producto::operator==(const Producto& otro) const {
    return this->id == otro.id;
}
