#include "combate_multiple.hpp"

combate_multiple::combate_multiple() {
    cantidad_combates = 0;
}

void combate_multiple::agregar_combate(combate combate_a_agregar)
{
    if (cantidad_combates == 6)
    {
        std::cout << "¡Ya no entran mas combates!" << std::endl;
    }

    else
    {
        combates.alta(combate_a_agregar);
        cantidad_combates++;
    }
}

size_t combate_multiple::pelear()
{
    if (combates.vacio())
    {
        return 0;
    }

    combate combate_actual = combates.primero();
    std::cout << "---------- \n";
    std::cout << combate_actual << std::endl;
    combates.baja();
    return pelear() + combate_actual.obtener_poder_gastado();
}
