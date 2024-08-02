#include "a_estrella.hpp"
#include <algorithm>
#include <cmath>

vertice* a_estrella::buscar_mejor_vertice() {
    vertice* mejor_vertice = nullptr;
    auto it = min_element(set_abierto.begin(), set_abierto.end(), vertice::menor);
    if (it != set_abierto.end()) {
        mejor_vertice = *it;
        set_abierto.erase(it);
    }
    return mejor_vertice;
}

vertice* a_estrella::buscar_vertice(std::vector<vertice*> set, coordenada posicion) {
    vertice* vertice_buscado = nullptr;
    auto coincide_posicion = [&posicion](vertice* v) { return *v == posicion; };
    auto it = std::find_if(set.begin(), set.end(), coincide_posicion);
    if (it != set.end()) {
        vertice_buscado = *it;
    }
    return vertice_buscado;
}

void a_estrella::limpiar_sets() {
    for (vertice* vertice: set_abierto) {
        delete vertice;
    }
    for (vertice* vertice: set_cerrado) {
        delete vertice;
    }
    set_abierto.clear();
    set_cerrado.clear();
}

std::stack<coordenada> a_estrella::reconstruir_camino(vertice* destino) {
    std::stack<coordenada> camino_desde_origen;
    while (destino != nullptr) {
        camino_desde_origen.push(destino->posicion);
        destino = destino->padre;
    }
    return camino_desde_origen;
}

void a_estrella::verificar_vecinos(vertice *actual, vertice *fin, mapa &mapa_callejon, int (*heuristica)(vertice *, vertice *)) {
    for (const auto& coordenadas : direcciones) {
        coordenada posicion_vecino = {actual->posicion.x() + coordenadas.first, actual->posicion.y() + coordenadas.second}; //calculo la coordenada del vecino

        if (mapa_callejon.es_vecino_valido(posicion_vecino) && !buscar_vertice(set_cerrado, posicion_vecino)) { //que sea 'caminable' y no este en el set cerrado
            int nuevo_costo = actual->costo_origen + 1;
            vertice* vecino = buscar_vertice(set_abierto, posicion_vecino); //busco al vecino en el conjunto abierto

            if (vecino == nullptr) {                                        //si no esta, lo agrego
                vecino = new vertice(posicion_vecino, actual);
                vecino->costo_origen = nuevo_costo;
                vecino->distancia_destino = heuristica(vecino, fin);
                set_abierto.push_back(vecino);
            } else if (nuevo_costo < vecino->costo_origen) {            //si esta evaluo si hay un costo menor
                vecino->padre = actual;
                vecino->costo_origen = nuevo_costo;
                vecino->distancia_destino = heuristica(vecino, fin);
            }
        }
    }
}

std::stack<coordenada> a_estrella::obtener_camino_minimo(coordenada origen, coordenada destino, mapa& mapa_callejon,
                                                         int heuristica(vertice*, vertice*)) {
    std::stack<coordenada> camino;
    bool camino_encontrado = false;
    vertice* inicio = new vertice(origen);
    vertice* fin = new vertice(destino);

    set_abierto.push_back(inicio);

    while (!set_abierto.empty() && !camino_encontrado) { //mientras que set abierto tenga valores y no encuentre el destino
        vertice* actual = buscar_mejor_vertice();

        if (*actual == destino) {                           // si encuentro el destino, reonstruyo camino y salgo
            camino = reconstruir_camino(actual);
            camino_encontrado = true;
        } else {                                            //sino, sigo buscando los vecinos
            set_cerrado.push_back(actual);
            verificar_vecinos(actual, fin, mapa_callejon, heuristica);
        }
    }
    limpiar_sets();

    return camino;
}

int a_estrella::heuristica_manhattan(vertice *a, vertice *b) {
    return abs(a->posicion.x() - b->posicion.x()) + abs(a->posicion.y() - b->posicion.y());
}

/*int a_estrella::heuristica_euclidiana(vertice *a, vertice *b) {
    return static_cast<int>(sqrt(
            pow(a->posicion.x() - b->posicion.x(), 2) + pow(a->posicion.y() - b->posicion.y(), 2)));
}*/
