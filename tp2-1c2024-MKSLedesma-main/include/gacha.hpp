#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "salto.hpp"
#include "vector.hpp"

class gacha {
private:
    int contador_saltos_5_estrellas;
    int contador_saltos_4_estrellas;
    int generar_probabilidad();
    vector<salto> saltos_generados;

public:
    gacha(int contador_saltos_5_estrellas = 0,
          int contador_saltos_4_estrellas = 0);

    salto generar_salto();

    vector<salto> generar_salto_multiple();

    vector<salto> generar_salto_multiple(size_t cantidad);

    void exportar_saltos();
};

#endif