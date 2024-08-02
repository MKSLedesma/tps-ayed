#include "mapa.hpp"

bool mapa::es_vecino_valido(coordenada posicion) {
    int tam_filas = int(map.filas());
    int tam_col = int(map.columnas());

    if (posicion.x() < 0 || posicion.x() >= tam_filas || posicion.y() < 0 || posicion.y() >= tam_col) {
        return false;
    }

    return map.elemento(static_cast<size_t>(posicion.x()), static_cast<size_t>(posicion.y())) == Casillero::DISPONIBLE
    || map.elemento(static_cast<size_t>(posicion.x()), static_cast<size_t>(posicion.y())) == Casillero::LOCAL;
}

mapa::mapa(Tablero tablero) {
    map = tablero.obtener_matriz_tablero();
}