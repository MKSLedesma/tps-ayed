#include "salto.hpp"
#include <chrono>
#include <ostream>

salto::salto(rareza rareza, recompensa recompensa) {
    auto hora_actual = std::chrono::system_clock::now();
    this->hora_obtencion = std::chrono::system_clock::to_time_t(hora_actual);
    this->rareza_obtenida = rareza;
    this->recompensa_obtenida = std::move(recompensa);
}

rareza salto::obtener_rareza() {
    return rareza_obtenida;
}

std::ostream& operator<<(std::ostream& os, const salto& salto) {
    std::string hora = std::ctime(&salto.hora_obtencion);
    hora.pop_back();
    os << hora << ','
       << salto.rareza_obtenida << " Estrellas,"
       << salto.recompensa_obtenida;
    return os;
}