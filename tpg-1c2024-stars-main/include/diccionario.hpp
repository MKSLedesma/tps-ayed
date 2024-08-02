/* Archivo realizado en conjunto por los alumnos Elias Josue Cuba y Mauricio Agustin Laganga. */

#ifndef AYED_TPG_1C2024_DICCIONARIO_HPP
#define AYED_TPG_1C2024_DICCIONARIO_HPP

#include <exception>
#include <cstdlib>
#include <vector>
#include <queue>
#include "nodo.hpp"

const int RAIZ = 0;
const int NODO_IZQUIERDO = 1;
const int NODO_DERECHO = 2;

const std::vector<int> PREORDER = {RAIZ, NODO_IZQUIERDO, NODO_DERECHO};
const std::vector<int> INORDER = {NODO_IZQUIERDO, RAIZ, NODO_DERECHO};
const std::vector<int> POSTORDER = {NODO_IZQUIERDO, NODO_DERECHO, RAIZ};

class diccionario_exception : public std::exception {
};

template<typename c, typename T, bool comp(c, c)>
class diccionario {
private:
    // comp es la función de comparación para las claves.
    // La clave debe implementar el operator==().
    nodo<c, T, comp>* raiz;
    std::size_t cantidad_datos;

    // Pre: 'nodo' es un puntero que apunta a un nodo del diccionario o nullptr.
    // 'recorrido' es un vector que establece el orden de ejecucion entre raiz, hijo izquierdo e hijo derecho.
    // Post: Retorna un vector con los elementos en el orden de 'recorrido'.
    std::vector<T> recorridos_recursivos(std::vector<T> lista, nodo<c, T, comp>* nodo, std::vector<int> recorrido);

    // Pre: 'nodo' es un puntero que apunta a un nodo del diccionario o nullptr.
    // Post: Elimina todos los nodos en el subarbol de 'nodo'.
    void baja_postorder_recursivo(nodo<c, T, comp>* nodo);

    // Pre: Nodo no debe ser nulo.
    // Post: Se aplica la función 'funcion' a cada elemento en orden.
    void ejecutar_recursivo(nodo<c, T, comp>* nodo, void (*funcion)(T));

public:
    // constructor
    diccionario();

    // Pre: 'clave' no debe existir ya en el diccionario.
    // Post: Se agrega el nuevo elemento con la clave y dato proporcionados.
    void alta(c clave, T dato);

    // Pre: 'clave' debe existir en el diccionario.
    // Post: Se elimina el elemento con la clave proporcionada.
    void baja(c clave);

    // Pre: 'clave' debe existir en el diccionario.
    // Post: Retorna el dato asociado a la clave proporcionada.
    T& operator[](c clave);

    // Pre: -
    // Post: Retorna un vector con los elementos en orden inorder.
    std::vector<T> inorder();

    // Pre: -
    // Post: Retorna un vector con los elementos en orden preorder.
    std::vector<T> preorder();

    // Pre: -
    // Post: Retorna un vector con los elementos en orden postorder.
    std::vector<T> postorder();

    // Pre: -
    // Post: Retorna un vector con los elementos en orden de ancho.
    std::vector<T> ancho();

    // Pre: -
    // Post: Aplica la función proporcionada a cada elemento del diccionario en orden inorder.
    void ejecutar(void funcion(T));

    // Pre: -
    // Post: Retorna el número de elementos en el diccionario.
    std::size_t tamanio();

    // Pre: -
    // Post: Retorna true si el diccionario está vacío, false en caso contrario.
    bool vacio();

    // Pre: -
    // Post: Retorna true si la clave está en el diccionario
    bool esta_en_diccionario(c clave_busqueda);

    diccionario(const diccionario& abb) = delete;
    void operator=(const diccionario& abb) = delete;

    ~diccionario();
};

template<typename c, typename T, bool comp(c, c)>
diccionario<c, T, comp>::diccionario() {
    raiz = nullptr;
    cantidad_datos = 0;
}

template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::alta(c clave, T dato) {
    nodo<c, T, comp>* actual = raiz;
    nodo<c, T, comp>* padre = nullptr;
    bool izquierdo = false;

    while (actual) {
        padre = actual;
        if (comp(clave, actual->clave)) {
            actual = actual->hijo_izquierdo;
            izquierdo = true;
        } else if (comp(actual->clave, clave)) {
            actual = actual->hijo_derecho;
            izquierdo = false;
        } else {
            throw diccionario_exception();
        }
    }

    nodo<c, T, comp>* nuevo_nodo = new nodo<c, T, comp>(clave, dato, padre, nullptr, nullptr);

    if (!raiz) {
        raiz = nuevo_nodo;
    } else {
        if (izquierdo) {
            padre->hijo_izquierdo = nuevo_nodo;
        } else {
            padre->hijo_derecho = nuevo_nodo;
        }
    }
    cantidad_datos++;
}

