// Aaron Hernandez
// productoPerecedero.h

#pragma once
#include "Producto.h"

class ProductoPerecedero : public Producto {
private:
    std::string fechaCaducidad;

public:
    ProductoPerecedero(int id, const std::string& nombre, float precio, int stock);
    void mostrarInfo() const override;
};
