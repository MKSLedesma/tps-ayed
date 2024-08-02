#include <iostream>
#include "grafo.hpp"
#include <vector>
#include "matriz.hpp"
#include "arista.hpp"
#include <algorithm>

#include <iomanip>



grafo::grafo(size_t cantidad_vertices) {
    matriz_adyacencia = matriz(cantidad_vertices, INFINITO);
    for (size_t i = 0; i < matriz_adyacencia.columnas(); i++) {
        matriz_adyacencia.elemento(i, i) = 0;
    }

}

void grafo::agregar_vertice() {
    size_t vertices = matriz_adyacencia.columnas() + 1;
    matriz_adyacencia.redimensionar(vertices, vertices);
    for (size_t i = 0; i < vertices - 1; i++) {
        eliminar_arista(vertices - 1, i);
        eliminar_arista(i, vertices - 1);
    }
}

void grafo::modificar_arista(size_t origen, size_t destino, int peso) {
    size_t vertices = matriz_adyacencia.columnas();
    if (origen < vertices && destino < vertices) {
        matriz_adyacencia.elemento(origen, destino) = peso;
    } else {
        std::cout << "ERROR: Los vértices no son válidos. No se cambió el camino." << std::endl;
    }
}

void grafo::eliminar_arista(size_t origen, size_t destino) {
    modificar_arista(origen, destino, INFINITO);
}

void grafo::aislar_vertice(size_t vertice) {
    size_t vertices = matriz_adyacencia.columnas();
    if (vertice < vertices) {
        for (size_t i = 0; i < vertices; i++) {
            if (i != vertice) {
                eliminar_arista(i, vertice);
                eliminar_arista(vertice, i);
            }
        }
    } else {
        std::cout << "ERROR: El vértice no es válido. No se aisló." << std::endl;
    }
}

grafo::grafo(const grafo& grafo1) {
    matriz_adyacencia = grafo1.matriz_adyacencia;
}

grafo& grafo::operator=(const grafo& grafo1) {
    if (this != &grafo1) {
        matriz_adyacencia = grafo1.matriz_adyacencia;
    }
    return *this;
}


std::vector<arista> grafo::obtener_todas_las_aristas(matriz<int>& matriz_adyacencia)  {
    std::vector<arista> todas_las_aristas;
    for (size_t origen = 0; origen < matriz_adyacencia.filas(); ++origen) {
        for (size_t destino = origen + 1; destino < matriz_adyacencia.columnas(); ++destino) {
            if (matriz_adyacencia.elemento(origen, destino) != INFINITO) {
                todas_las_aristas.push_back({{origen, destino}, matriz_adyacencia.elemento(origen, destino)});
            }
        }
    }
    return todas_las_aristas;
}

bool grafo::comparar_aristas_por_peso( arista& primera_arista,  arista& segunda_arista) {
    return primera_arista.obtener_peso() > segunda_arista.obtener_peso();
}

size_t grafo::encontrar_padre(size_t vertice, std::vector<size_t>& padres) {
    while (padres[vertice] != vertice) {
        padres[vertice] = padres[padres[vertice]];
        vertice = padres[vertice];
    }
    return vertice;
}

void grafo::unir_subconjuntos(size_t conjunto_a, size_t conjunto_b, std::vector<size_t>& padres) {
    auto padre_conjunto_a = encontrar_padre(conjunto_a, padres);
    auto padre_conjunto_b = encontrar_padre(conjunto_b, padres);
    padres[padre_conjunto_a] = padre_conjunto_b;
}

std::vector<arista> grafo::obtener_aem() {
    std::vector<arista> arbol_expansion_maxima;

    auto todas_las_aristas = obtener_todas_las_aristas(matriz_adyacencia);
    std::sort(todas_las_aristas.begin(), todas_las_aristas.end(), comparar_aristas_por_peso);

    std::vector<size_t> padres(matriz_adyacencia.filas());
    for (size_t vertice = 0; vertice < padres.size(); ++vertice) {
        padres[vertice] = vertice;
    }

    for ( arista& arista : todas_las_aristas) {
        size_t origen = arista.obtener_vertices().first;
        size_t destino = arista.obtener_vertices().second;

        if (encontrar_padre(origen, padres) != encontrar_padre(destino, padres)) {
            arbol_expansion_maxima.push_back(arista);
            unir_subconjuntos(origen, destino, padres);
        }
    }
    return arbol_expansion_maxima;
}


void grafo::incrementar_contador_pedidos(size_t origen, size_t destino) {
    if (origen < matriz_adyacencia.filas() && destino < matriz_adyacencia.columnas()) {
        if (matriz_adyacencia.elemento(origen, destino) == INFINITO) {
            matriz_adyacencia.elemento(origen, destino) = 1;
        } else {
            matriz_adyacencia.elemento(origen, destino)++;
        }
        if (matriz_adyacencia.elemento(destino, origen) == INFINITO) {
            matriz_adyacencia.elemento(destino, origen) = 1;
        } else {
            matriz_adyacencia.elemento(destino, origen)++;
        }
    }
}


int grafo::obtener_contador_pedidos(size_t origen, size_t destino) {
    return matriz_adyacencia.elemento(origen, destino);
}