#pragma once
#include <string>
#include <vector>
#include <functional>
#include <freeglut.h>


class ControladorMenu {
    enum TEMATICA { CLASICO = 0, ETSIDI } tematica{ CLASICO};
 
public:
    ControladorMenu();

    void dibujar();
    void manejarClick(int x, int y);
    void Tema();
    void dibujaFondo();
    void setIndiceSeleccionado(int indice);
    void setOpciones(const std::vector<std::string>& opciones, const std::vector<std::function<void()>>& acciones);
    void setTematicaSeleccionada(const std::string& tema);
private:
    std::vector<std::string> textos;
    std::vector<std::function<void()>> callbacks;
    int anchoBoton = 150;
    int altoBoton = 50;
    int separacion = 70;
    int xInicio = 850;
    int yInicio = 100;
    int altoBotonGrande = 80;
    int separacionExtra = 50;
    int indiceSel = -1;
    std::string tematicaSeleccionada = "CLASICO";
};
