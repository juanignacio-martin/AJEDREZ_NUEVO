#pragma once
#include <string>
#include <vector>
#include <functional>
#include <freeglut.h>


class ControladorMenu {
    enum TEMATICA { SW = 0, ETSIDI } tematica{ SW };

public:
    ControladorMenu();

    void dibujar();
    void manejarClick(int x, int y);
    void Tema();
    void dibujaFondo();

    void setOpciones(const std::vector<std::string>& opciones, const std::vector<std::function<void()>>& acciones);

private:
    std::vector<std::string> textos;
    std::vector<std::function<void()>> callbacks;
    int anchoBoton = 200;
    int altoBoton = 60;
    int separacion = 40;
    int xInicio = 300;
    int yInicio = 100;
    int altoBotonGrande = 100;
    int separacionExtra = 50;
};
