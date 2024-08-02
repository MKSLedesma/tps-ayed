#include "recompensa.hpp"
#include <ostream>

const std::string recompensa::ELEMENTOS[8] = {"Viento",
                                              "Fuego",
                                              "Electrico",
                                              "Cuantico",
                                              "Fisico",
                                              "Imaginario",
                                              "Hielo",
                                              "N/A"};

const std::string recompensa::VIAS[7] = {"Nihilidad",
                                         "Destruccion",
                                         "Abundancia",
                                         "Erudicion",
                                         "Caceria",
                                         "Conservacion",
                                         "Armonia"};

const std::string recompensa::TIPOS[2] = {"Personaje",
                                          "Cono de Luz"};

recompensa::recompensa(std::string nombre, int tipo, int elemento, int via) {
    this->nombre = std::move(nombre);
    this->tipo = tipo;
    this->elemento = elemento;
    this->via = via;
}

std::ostream& operator<<(std::ostream& os, const recompensa& recompensa) {
    os << recompensa.nombre << ','
       << recompensa::TIPOS[recompensa.tipo] << ','
       << recompensa::ELEMENTOS[recompensa.elemento] << ','
       << recompensa::VIAS[recompensa.via];
    return os;
}