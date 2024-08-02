#ifndef AYED_TP3_1C2024_COMBATE_HPP
#define AYED_TP3_1C2024_COMBATE_HPP

#include <string>

#include <ostream>

class combate {
private:
    std::string descripcion;
    size_t cantidad_enemigos{};
    size_t poder_trazacaminos_gastado{};
public:
    combate() = default;

    combate(std::string descripcion, size_t cantidad_enemigos, size_t poder_trazacaminos_gastado);

    friend std::ostream& operator<<(std::ostream& os, const combate& combate1);

    size_t obtener_poder_gastado();

    ~combate() = default;
};

#endif