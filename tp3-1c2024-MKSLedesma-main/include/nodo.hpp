#ifndef AYED_TP3_1C2024_NODO_HPP
#define AYED_TP3_1C2024_NODO_HPP

template<typename T>
class cola;

template<typename T>
class lista_circular;

template<typename T>
class nodo {
private:
    T dato;
    nodo<T>* anterior;
    nodo<T>* siguiente;
public:
    // Constructores.
    nodo(T dato);

    nodo(T dato, nodo<T>* anterior, nodo<T>* siguiente);

    // Esto permite acceder directamente a los atributos del nodo.
    friend class cola<T>;

    friend class lista_circular<T>;
};

template<typename T>
nodo<T>::nodo(T dato) {
    this->dato = dato;
    anterior = nullptr;
    siguiente = nullptr;
}

template<typename T>
nodo<T>::nodo(T dato, nodo<T>* anterior, nodo<T>* siguiente) {
    this->dato = dato;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

#endif