#ifndef CLASIFICACION_H
#define CLASIFICACION_H

#include <vector>
#include <string>

struct EntradaClasificacion {
    std::string nombre;
    int puntuacion;

    EntradaClasificacion() : nombre(""), puntuacion(0) {}  // Constructor por defecto
    EntradaClasificacion(const std::string& n, int p)
        : nombre(n), puntuacion(p) {
    }
};


class Clasificacion {
private:
    std::vector<EntradaClasificacion> entradas;
    const size_t MAX_ENTRADAS = 10;

public:
    Clasificacion();

    void agregar(const std::string& nombre, int puntos);
    void mostrar() const;

    void guardar(const std::string& archivo) const;
    void cargar(const std::string& archivo);

    const std::vector<EntradaClasificacion>& obtenerEntradas() const;
};

#endif
