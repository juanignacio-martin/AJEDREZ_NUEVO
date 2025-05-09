#pragma once
#include <string>
#include <vector>
#include <functional>
#include <freeglut.h>

class ControladorMenu {
public:
    ControladorMenu();

    void dibujar();
    void manejarClick(int x, int y);

    void setOpciones(const std::vector<std::string>& opciones, const std::vector<std::function<void()>>& acciones);

private:
    std::vector<std::string> textos;
    std::vector<std::function<void()>> callbacks;
    int anchoBoton = 300;
    int altoBoton = 60;
    int separacion = 20;
    int xInicio = 100;
    int yInicio = 100;
};
