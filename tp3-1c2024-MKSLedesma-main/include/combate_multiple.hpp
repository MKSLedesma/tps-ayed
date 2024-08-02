#ifndef AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#define AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#include "combate.hpp"
#include "cola.hpp"
#include <iostream>

class combate_multiple {
private:
    cola<combate> combates;
    size_t cantidad_combates;

public:
    //Constructor
    combate_multiple();

    //Pre: Los combates agregados no pueden ser mayores a 6.
    //Post: Agrega el combate actual a combates.
    void agregar_combate(combate combate_a_agregar);

    //Pre:
    //Post: Resuelve todos los combates agregados a combates y devuelve el total de Poder de Trazacaminos gastado.
    //Recursividad: No de cola, directa y simple.
    size_t pelear();

};

#endif