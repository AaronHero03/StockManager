// Emiliano Montalvo
// Transaccion.h

#pragma once
#include <string>
#include "Producto.h"

class Transaccion {
protected:
    int id;
    std::string fecha;
    Producto* producto;
    int cantidad;

public:
    Transaccion(int id, const std::string& fecha, Producto* producto, int cantidad);
    virtual ~Transaccion();

    // Ya no es virtual pura, ahora métodos concretos
    void vender();
    void comprar();

    Transaccion operator+(int extra);
    Transaccion operator-(int menos);
};
