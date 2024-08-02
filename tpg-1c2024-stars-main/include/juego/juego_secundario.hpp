#ifndef AYED_TPG_1C2024_JUEGO_SECUNDARIO_HPP
#define AYED_TPG_1C2024_JUEGO_SECUNDARIO_HPP
#include "iostream"
#include "vector"
#include "arista.hpp" 
#include "grafo.hpp"
#include "juego_principal.hpp"

class JuegoSecundario{
private:
    grafo& grafo_principal;


public:
    // Pre: Recibe una referencia a un objeto de tipo grafo.
    // Post: Inicializa el objeto JuegoSecundario con el grafo proporcionado.
    JuegoSecundario(grafo& grafo_principal) : grafo_principal(grafo_principal) {}
    // Pre: -
    // Post: Devuelve un vector de aristas que representan el árbol de expansión máxima (AEM) del grafo principal.
    std::vector<arista> obtener_caminos_transitados();
    // Pre: Recibe una referencia a un objeto de tipo arista.
    // Post: Imprime la información de la arista.
    void imprimir_arista( arista& arista) ;
     // Pre: Recibe una referencia a un vector de aristas que representan el AEM.
    // Post: Imprime la información del árbol de expansión máxima.
    void imprimir_aem( std::vector<arista>& arbol_expansion_maxima) ;

};


std::vector<arista> JuegoSecundario::obtener_caminos_transitados() {
    std::vector<arista> aem = grafo_principal.obtener_aem();
    imprimir_aem(aem);
    return aem;
}

void JuegoSecundario::imprimir_aem( std::vector<arista>& arbol_expansion_maxima)  {
    std::cout << "Senderos a priorizar, por cantidad de pedidos:" << std::endl;
    for ( arista& arista : arbol_expansion_maxima) {
        imprimir_arista(arista);
    }
}

void JuegoSecundario::imprimir_arista( arista& arista) {
    std::pair<size_t, size_t> vertices = arista.obtener_vertices();
    int peso = arista.obtener_peso();
    std::cout << "Mejorar camino entre : Local " << vertices.first + 1 << " -> Local " << vertices.second + 1<< ", Cantidad de pedidos : " << peso << std::endl;
}

#endif //AYED_TPG_1C2024_JUEGO_SECUNDARIO_HPP
