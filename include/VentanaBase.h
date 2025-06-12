#pragma once

#include <QMainWindow>
#include <QVBoxLayout>

class QPushButton;

class VentanaBase : public QMainWindow {
    Q_OBJECT

public:
    explicit VentanaBase(QWidget *parent = nullptr);
    virtual ~VentanaBase();
    virtual void configurarUI() = 0; // Método virtual puro para configurar la UI
    //virtual void conectarSlots() = 0; // Método virtual puro para conectar señales y slots

    QVBoxLayout* layoutPrincipal;

private:
};