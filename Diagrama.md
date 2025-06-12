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


VentanaBase <|-- VentanaProducto
VentanaBase <|-- VentanaProveedor
VentanaBase <|-- VentanaTransaccion


%% Ventana principal
class MainWindow {
    +mostrarVentanaProducto()
    +mostrarVentanaProveedor()
    +mostrarVentanaTransaccion()
}

MainWindow --> VentanaProducto
MainWindow --> VentanaProveedor
MainWindow --> VentanaTransaccion
