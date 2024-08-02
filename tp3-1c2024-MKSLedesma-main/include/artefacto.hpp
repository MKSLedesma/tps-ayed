#ifndef AYED_TP3_1C2024_ARTEFACTO_HPP
#define AYED_TP3_1C2024_ARTEFACTO_HPP

#include <string>
#include <ostream>

enum tipo {
    CABEZA = 1,
    MANOS = 2,
    TORSO = 3,
    PIERNAS = 4,
    ESFERA_PLANAR = 5,
    PISTA_DE_LUZ = 6
};

enum rareza {
    TRES_ESTRELLAS = 3,
    CUATRO_ESTRELLAS = 4,
    CINCO_ESTRELLAS = 5
};

class artefacto {
private:
    int id{};
    std::string set;
    tipo tipo1{};
    size_t nivel{};
    rareza rareza1{};

public:
    artefacto() = default;

    artefacto(int id, std::string set, tipo tipo1, size_t nivel, rareza rareza1);

    friend std::ostream& operator<<(std::ostream& os, const artefacto& artefacto1);

    bool operator==(const artefacto& artefacto1) const;

    static tipo string_a_tipo(const std::string& tipo_str);

    static rareza string_a_rareza(const std::string& rareza_str);

    ~artefacto() = default;
};

#endif