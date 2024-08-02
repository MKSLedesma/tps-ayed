#ifndef AYED_TPG_1C2024_GRAFO_HPP
#define AYED_TPG_1C2024_GRAFO_HPP

#include <vector>
#include "matriz.hpp"
#include "arista.hpp"


const int INFINITO = -1;


class grafo {
private:
    matriz<int> matriz_adyacencia;
public:


    // Constructores.
    grafo() = default;

    grafo(size_t cantidad_vertices);

    // Pre: -
    // Post: Agrega un nuevo vértice aislado al grafo (es decir, no tiene ninguna arista asociada).
    // NOTA: El número del vértice corresponde con el último índice agregado a la matriz.
    // Por ejemplo, si tienen 5 vértices y se agrega uno más, ese vértice es el 5 (recordar que matriz es 0-indexed).
    void agregar_vertice();

    // Pre: -
    // Post: Agrega (o modifica) la arista desde origen a destino. Si los vértices no son válidos, la matriz no cambia.
    // NOTA: Como solo se guarda una arista entre dos vértices, este grafo no puede tener aristas paralelas.
    void modificar_arista(size_t origen, size_t destino, int peso);

    // Pre: -
    // Post: Elimina la arista desde origen a destino. Si los vértices no son válidos, la matriz no cambia.
    void eliminar_arista(size_t origen, size_t destino);

    // Pre: -
    // Post: Aisla el vértice. Si no es válido, la matriz no cambia.
    void aislar_vertice(size_t vertice);

    // Constructor de copia..
    grafo(const grafo& grafo1);

    // Operador de asignación.
    grafo& operator=(const grafo& grafo1);

    // Pre: El grafo representado debe ser conexo y no direccionado (asumirlo).
    // Post: Devuelve el arbol de expansión mínimo/máximo.
    std::vector<arista> obtener_aem() ;

    // Pre: -
    // Post: Devuelve un vector con todas las aristas del grafo.
    std::vector<arista> obtener_todas_las_aristas(matriz<int>& matriz_adyacencia) ;
    // Pre:-
    // Post: Devuelve true si el peso de la primera arista es mayor que el peso de la segunda arista.
    static bool comparar_aristas_por_peso(arista& primera_arista, arista& segunda_arista);
    // Pre: el vértice debe ser válido.
    // Post: Devuelve el padre del vértice en el conjunto de disjoint sets.
    static size_t encontrar_padre(size_t vertice, std::vector<size_t>& padres);
    // Pre: Los conjuntos deben ser válidos .
    // Post: Une los dos subconjuntos en uno solo.
    static void unir_subconjuntos(size_t conjunto_a, size_t conjunto_b, std::vector<size_t>& padres);
    // Pre:  los vértices origen y destino deben ser válidos.
    // Post: Incrementa el contador de pedidos entre los vértices origen y destino. Si la arista no existe, se crea con un peso de 1.
    void incrementar_contador_pedidos(size_t origen, size_t destino);
    // Pre: los vértices origen y destino deben ser válidos.
    // Post: Devuelve el contador de pedidos entre los vértices origen y destino.
    int obtener_contador_pedidos(size_t origen, size_t destino);

};

#endif