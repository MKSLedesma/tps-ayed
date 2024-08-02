/* Trabajos e implementaciones realizadas por Mauricio Laganga y Elias Cuba. Colaboracion de Cristian Ledesma.*/

#ifndef AYED_TPG_1C2024_JUEGO_PRINCIPAL_HPP
#define AYED_TPG_1C2024_JUEGO_PRINCIPAL_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <ctime>
#include "pedido.hpp"
#include "a_estrella.hpp"
#include "heap.hpp"
#include "tablero.hpp"
#include "diccionario.hpp"
#include "grafo.hpp"

const int GENERAR_LOCAL = 1;
const int GENERAR_CAMINO_MINIMO = 2;
const int GENERAR_PEDIDO = 3;
const int BUSCAR_LOCAL = 4;
const int IMPRIMIR_MAPA = 5;
const int SALIR = 6;
const std::vector<std::string> NOMBRES = {
        "ARCO DE LA DIOSA",
        "CÍRCULO DE LA NOCHE",
        "SENDERO DE LAS ESTRELLAS",
        "REINA DE LA TORMENTA",
        "LAMENTO DE LAS ALMAS",
        "NOCTURNA DE LA LANZA",
        "VIGILIA DEL ALMA",
        "CANTO DEL VIENTO",
        "CRUZ DE LA ESPADA",
        "MURMULLO DEL BOSQUE"
};

class JuegoPrincipal {
private:

    grafo grafo_principal; 
    static bool comparar_diccionario(std::string clave1, std::string clave2);
    static bool comparar_heap(Pedido pedido1, Pedido pedido2);

    diccionario<std::string, Local, comparar_diccionario> locales;
    heap<Pedido, comparar_heap> pedidos;
    Tablero tablero;
    a_estrella algoritmo;

    // Pre: Recibe una pila de coordenadas
    // Post: Modifica el tipo de los casilleros correspondientes a las coordenadas en pila_coordenadas en el tablero
    void cambiar_tipo_coordenadas(std::stack<coordenada> pila_coordenadas, Casillero tipo);

public:
    // Constructor
    JuegoPrincipal();

    // Pre: -
    // Post: Imprime el menú correspondiente a esta clase
    void imprimir_menu_juego_principal();

    // Pre: -
    // Post: Se genera un local aleatorio, se añade a locales y al tablero
    void generar_local();

    // Pre: -
    // Post: Se generan coordenadas aleatorias para los clientes y se añaden al tablero
    void generar_clientes();

    // Pre: -
    // Post: Imprime una copia del tablero que muestra el camino mínimo entre local_origen y local_destino
    void generar_camino_minimo(Local local_origen, Local local_destino);

    // Pre: -
    // Post: Genera un pedido personalizado, lo muestra por pantalla y lo añade a pedidos
    void generar_pedido();

    // Pre: -
    // Post: Muestra por pantalla el tablero con clientes y locales
    void imprimir_mapa();

    // Pre: -
    // Post: Controla la lógica del juego principal
    void jugar();
    // Pre: -
    // Post: Devuelve una referencia al grafo principal del juego.
    grafo& obtener_grafo() {
        return grafo_principal;
    }
};

JuegoPrincipal::JuegoPrincipal() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

bool JuegoPrincipal::comparar_diccionario(std::string clave1, std::string clave2) {
    return clave1 < clave2;
}

bool JuegoPrincipal::comparar_heap(Pedido pedido1, Pedido pedido2) {
    return pedido1.obtener_prioridad() > pedido2.obtener_prioridad();
}

void JuegoPrincipal::imprimir_menu_juego_principal() {
    std::cout << GENERAR_LOCAL << ". Generar Local\n";
    std::cout << GENERAR_CAMINO_MINIMO << ". Generar Camino Minimo\n";
    std::cout << GENERAR_PEDIDO << ". Generar Pedido\n";
    std::cout << BUSCAR_LOCAL << ". Buscar Local\n";
    std::cout << IMPRIMIR_MAPA << ". Imprimir Mapa\n";
    std::cout << SALIR << ". Salir\n";
}

void JuegoPrincipal::generar_local() {
    std::vector<int> prioridades(NOMBRES.size());
    for (size_t i = 0; i < NOMBRES.size(); ++i) {
        prioridades[i] = rand() % 100 + 1;
    }

    size_t indice = (size_t)rand() % NOMBRES.size();
    std::string nombre_local = NOMBRES[indice];
    int prioridad = prioridades[indice];

    size_t x, y;
    do {
        x = (size_t) rand() % FILAS_CALLEJON;
        y = (size_t) rand() % COLUMNAS_CALLEJON;
    } while (tablero.tipo_elemento(x, y) != Casillero::DISPONIBLE);

    Local nuevo_local(nombre_local, prioridad, x, y);
    tablero.marcar_casillero(x, y, Casillero::LOCAL);

    try {
        locales.alta(nombre_local, nuevo_local);
        std::cout << "Local generado: " << nombre_local << " - Prioridad: " << prioridad << "\n";
        grafo_principal.agregar_vertice();
    } catch (const diccionario_exception& e) {
        std::cerr << "Error al insertar local en el diccionario.\n";
    }

    std::vector<Local> locales_en_orden = locales.inorder();
    std::cout << "Locales actuales:\n";
    for (const auto& local : locales_en_orden) {
        std::cout << local.obtener_nombre() << " - Prioridad: " << local.obtener_prioridad() << "\n";
    }
}

void JuegoPrincipal::generar_clientes() {
    size_t cantidad_clientes = (size_t) rand() % CANTIDAD_MAXIMA_CLIENTES;
    for (size_t i = 0; i < cantidad_clientes; i++) {
        size_t x, y;
        do {
            x = (size_t) rand() % FILAS_CALLEJON;
            y = (size_t) rand() % COLUMNAS_CALLEJON;
        } while (tablero.tipo_elemento(x, y) != Casillero::DISPONIBLE);
        tablero.marcar_casillero(x, y, Casillero::CLIENTE);
    }
}

