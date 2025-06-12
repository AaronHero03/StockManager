#pragma once
#include "Producto.h"

class ProductoPerecedero : public Producto {
private:
    std::string fechaCaducidad;

public:
    ProductoPerecedero(int id, const std::string& nombre, float precio, int stock, const std::string& caducidad);
    void mostrarInfo() const override;
};
