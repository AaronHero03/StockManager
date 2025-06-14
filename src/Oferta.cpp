// Alexander Luna
// Implementation of the Oferta class

#include "Oferta.h"
#include <iostream>

Oferta::Oferta(int idProducto, const std::string& nombreProd, float precioBase, int stock,
               int idProveedor, const std::string& nombreProv,
               float precioOferta, const std::string& condiciones)
    : Producto(idProducto, nombreProd, precioBase, stock),
      Proveedor(idProveedor, nombreProv),
      precioOferta(precioOferta), condiciones(condiciones) {}

void Oferta::mostrarOferta() const {
    std::cout << "OFERTA de " << Producto::nombre << " por parte de " << Proveedor::nombre << std::endl;
    std::cout << "Precio original: $" << Producto::precio << " | Oferta: $" << precioOferta << std::endl;
    std::cout << "Condiciones: " << condiciones << std::endl;
}
