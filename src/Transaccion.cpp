#include "Transaccion.h"
#include <iostream>

Transaccion::Transaccion(int id, const std::string& fecha, Producto* producto, int cantidad)
    : id(id), fecha(fecha), producto(producto), cantidad(cantidad) {}

Transaccion::~Transaccion() {}

void Transaccion::vender() {
    std::cout << "Vendiendo " << cantidad << " unidades de producto ID " << producto->getId() << "\n";
    // Aquí la lógica de venta
}

void Transaccion::comprar() {
    std::cout << "Comprando " << cantidad << " unidades de producto ID " << producto->getId() << "\n";
    // Aquí la lógica de compra
}

Transaccion Transaccion::operator+(int extra) {
    return Transaccion(id, fecha, producto, cantidad + extra);
}

Transaccion Transaccion::operator-(int menos) {
    return Transaccion(id, fecha, producto, cantidad - menos);
}
