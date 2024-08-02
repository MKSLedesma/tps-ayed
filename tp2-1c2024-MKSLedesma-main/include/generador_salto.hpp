#ifndef AYED_TP2_1C2024_GENERADOR_SALTO_HPP
#define AYED_TP2_1C2024_GENERADOR_SALTO_HPP

#include "salto.hpp"
#include <vector>

class generador_salto {
private:
    enum elementos {
        VIENTO = 0,
        FUEGO = 1,
        ELECTRICO = 2,
        CUANTICO = 3,
        FISICO = 4,
        IMAGINARIO = 5,
        HIELO = 6,
        SIN_ELEMENTO = 7
    };

    enum vias {
        NIHILIDAD = 0,
        DESTRUCCION = 1,
        ABUNDANCIA = 2,
        ERUDICION = 3,
        CACERIA = 4,
        CONSERVACION = 5,
        ARMONIA = 6
    };

    enum tipos {
        PERSONAJE = 0,
        CONO_DE_LUZ = 1
    };

    static const std::vector<recompensa> RECOMPENSAS_CINCO_ESTRELLAS;
    static const std::vector<recompensa> RECOMPENSAS_CUATRO_ESTRELLAS;
    static const std::vector<recompensa> RECOMPENSAS_TRES_ESTRELLAS;

    // Pre: Recompensas no puede estar vacío.
    // Post: Devuelve una recompensa_obtenida elegida al azar.
    static recompensa elegir_recompensa_aleatoria(std::vector<recompensa> recompensas);

public:
    // Pre: -
    // Post: Genera y devuelve un salto_simple aleatorio de 5 estrellas.
    static salto generar_salto_5_estrellas();

    // Pre: -
    // Post: Genera y devuelve un salto_simple aleatorio de 4 estrellas.
    static salto generar_salto_4_estrellas();

    // Pre: -
    // Post: Genera y devuelve un salto_simple aleatorio de 3 estrellas.
    static salto generar_salto_3_estrellas();
};

#endif