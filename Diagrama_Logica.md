# Diagrama de Clases

```mermaid
classDiagram
    class Proveedor {
        - id: int
        - nombre: string
        - productosSuministrados: List~Producto~
        + mostrarProductos(): void
        + operator+=(Producto): Proveedor
    }

    class Producto {
        - id: int
        - nombre: string
        - precio: float
        - stock: int
        + mostrarInfo(): void
        + actualizarStock(cantidad: int): void
        + operator==(Producto): bool
    }

    class ProductoPerecedero {
        - fechaCaducidad: string
        + mostrarInfo(): void
    }

    class ProductoElectronico {
        - garantiaMeses: int
        + mostrarInfo(): void
    }

    class Transaccion {
        - id: int
        - fecha: string
        - producto: Producto
        - cantidad: int
        + procesar(): void
        + operator+(int): Transaccion
        + operator-(int): Transaccion
    }

    class Oferta {
        - descuento: float
        - fechaInicio: string
        - fechaFin: string
        + aplicarDescuento(): void
        + mostrarOferta(): void
    }

    ProductoPerecedero <|-- Producto
    ProductoElectronico <|-- Producto
    Transaccion <|-- Producto
    Oferta <|-- Proveedor
    Oferta <|-- Producto