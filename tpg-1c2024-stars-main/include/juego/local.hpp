#ifndef AYED_TPG_1C2024_LOCAL_H
#define AYED_TPG_1C2024_LOCAL_H

#include <string>
#include "coordenada.hpp"

class Local {
private:
    std::string nombre;
    int prioridad;
    coordenada coordenada1;

public:

    //constructor
    Local();
    Local(std::string nombre, int prioridad, size_t x, size_t y) :
        nombre(nombre), prioridad(prioridad), coordenada1((int)x, (int)y) {}

    //Pre: -
    //Post: Devuelve la prioridad del local
    int obtener_prioridad() const;

    //Pre: -
    //Post: Devuelve el nombre del local
    std::string obtener_nombre() const;

    //Pre: -
    //Post: Devuelve la coordenada del local
    coordenada obtener_coordenada() const;
};

Local::Local() {}

int Local::obtener_prioridad() const{
    return prioridad;
}

std::string Local::obtener_nombre() const {
    return nombre;
}

coordenada Local::obtener_coordenada() const {
    return coordenada1;
}

#endif //AYED_TPG_1C2024_LOCAL_H
