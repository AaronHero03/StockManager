#pragma once

#include <QMainWindow>

class QPushButton;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* botonProductos;
    QPushButton* botonProveedores;
    QPushButton* botonTransacciones;
    QPushButton* botonReportes;

    void configurarUI();
    void conectarSlots();
};
