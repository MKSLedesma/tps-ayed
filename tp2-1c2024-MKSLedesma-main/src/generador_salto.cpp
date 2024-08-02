#include "generador_salto.hpp"
#include <random>

const std::vector<recompensa> generador_salto::RECOMPENSAS_CINCO_ESTRELLAS = {
        {"Black Swan",                 PERSONAJE, VIENTO,     NIHILIDAD},
        {"Sparkle",                    PERSONAJE, CUANTICO,   ARMONIA},
        {"Argenti",                    PERSONAJE, FISICO,     ERUDICION},
        {"Bailu",                      PERSONAJE, ELECTRICO,  ABUNDANCIA},
        {"Blade",                      PERSONAJE, VIENTO,     DESTRUCCION},
        {"Bronya",                     PERSONAJE, VIENTO,     ARMONIA},
        {"Clara",                      PERSONAJE, FISICO,     DESTRUCCION},
        {"Dan Heng - Imbibitor Lunae", PERSONAJE, IMAGINARIO, DESTRUCCION},
        {"Dr. Ratio",                  PERSONAJE, IMAGINARIO, CACERIA},
        {"Fu Xuan",                    PERSONAJE, CUANTICO,   CONSERVACION},
        {"Gepard",                     PERSONAJE, HIELO,      CONSERVACION},
        {"Himeko",                     PERSONAJE, FUEGO,      ERUDICION},
        {"Huohuo",                     PERSONAJE, VIENTO,     ABUNDANCIA},
        {"Jing Yuan",                  PERSONAJE, ELECTRICO,  ERUDICION},
        {"Jingliu",                    PERSONAJE, HIELO,      DESTRUCCION},
        {"Kafka",                      PERSONAJE, ELECTRICO,  NIHILIDAD},
        {"Luocha",                     PERSONAJE, IMAGINARIO, ABUNDANCIA},
        {"Ruan Mei",                   PERSONAJE, HIELO,      ARMONIA},
        {"Seele",                      PERSONAJE, CUANTICO,   CACERIA},
        {"Silver Wolf",                PERSONAJE, CUANTICO,   NIHILIDAD},
        {"Topaz & Numby",              PERSONAJE, FUEGO,      CACERIA},
        {"Welt",                       PERSONAJE, IMAGINARIO, NIHILIDAD},
        {"Yanqing",                    PERSONAJE, HIELO,      CACERIA},
};

const std::vector<recompensa> generador_salto::RECOMPENSAS_CUATRO_ESTRELLAS = {
        {"Misha",     PERSONAJE, HIELO,      DESTRUCCION},
        {"Arlan",     PERSONAJE, ELECTRICO,  DESTRUCCION},
        {"Asta",      PERSONAJE, FUEGO,      ARMONIA},
        {"Dan Heng",  PERSONAJE, VIENTO,     CACERIA},
        {"Guinaifen", PERSONAJE, FUEGO,      NIHILIDAD},
        {"Hanya",     PERSONAJE, FISICO,     ARMONIA},
        {"Herta",     PERSONAJE, HIELO,      ERUDICION},
        {"Hook",      PERSONAJE, FUEGO,      DESTRUCCION},
        {"Luka",      PERSONAJE, FISICO,     NIHILIDAD},
        {"Lynx",      PERSONAJE, CUANTICO,   ABUNDANCIA},
        {"March 7th", PERSONAJE, HIELO,      CONSERVACION},
        {"Natasha",   PERSONAJE, FISICO,     ABUNDANCIA},
        {"Pela",      PERSONAJE, HIELO,      NIHILIDAD},
        {"Qingque",   PERSONAJE, CUANTICO,   ERUDICION},
        {"Sampo",     PERSONAJE, VIENTO,     NIHILIDAD},
        {"Serval",    PERSONAJE, ELECTRICO,  ERUDICION},
        {"Sushang",   PERSONAJE, FISICO,     CACERIA},
        {"Tingyun",   PERSONAJE, ELECTRICO,  ARMONIA},
        {"Xueyi",     PERSONAJE, CUANTICO,   DESTRUCCION},
        {"Yukong",    PERSONAJE, IMAGINARIO, ARMONIA},
};

const std::vector<recompensa> generador_salto::RECOMPENSAS_TRES_ESTRELLAS = {
        {"Antagonista",      CONO_DE_LUZ, SIN_ELEMENTO, CACERIA},
        {"Archivos",         CONO_DE_LUZ, SIN_ELEMENTO, ERUDICION},
        {"Blindaje",         CONO_DE_LUZ, SIN_ELEMENTO, CONSERVACION},
        {"Bucle",            CONO_DE_LUZ, SIN_ELEMENTO, NIHILIDAD},
        {"Colapso celeste",  CONO_DE_LUZ, SIN_ELEMENTO, DESTRUCCION},
        {"Colonizacion",     CONO_DE_LUZ, SIN_ELEMENTO, CONSERVACION},
        {"Cornucopia",       CONO_DE_LUZ, SIN_ELEMENTO, ABUNDANCIA},
        {"Coro",             CONO_DE_LUZ, SIN_ELEMENTO, ARMONIA},
        {"Final mutuo",      CONO_DE_LUZ, SIN_ELEMENTO, DESTRUCCION},
        {"Flecha voladora",  CONO_DE_LUZ, SIN_ELEMENTO, CACERIA},
        {"Flechas",          CONO_DE_LUZ, SIN_ELEMENTO, CACERIA},
        {"Fruto excelente",  CONO_DE_LUZ, SIN_ELEMENTO, ABUNDANCIA},
        {"Hogar destrozado", CONO_DE_LUZ, SIN_ELEMENTO, DESTRUCCION},
        {"Llave maestra",    CONO_DE_LUZ, SIN_ELEMENTO, ERUDICION},
        {"Mediacion",        CONO_DE_LUZ, SIN_ELEMENTO, ARMONIA},
        {"Multiplicacion",   CONO_DE_LUZ, SIN_ELEMENTO, ABUNDANCIA},
        {"Rueda mecanica",   CONO_DE_LUZ, SIN_ELEMENTO, ARMONIA},
        {"Sagacidad",        CONO_DE_LUZ, SIN_ELEMENTO, ERUDICION},
        {"Sombra oculta",    CONO_DE_LUZ, SIN_ELEMENTO, NIHILIDAD},
        {"Vacio",            CONO_DE_LUZ, SIN_ELEMENTO, NIHILIDAD},
        {"Ambar",            CONO_DE_LUZ, SIN_ELEMENTO, CONSERVACION},
};

recompensa generador_salto::elegir_recompensa_aleatoria(std::vector<recompensa> recompensas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, (int) recompensas.size() - 1);
    return recompensas[(size_t) dist(gen)];
}

salto generador_salto::generar_salto_5_estrellas() {
    return {CINCO_ESTRELLAS, elegir_recompensa_aleatoria(RECOMPENSAS_CINCO_ESTRELLAS)};
}

salto generador_salto::generar_salto_4_estrellas() {
    return {CUATRO_ESTRELLAS, elegir_recompensa_aleatoria(RECOMPENSAS_CUATRO_ESTRELLAS)};
}

salto generador_salto::generar_salto_3_estrellas() {
    return {TRES_ESTRELLAS, elegir_recompensa_aleatoria(RECOMPENSAS_TRES_ESTRELLAS)};
}