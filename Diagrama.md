# Diagrama de clases – Parte gráfica de StockManager

```mermaid
classDiagram

%% Clases base
class QWidget
class VentanaBase {
    +configurarUI()*
    +conectarSlots()*
}

QWidget <|-- VentanaBase

%% Ventanas gráficas
class VentanaProducto {
    +configurarUI()
    +conectarSlots()
    +mostrarProducto()
}
class VentanaProveedor {
    +configurarUI()
    +conectarSlots()
}
class VentanaTransaccion {
    +configurarUI()
    +conectarSlots()
    +registrarCompra()
    +registrarVenta()
}
class VentanaReporte {
    +configurarUI()
    +conectarSlots()
    +generarPDF()
    +generarCSV()
}

VentanaBase <|-- VentanaProducto
VentanaBase <|-- VentanaProveedor
VentanaBase <|-- VentanaTransaccion
VentanaBase <|-- VentanaReporte

%% Herencia múltiple con lógica
class Gestionable {
    <<interface>>
    +guardar()
    +cargar()
}
VentanaProducto ..|> Gestionable
VentanaProveedor ..|> Gestionable

%% Clases lógicas usadas por las interfaces
class Producto {
    -id
    -nombre
    -precio
    -stock
    +actualizarStock()
}
class Proveedor {
    -id
    -nombreEmpresa
    +agregarProducto()
}
class Transaccion {
    -id
    -tipo
    -producto
    -cantidad
    +aplicar()
}
class Reporteador {
    +generar(vector~Producto~)
    +generar(vector~Transaccion~)
}

%% Asociación lógica a UI
VentanaProducto --> Producto
VentanaProveedor --> Proveedor
VentanaTransaccion --> Transaccion
VentanaReporte --> Reporteador

%% Ventana principal
class MainWindow {
    +mostrarVentanaProducto()
    +mostrarVentanaProveedor()
    +mostrarVentanaTransaccion()
    +mostrarVentanaReporte()
}
MainWindow --> VentanaProducto
MainWindow --> VentanaProveedor
MainWindow --> VentanaTransaccion
MainWindow --> VentanaReporte
