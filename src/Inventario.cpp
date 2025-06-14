// InventarioProductos.cpp
// David Bribiesca Valtierra
#include "Inventario.h"

void Inventario::agregarProducto(const Producto& p) {
    listaProductos.push_back(p);
}

const std::vector<Producto>& Inventario::obtenerProductos() const {
    return listaProductos;
}