template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::baja(c clave) {
    nodo<c, T, comp>* actual = raiz;
    nodo<c, T, comp>* padre = nullptr;
    nodo<c, T, comp>* a_borrar = nullptr;
    bool izquierdo = false;

    while (actual && !a_borrar) {
        if (comp(clave, actual->clave)) {
            padre = actual;
            actual = actual->hijo_izquierdo;
            izquierdo = true;
        } else if (comp(actual->clave, clave)) {
            padre = actual;
            actual = actual->hijo_derecho;
            izquierdo = false;
        } else {
            a_borrar = actual;
        }
    }

    if (!a_borrar) {
        return;
    }

    if (!a_borrar->hijo_izquierdo && !a_borrar->hijo_derecho) {
        if (!padre) {
            delete a_borrar;
            raiz = nullptr;
        } else {
            if (izquierdo) {
                padre->hijo_izquierdo = nullptr;
            } else {
                padre->hijo_derecho = nullptr;
            }
            delete a_borrar;
        }
    } else if (!a_borrar->hijo_izquierdo || !a_borrar->hijo_derecho) {
        nodo<c, T, comp>* hijo;
        if (a_borrar->hijo_izquierdo) {
            hijo = a_borrar->hijo_izquierdo;
        } else {
            hijo = a_borrar->hijo_derecho;
        }
        if (!padre) {
            raiz = hijo;
        } else {
            if (izquierdo) {
                padre->hijo_izquierdo = hijo;
            } else {
                padre->hijo_derecho = hijo;
            }
        }
        delete a_borrar;
    } else {
        nodo<c, T, comp>* sucesor = a_borrar->hijo_derecho;
        padre = nullptr;
        while (sucesor->hijo_izquierdo) {
            padre = sucesor;
            sucesor = sucesor->hijo_izquierdo;
        }

        a_borrar->clave = sucesor->clave;
        a_borrar->dato = sucesor->dato;

        if (!padre) {
            a_borrar->hijo_derecho = sucesor->hijo_derecho;
        } else {
            padre->hijo_izquierdo = sucesor->hijo_derecho;
        }
        delete sucesor;
    }
    cantidad_datos--;
}

template<typename c, typename T, bool comp(c, c)>
T& diccionario<c, T, comp>::operator[](c clave) {
    nodo<c, T, comp>* actual = raiz;

    while (actual) {
        if (comp(clave, actual->clave)) {
            actual = actual->hijo_izquierdo;
        } else if (comp(actual->clave, clave)) {
            actual = actual->hijo_derecho;
        } else {
            return actual->dato;
        }
    }
    throw diccionario_exception();
}

template<typename c, typename T, bool comp(c, c)>
std::vector<T> diccionario<c, T, comp>::recorridos_recursivos(std::vector<T> lista, nodo<c, T, comp>* nodo, std::vector<int> recorrido) {
    if (nodo) {
        for (size_t i = 0; i < 3; i++) {
            switch (recorrido[i]) {
                case RAIZ:
                    lista.push_back(nodo->dato);
                    break;

                case NODO_IZQUIERDO:
                    lista = recorridos_recursivos(lista, nodo->hijo_izquierdo, recorrido);
                    break;

                case NODO_DERECHO:
                    lista = recorridos_recursivos(lista, nodo->hijo_derecho, recorrido);
                    break;
            }
        }
    }
    return lista;
}

template<typename c, typename T, bool comp(c, c)>
std::vector<T> diccionario<c, T, comp>::inorder() {
    std::vector<T> lista_inorder;
    return recorridos_recursivos(lista_inorder, raiz, INORDER);
}

template<typename c, typename T, bool comp(c, c)>
std::vector<T> diccionario<c, T, comp>::preorder() {
    std::vector<T> lista_preorder;
    return recorridos_recursivos(lista_preorder, raiz, PREORDER);
}

template<typename c, typename T, bool comp(c, c)>
std::vector<T> diccionario<c, T, comp>::postorder() {
    std::vector<T> lista_postorder;
    return recorridos_recursivos(lista_postorder, raiz, POSTORDER);
}

template<typename c, typename T, bool comp(c, c)>
std::vector<T> diccionario<c, T, comp>::ancho() {
    std::vector<T> resultado;

    if (!raiz) {
        return resultado;
    }

    std::queue<nodo<c, T, comp>*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        nodo<c, T, comp>* actual = cola.front();
        cola.pop();
        resultado.push_back(actual->dato);
        if (actual->hijo_izquierdo) {
            cola.push(actual->hijo_izquierdo);
        }
        if (actual->hijo_derecho) {
            cola.push(actual->hijo_derecho);
        }
    }
    return resultado;
}

template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::ejecutar(void (*funcion)(T)) {
    ejecutar_recursivo(raiz, funcion);
}

template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::ejecutar_recursivo(nodo<c, T, comp>* nodo, void (*funcion)(T)) {
    if (nodo) {
        funcion(nodo->dato);
        ejecutar_recursivo(nodo->hijo_izquierdo, funcion);
        ejecutar_recursivo(nodo->hijo_derecho, funcion);
    }
}

template<typename c, typename T, bool comp(c, c)>
std::size_t diccionario<c, T, comp>::tamanio() {
    return cantidad_datos;
}

template<typename c, typename T, bool comp(c, c)>
bool diccionario<c, T, comp>::vacio() {
    return raiz == nullptr;
}

template<typename c, typename T, bool comp(c, c)>
bool diccionario<c, T, comp>::esta_en_diccionario(c clave_busqueda) {
    nodo<c, T, comp>* actual = raiz;

    while (actual) {
        if (comp(clave_busqueda, actual->clave)) {
            actual = actual->hijo_izquierdo;
        } else if (comp(actual->clave, clave_busqueda)) {
            actual = actual->hijo_derecho;
        } else {
            return true;
        }
    }
    return false;
}

template<typename c, typename T, bool comp(c, c)>
diccionario<c, T, comp>::~diccionario() {
    baja_postorder_recursivo(raiz);
}

template<typename c, typename T, bool comp(c, c)>
void diccionario<c, T, comp>::baja_postorder_recursivo(nodo<c, T, comp>* nodo) {
    if (nodo) {
        baja_postorder_recursivo(nodo->hijo_izquierdo);
        baja_postorder_recursivo(nodo->hijo_derecho);
        delete nodo;
    }
}

#endif //AYED_TPG_1C2024_DICCIONARIO_HPP