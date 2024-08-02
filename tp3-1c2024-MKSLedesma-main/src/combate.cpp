#include "combate.hpp"

#include <utility>

combate::combate(std::string descripcion, size_t cantidad_enemigos, size_t poder_trazacaminos_gastado) {
    this->descripcion = std::move(descripcion);
    this->cantidad_enemigos = cantidad_enemigos;
    this->poder_trazacaminos_gastado = poder_trazacaminos_gastado;
}

std::ostream& operator<<(std::ostream& os, const combate& combate1) {
    os << "Descripcion: " << combate1.descripcion << "\n"
       << "Cantidad de enemigos: " << combate1.cantidad_enemigos << "\n"
       << "Poder de Trazacaminos gastado: " << combate1.poder_trazacaminos_gastado << "\n";
    return os;
}

size_t combate::obtener_poder_gastado() {
    return poder_trazacaminos_gastado;
}