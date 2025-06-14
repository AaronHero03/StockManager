// Alexander Luna
// Proveedor.h

#pragma once
#include <string>
#include <vector>
#include "Producto.h"

class Proveedor {
protected:
    int id;
    std::string nombre;
    std::vector<Producto*> productosSuministrados;

public:
    Proveedor(int id, const std::string& nombre);
    virtual ~Proveedor();

    void mostrarProductos() const;
    void agregarProducto(Producto* producto);
    Proveedor& operator+=(Producto* producto);
};