void JuegoPrincipal::cambiar_tipo_coordenadas(std::stack<coordenada> pila_coordenadas, Casillero tipo) {
    while (!pila_coordenadas.empty()) {
        tablero.marcar_casillero((size_t)pila_coordenadas.top().x(), (size_t)pila_coordenadas.top().y(), tipo);
        pila_coordenadas.pop();
    }
}

void JuegoPrincipal::generar_camino_minimo(Local local_origen, Local local_destino) {
    coordenada coordenada_local1 = local_origen.obtener_coordenada();
    coordenada coordenada_local2 = local_destino.obtener_coordenada();
    mapa mapa_callejon(tablero);

    std::stack<coordenada> camino_minimo = algoritmo.obtener_camino_minimo(coordenada_local1, coordenada_local2,
                                                                            mapa_callejon, algoritmo.heuristica_manhattan);
    if (camino_minimo.empty()) {
        std::cout << "No existe camino desde " << local_origen.obtener_nombre() << " hasta " << local_destino.obtener_nombre() << "\n";
    } else {
        cambiar_tipo_coordenadas(camino_minimo, Casillero::CAMINO);
        tablero.marcar_casillero(static_cast<size_t>(local_origen.obtener_coordenada().x()),
                                 static_cast<size_t>(local_origen.obtener_coordenada().y()), Casillero::LOCAL_ORIGEN);
        tablero.marcar_casillero(static_cast<size_t>(local_destino.obtener_coordenada().x()),
                                 static_cast<size_t>(local_destino.obtener_coordenada().y()), Casillero::LOCAL_DESTINO);
        tablero.imprimir_tablero();
        cambiar_tipo_coordenadas(camino_minimo, Casillero::DISPONIBLE);
        tablero.marcar_casillero(static_cast<size_t>(local_origen.obtener_coordenada().x()),
                                 static_cast<size_t>(local_origen.obtener_coordenada().y()), Casillero::LOCAL);
        tablero.marcar_casillero(static_cast<size_t>(local_destino.obtener_coordenada().x()),
                                 static_cast<size_t>(local_destino.obtener_coordenada().y()), Casillero::LOCAL);
    }
}

void JuegoPrincipal::generar_pedido() {
    if (locales.vacio()) {
        std::cout << "No hay locales disponibles para generar un pedido.\n";
    } else {
        std::cout << "Locales disponibles:\n";
        std::vector<Local> locales_en_orden = locales.inorder();
        for (size_t i = 0; i < locales_en_orden.size(); i++) {
            std::cout << i + 1 << ". " << locales_en_orden[i].obtener_nombre() << "\n";
        }

        size_t indice_origen, indice_destino;
        int peso;
        std::cout << "Seleccione el índice del local de origen: ";
        std::cin >> indice_origen; indice_origen--;
        std::cout << "Seleccione el índice del local de destino: ";
        std::cin >> indice_destino; indice_destino--;
        std::cout << "Ingrese el peso del paquete: ";
        std::cin >> peso;

        if (indice_origen < locales_en_orden.size() && indice_destino < locales_en_orden.size()) {
            Pedido pedido(locales_en_orden[indice_origen], locales_en_orden[indice_destino], peso);
            pedidos.alta(pedido);
            std::cout << "Se generó un pedido desde " << locales_en_orden[indice_origen].obtener_nombre()
                      << " a " << locales_en_orden[indice_destino].obtener_nombre() << " con peso " << peso << "\n";
            grafo_principal.incrementar_contador_pedidos(indice_origen, indice_destino);
        } else {
            std::cout << "Índices de locales no válidos.\n";
        }
    }
}


void JuegoPrincipal::imprimir_mapa() {
    tablero.imprimir_tablero();
}

void JuegoPrincipal::jugar() {
    bool jugando = true;
    std::string nombre_local;
    generar_clientes();
    while (jugando) {
        imprimir_menu_juego_principal();
        int opcion;
        std::cin >> opcion;
        switch (opcion) {
            case GENERAR_LOCAL:
                generar_local();
                break;
            case GENERAR_CAMINO_MINIMO:
                if (locales.tamanio() < 2) {
                    std::cout << "Se requieren al menos dos locales para generar un camino mínimo.\n";
                } else if (pedidos.vacio()) {
                    std::cout << "No hay pedidos disponibles para generar el camino mínimo.\n";
                } else {
                    Pedido pedido_prioritario = pedidos.baja();
                    generar_camino_minimo(pedido_prioritario.obtener_origen(), pedido_prioritario.obtener_destino());
                }
                break;
            case GENERAR_PEDIDO:
                generar_pedido();
                break;
            case BUSCAR_LOCAL:
                std::cout << "Ingrese el nombre del local: ";
                std::cin.ignore();
                std::getline(std::cin, nombre_local);

                for (char& c : nombre_local) {
                    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
                }

                if (locales.esta_en_diccionario(nombre_local)) {
                    std::cout << "Prioridad: " << locales[nombre_local].obtener_prioridad() << "\n";
                    std::cout << "Coordenada: (" << locales[nombre_local].obtener_coordenada().x() << ";" << locales[nombre_local].obtener_coordenada().y() << ")\n\n";
                } else {
                    std::cout << "No se encuentra dicho local";
                }
                break;
            case IMPRIMIR_MAPA:
                imprimir_mapa();
                break;
            case SALIR:
                jugando = false;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    }
}

#endif //AYED_TPG_1C2024_JUEGO_PRINCIPAL_HPP
