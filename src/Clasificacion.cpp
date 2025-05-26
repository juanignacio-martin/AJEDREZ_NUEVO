#include "clasificacion.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Constructor vac�o, inicializaciones futuras
Clasificacion::Clasificacion() {}

// Agrega una nueva entrada al ranking
void Clasificacion::agregar(const std::string& nombre, int puntos) {
    entradas.push_back(EntradaClasificacion(nombre, puntos));

    // Ordenar de mayor a menor puntuaci�n
    std::sort(entradas.begin(), entradas.end(), [](const auto& a, const auto& b) {
        return a.puntuacion > b.puntuacion;
        });

    // Recortar a las 10 primeras
    if (entradas.size() > MAX_ENTRADAS) {
        entradas.resize(MAX_ENTRADAS);
    }
}

// Muestra el ranking por consola
void Clasificacion::mostrar() const {
    std::cout << "\n--- Clasificaci�n TOP " << MAX_ENTRADAS << " ---\n";
    for (size_t i = 0; i < entradas.size(); ++i) {
        std::cout << i + 1 << ". " << entradas[i].nombre
            << " - " << entradas[i].puntuacion << " puntos\n";
    }
}

// Guarda la clasificaci�n en un archivo de texto
void Clasificacion::guardar(const std::string& archivo) const {
    std::ofstream out(archivo);
    if (!out) {
        std::cerr << "Error al guardar el archivo: " << archivo << "\n";
        return;
    }

    for (const auto& entrada : entradas) {
        out << entrada.nombre << ' ' << entrada.puntuacion << '\n';
    }
}

// Carga la clasificaci�n desde un archivo de texto
void Clasificacion::cargar(const std::string& archivo) {
    std::ifstream in(archivo);
    if (!in) {
        // Si no existe el archivo, empezamos con lista vac�a
        return;
    }

    entradas.clear();
    std::string nombre;
    int puntos;

    while (in >> nombre >> puntos) {
        entradas.push_back(EntradaClasificacion(nombre, puntos));
    }

    // Ordenamos despu�s de cargar
    std::sort(entradas.begin(), entradas.end(), [](const auto& a, const auto& b) {
        return a.puntuacion > b.puntuacion;
        });

    if (entradas.size() > MAX_ENTRADAS) {
        entradas.resize(MAX_ENTRADAS);
    }
}

// Devuelve las entradas (�til para mostrar en una GUI, por ejemplo)
const std::vector<EntradaClasificacion>& Clasificacion::obtenerEntradas() const {
    return entradas;
}
