#ifndef AYED_TPG_1C2024_HEAP_HPP
#define AYED_TPG_1C2024_HEAP_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>
#include <random>

const int CANTIDAD_EXPERIMENTOS = 100;
const std::vector<int> TAMANIOS_HEAP = {100, 1000, 10000};

class heap_exception : public std::exception {
};

template<typename T, bool comp(T, T)>
class heap {
private:
    std::vector<T> datos;

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Intercambia de lugar los datos de los indices indicados.
    void swap(size_t indice_1, size_t indice_2);

    // Pre: Ambos índices deben ser menor que la cantidad de datos.
    // Post: Realiza un "upheap" sobre los índices indicados.
    // (El dato "sube" en el heap.)
    void upheap(size_t& indice);

    // Post: El índice debe ser menor que la cantidad de datos.
    // Post: Realiza un "downheap" sobre el índice indicado.
    // (El dato "baja" en el heap, intercambiándose con el menor/mayor dato.)
    void downheap(size_t& indice);

    // Pre:
    // Post: Devuelve un numero entre 0 y 100000.
    int generar_random();

    unsigned long contador_downheap = 0;
    unsigned long contador_upheap = 0;

    // NOTA: No es necesario que lancen excepciones en estos métodos porque son privados.
    // Deberían siempre asegurar que los índices pasados por parámetros son válidos.
    // Consideren cada caso con detenimiento.
    // Adicionalmente, tengan cuidado con el casteo de las variables, porque son size_t.
    // Hacer, por ejemplo, size_t i = 0; i - 1; produce un underflow.
public:
    // Constructor.
    heap();

    // Pre: -
    // Post: Agrega el dato al heap.
    void alta(T dato);

    // Pre: El heap no puede estar vacío.
    // Post: Elimina y devuelve el primer dato.
    T baja();

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "upheaps".
    size_t alta_complejidad(T dato);

    // Método para el informe de complejidad algorítmica. Devuelve la cantidad de "downheaps".
    size_t baja_complejidad();

    // // Método para el informe de complejidad algorítmica. Imprime los promedios solicitados".
    void informar_complejidad();

    // Pre: El heap no puede estar vacío.
    // Post: Devuelve el primer dato.
    T primero();

    // Pre: -
    // Post: Devuelve true si el heap está vacío.
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos en el heap.
    size_t tamanio();

    // Destructor.
    ~heap();
};

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::heap() {
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::swap(size_t indice_1, size_t indice_2)
{
    std::swap(datos[indice_1], datos[indice_2]);
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::upheap(size_t& indice)
{
    if (indice != 0)
    {
        size_t padre = (indice - 1) / 2;
        if(comp(datos[indice], datos[padre]))
        {
            swap(indice, padre);
            contador_upheap++;
            upheap(padre);
        }
    }
}

template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::downheap(size_t& indice)
{
    size_t hijo_izquierdo = (2 * indice) + 1;
    size_t hijo_derecho = (2 * indice) + 2;
    size_t nodo = indice;
    if (hijo_izquierdo < tamanio() && comp(datos[hijo_izquierdo], datos[nodo]))
    {
        nodo = hijo_izquierdo;
    }
    if (hijo_derecho < tamanio() && comp(datos[hijo_derecho], datos[nodo]))
    {
        nodo = hijo_derecho;
    }
    if (nodo != indice)
    {
        swap(nodo, indice);
        contador_downheap++;
        downheap(nodo);
    }
}

template<typename T, bool (* comp)(T, T)>
int heap<T, comp>::generar_random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100000);
    return dis(gen);
}


template<typename T, bool (* comp)(T, T)>
void heap<T, comp>::alta(T dato)
{
    datos.push_back(dato);
    size_t indice = tamanio() - 1;
    upheap(indice);
}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::baja()
{
    if (datos.empty())
    {
        throw heap_exception();
    }

    T dato_primero = primero();
    size_t cero = 0;
    datos[0] = datos.back();
    datos.pop_back();
    if (!vacio())
    {
        downheap(cero);
    }
    return dato_primero;
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::alta_complejidad(T dato)
{
    contador_upheap = 0;
    alta(dato);
    return static_cast<size_t>(contador_upheap);
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::baja_complejidad()
{
    contador_downheap = 0;
    baja();
    return static_cast<size_t>(contador_downheap);
}

template<typename T, bool (*comp)(T, T)>
void heap<T, comp>::informar_complejidad()
{
    for (int tamanio : TAMANIOS_HEAP) {
        size_t total_upheaps = 0;
        size_t total_downheaps = 0;
        size_t mayor_upheaps = 0;
        size_t mayor_downheaps = 0;
        size_t menor_downheaps = 100;
        size_t menor_upheaps = 100;

        for (int i = 0; i < CANTIDAD_EXPERIMENTOS; i++)
        {
            heap<int, comp> heap_informe;

            for (int j = 0; j < tamanio; j++)
            {
                heap_informe.alta(generar_random());
            }
            size_t alta_informe = heap_informe.alta_complejidad(generar_random());
            total_upheaps += alta_informe;

            if (mayor_upheaps < alta_informe)
            {
                mayor_upheaps = alta_informe;
            }
            if (menor_upheaps > alta_informe)
            {
                menor_upheaps = alta_informe;
            }
        }

        for (int i = 0; i < CANTIDAD_EXPERIMENTOS; i++)
        {
            heap<int, comp> heap_informe;

            for (int j = 0; j < tamanio; j++)
            {
                heap_informe.alta(generar_random());
            }
            size_t baja_informe = heap_informe.baja_complejidad();
            total_downheaps += baja_informe;

            if (mayor_downheaps < baja_informe)
            {
                mayor_downheaps = baja_informe;
            }
            if (menor_downheaps > baja_informe)
            {
                menor_downheaps = baja_informe;
            }
        }

        double promedio_upheaps = static_cast<double>(total_upheaps) / CANTIDAD_EXPERIMENTOS;
        double promedio_downheaps = static_cast<double>(total_downheaps) / CANTIDAD_EXPERIMENTOS;

        std::cout << "Tamaño del heap: " << tamanio << std::endl;
        std::cout << "Promedio de upheap en " << CANTIDAD_EXPERIMENTOS << " altas: " << promedio_upheaps << std::endl;
        std::cout << "Total de upheaps: " << total_upheaps << std::endl;
        std::cout << "Mayor cantidad de upheaps en un alta: " << mayor_upheaps << std::endl;
        std::cout << "Menor cantidad de upheaps en una alta: " << menor_upheaps << std::endl;
        std::cout << "Promedio de downheap en " << CANTIDAD_EXPERIMENTOS << " bajas: " << promedio_downheaps << std::endl;
        std::cout << "Total de downheaps: " << total_downheaps << std::endl;
        std::cout << "Mayor cantidad de downheaps en una baja: " << mayor_downheaps << std::endl;
        std::cout << "Menor cantidad de downheaps en una baja: " << menor_downheaps << std::endl;
        std::cout << std::endl;
    }
}

template<typename T, bool (* comp)(T, T)>
T heap<T, comp>::primero()
{
    if (datos.empty())
    {
        throw heap_exception();
    }

    return datos.front();
}

template<typename T, bool (* comp)(T, T)>
bool heap<T, comp>::vacio()
{
    return datos.empty();
}

template<typename T, bool (* comp)(T, T)>
size_t heap<T, comp>::tamanio()
{
    return datos.size();
}

template<typename T, bool (* comp)(T, T)>
heap<T, comp>::~heap() {
    while (!vacio())
    {
        baja();
    }
}

#endif