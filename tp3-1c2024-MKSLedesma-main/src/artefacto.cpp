#include "artefacto.hpp"

#include <utility>

artefacto::artefacto(int id, std::string set, tipo tipo1, size_t nivel, rareza rareza1) {
    this->id = id;
    this->set = std::move(set);
    this->tipo1 = tipo1;
    this->nivel = nivel;
    this->rareza1 = rareza1;
}

std::ostream& operator<<(std::ostream& os, const artefacto& artefacto1) {
    os << artefacto1.id << ","
       << artefacto1.set << ","
       << artefacto1.tipo1 << ","
       << artefacto1.nivel << ","
       << artefacto1.rareza1;
    return os;
}

bool artefacto::operator==(const artefacto& artefacto1) const {
    return id == artefacto1.id;
}

tipo artefacto::string_a_tipo(const std::string &tipo_str) {
    if (tipo_str == "1") {
        return CABEZA;
    } else if (tipo_str == "2") {
        return MANOS;
    } else if (tipo_str == "3") {
        return TORSO;
    } else if (tipo_str == "4") {
        return PIERNAS;
    } else if (tipo_str == "5") {
        return ESFERA_PLANAR;
    } else if (tipo_str == "6") {
        return PISTA_DE_LUZ;
    } else {
        // Manejar un tipo no válido
        throw std::invalid_argument("Tipo no válido");
    }
}

rareza artefacto::string_a_rareza(const std::string &rareza_str) {
    if (rareza_str == "3") {
        return TRES_ESTRELLAS;
    } else if (rareza_str == "4") {
        return CUATRO_ESTRELLAS;
    } else if (rareza_str == "5") {
        return CINCO_ESTRELLAS;
    } else {
        throw std::invalid_argument("Rareza no válida");
    }
}