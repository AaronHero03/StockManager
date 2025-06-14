// David Bribiesca 
// ProductoElectronico.h

#pragma once
#include "Producto.h"

class ProductoElectronico : public Producto {
private:
    int garantiaMeses;

public:
    ProductoElectronico(int id, const std::string& nombre, float precio, int stock);
    void mostrarInfo() const override;
};
