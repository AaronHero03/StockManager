// Alexander Luna
// Oferta.h

#pragma once
#include "Producto.h"
#include "Proveedor.h"

class Oferta : public Producto, public Proveedor {
private:
    float precioOferta;
    std::string condiciones;

public:
    Oferta(int idProducto, const std::string& nombreProd, float precioBase, int stock,
           int idProveedor, const std::string& nombreProv,
           float precioOferta, const std::string& condiciones);


    void mostrarOferta() const;
};
