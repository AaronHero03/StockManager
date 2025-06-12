# StockManager 

## Contexto
En esta primera etapa definimos la idea, el público objetivo y el problema que resolverá nuestra aplicación.  
El proyecto se desarrollará con C++ y Qt 6; más adelante incluiremos diagramas UML, prototipos de interfaz y la arquitectura detallada.

## Posibles consumidores
- **Empresas con gran inventario** (mayoreo, distribución, manufactura).  
- **Tiendas minoristas** que necesiten registrar entradas y salidas de productos.  
- **Negocios de servicios** que venden insumos y requieren reposiciones constantes.

## Problemática detectada
La **mala organización del inventario** provoca:
- Compras innecesarias o sobre-stock.
- Faltantes que derivan en ventas perdidas.
- Falta de trazabilidad histórica de compras y ventas.

Se requiere **optimizar el proceso de stock** y mantener un registro confiable de movimientos en periodos definidos.

## Objetivo (versión borrador)
Crear un prototipo de escritorio, multiplataforma, que:
1. Registre entradas y salidas de productos.
2. Muestre niveles actuales de inventario.
3. Genere reportes básicos de ventas y compras.