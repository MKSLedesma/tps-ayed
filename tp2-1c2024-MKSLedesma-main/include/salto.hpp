#ifndef AYED_TP2_1C2024_SALTO_HPP
#define AYED_TP2_1C2024_SALTO_HPP

#include "recompensa.hpp"
#include <ctime>

enum rareza {
    CINCO_ESTRELLAS = 5, CUATRO_ESTRELLAS = 4, TRES_ESTRELLAS = 3
};

class salto {
private:
    time_t hora_obtencion{};
    rareza rareza_obtenida{};
    recompensa recompensa_obtenida;
public:
    // Constructor default.
    salto() = default;

    // Constructor.
    salto(rareza rareza, recompensa recompensa);

    // Pre: -
    // Post: Devuelve la rareza_obtenida del salto_simple.
    rareza obtener_rareza();

    // Pre: -
    // Post: Carga la información al stream de salida.
    friend std::ostream& operator<<(std::ostream& os, const salto& salto);
};

#endif