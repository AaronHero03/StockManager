# Diagrama de clases – Parte gráfica de StockManager

```mermaid
classDiagram

%% Clases base
class QWidget
class VentanaBase {
    +configurarUI()*
    +conectarSlots()*
}

%% Ventana principal
class MainWindow {
    +mostrarVentanaProducto()
    +mostrarVentanaProveedor()
    +mostrarVentanaTransaccion()
}

QWidget <!-- MainWindow
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

VentanaBase <|-- VentanaProducto
VentanaBase <|-- VentanaProveedor
VentanaBase <|-- VentanaTransaccion

MainWindow ..> VentanaProducto
MainWindow ..> VentanaProveedor
MainWindow ..> VentanaTransaccion
