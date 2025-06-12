// InventarioProductos.h
#pragma once
#include <vector>
#include "Producto.h"

class Inventario {
public:
    void agregarProducto(const Producto& p);
    const std::vector<Producto>& obtenerProductos() const;

private:
    std::vector<Producto> listaProductos;
};
