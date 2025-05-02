#define SELECCION_VARIANTE_H

#include <string>

class SeleccionVariante {
public:
    SeleccionVariante(int anchoVentana, int altoVentana);

    void dibujar();
    void manejarClic(int button, int state, int x, int y);
    bool varianteConfirmada() const;
    std::string getVariante() const;


private:
    int ancho, alto;
    std::string variante;
    bool confirmada;

    void dibujarBoton(int x, int y, int ancho, int alto, const char* texto);
    bool clicEnRango(int x, int y, int bx, int by, int bw, int bh);
};