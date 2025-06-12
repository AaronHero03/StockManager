#pragma once
#include <string>

class Producto {
protected:
    int id;
    std::string nombre;
    float precio;
    int stock;

public:
    Producto(int id, const std::string& nombre, float precio, int stock);
    virtual ~Producto();

    virtual void mostrarInfo() const;
    void actualizarStock(int cantidad);
    bool operator==(const Producto& otro) const;
    int getId() const { return id; }
};
