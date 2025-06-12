#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class Inventario;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void configurarUI();
    void conectarSlots();

    QPushButton *botonProductos;
    QPushButton *botonProveedores;
    QPushButton *botonTransacciones;

    Inventario *inventario;  // puntero al inventario compartido
};

#endif // MAINWINDOW_H
