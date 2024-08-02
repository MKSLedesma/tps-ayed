#ifndef AYED_TPG_1C2024_A_ESTRELLA_HPP
#define AYED_TPG_1C2024_A_ESTRELLA_HPP

#include <vector>
#include <stack>
#include "vertice.hpp"
#include "mapa.hpp"

class a_estrella {
private:
    std::vector<vertice *> set_abierto;
    std::vector<vertice *> set_cerrado;
    std::vector<coordenada> direcciones = {{0,  1},
                                           {1,  0},
                                           {0,  -1},
                                           {-1, 0}}; //posibles movimientos (no puedo en diagonal)

    // Pre: -
    // Post: Devuelve el vértice con menor distancia al destino, quitándolo del set abierto.
    // Si el set abierto está vacío, devuelve nullptr.
    vertice *buscar_mejor_vertice();

    // Pre: -
    // Post: Busca y devuelve, de existir, el vértice con la posición indicada.
    // Si no existe (o el set está vacío), devuelve nullptr.
    vertice *buscar_vertice(std::vector<vertice *> set, coordenada posicion);

    // Pre: -
    // Post: Limpia los sets, liberando la memoria reservada para los vértices.
    // NOTA: Es necesario limpiarlos entre llamados a obtener_camino_minimo.
    void limpiar_sets();

    // Pre: Se debe haber encontrado el vértice destino
    // (es decir, destino está correctamente conectado con los vértices desde el origen).
    // Post: Devuelve el camino encontrado desde el origen hasta el destino.
    std::stack<coordenada> reconstruir_camino(vertice *destino);

    // Pre: Los vertices actual y fin no son nulos, mapa y heuristica estan correctamente implementados
    // Post: Agrega los vecinos al conjunto abierto si no están en el conjunto cerrado
    // y actualiza su costo, padre y distancia si se encuentra un camino más corto.
    void verificar_vecinos(vertice* actual, vertice* fin, mapa& mapa_callejon, int heuristica(vertice*, vertice*));

public:
    // Pre: -
    // Post: Devuelve el camino encontrado desde el origen hasta el destino.
    // De no haber camino, devuelve un camino vacío.
    // NOTA: Si manejan bien desde mapa la validez de un vecino, origen y destino podrían ser coordenadas no válidas.
    // Sin embargo, probablemente les convenga revisar de antemano si tiene sentido la búsqueda.
    std::stack<coordenada> obtener_camino_minimo(coordenada origen, coordenada destino, mapa &mapa_callejon, int heuristica(vertice *, vertice *));

    // Pre: los vertices a y b no son nulos
    // Post: Devuelve la distancia Manhattan entre vertice a y b
    static int heuristica_manhattan(vertice *a, vertice *b);
    //static int heuristica_euclidiana(vertice *a, vertice *b); prueba con otra heuristica
};
#endif
