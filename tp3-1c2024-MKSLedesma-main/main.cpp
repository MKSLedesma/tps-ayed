#include "armamento_artefactos.hpp"
#include "combate_multiple.hpp"
#include <iostream>
const int OPCION_SALIR = 0;
const int OPCION_ARMAMENTOS = 1;
const int OPCION_COMBATES = 2;

int main() {
    int opcion;

    std::cout << "Bienvenido a Honkai Star Rail \n";
    std::cout << "¿Que seccion deseas visitar? \n";
    std::cout << "[1] Armamentos \n[2] Combates \n";
    std::cin >> opcion;

    if (opcion == OPCION_ARMAMENTOS)
    {
        std::cout << "[1] Importar armamento \n[2] Crear armamento \n";
        std::cin >> opcion;
        if (opcion == 1)
        {
            std::string ruta_armamento;
            std::cout << "Ingresa la ruta del armamento a importar: ";
            std::cin >> ruta_armamento;
            armamento_artefactos armamento_exportado(ruta_armamento);
            armamento_exportado.mostrar_artefactos();
        }
        else if (opcion == 2)
        {
            armamento_artefactos armamento1;
            armamento1.establecer_uuid();
            while (opcion != OPCION_SALIR)
            {
                std::cout << "[1] Agregar artefacto \n[2] Mostrar armamento \n[3] Exportar armamento\n[0] Salir\n";
                std::cin >> opcion;
                if (opcion == 1)
                {
                    std::cout << "Ingresa el artefacto que desee agregar: ";
                    std::cout << "[1] Casco Paladina  \n[2] Torso Paladina \n[3] Piernas Paladina \n[4] Esfera Planar Sellaespacios\n";
                    std::cout << "[5] Esfera Planar Diferenciador Celestial \n[6] Pista de Luz Diferenciador Celestial \n[7] Esfera Planar Quilla Rota\n";
                    std::cin >> opcion;
                    if (opcion == 1)
                    {
                        armamento1.agregar_artefacto(artefacto(1, "Paladina de la Iglesia de la Corte Inmaculada", CABEZA, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 2)
                    {
                        armamento1.agregar_artefacto(artefacto(2, "Paladina de la Iglesia de la Corte Inmaculada", TORSO, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 3)
                    {
                        armamento1.agregar_artefacto(artefacto(3, "Paladina de la Iglesia de la Corte Inmaculada", PIERNAS, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 4)
                    {
                        armamento1.agregar_artefacto(artefacto(4, "Estacion Sellaespacios", ESFERA_PLANAR, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 5)
                    {
                        armamento1.agregar_artefacto(artefacto(5, "Diferenciador Celestial", ESFERA_PLANAR, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 6)
                    {
                        armamento1.agregar_artefacto(artefacto(6, "Diferenciador Celestial", PISTA_DE_LUZ, 1, CINCO_ESTRELLAS));
                    }
                    else if (opcion == 7)
                    {
                        armamento1.agregar_artefacto(artefacto(7, "Quilla Rota", ESFERA_PLANAR, 1, CINCO_ESTRELLAS));
                    }
                }
                else if (opcion == 2)
                {
                    armamento1.mostrar_artefactos();
                }
                else if (opcion == 3)
                {
                    armamento1.establecer_nombre_armamento();
                    armamento1.exportar_armamento();
                }
            }
        }
    }

    else if (opcion == OPCION_COMBATES)
    {
        combate_multiple combate1;
        while (opcion != OPCION_SALIR)
        {
            std::cout << "[1] Agregar combate \n[2] Pelear \n[0] Salir \n";
            std::cin >> opcion;
            if (opcion == 1)
            {
                std::cout << "Ingresa el combate que deseas agregar \n";
                std::cout << "[1] Doomsday Beast \n[2] Voidrangers \n[3] Stormbringer \n[4] Svarog \n[5] Bronya \n";
                std::cin >> opcion;
                if (opcion == 1)
                {
                    combate1.agregar_combate(combate("Estas en presencia del Doomsday Beast, maxima precaución", 1, 20));
                }
                if (opcion == 2)
                {
                    combate1.agregar_combate(combate("Fuiste emboscado por Voidrangers", 3, 5));
                }
                if (opcion == 3)
                {
                    combate1.agregar_combate(combate("Te encontraste con Stormbringer, preparate", 3, 5));
                }
                if (opcion == 4)
                {
                    combate1.agregar_combate(combate("Svarog, protocolo de exterminación lanzado", 1, 10));
                }
                if (opcion == 5)
                {
                    combate1.agregar_combate(combate("Bronya te ordena lanzar las armas y rendirte", 5, 10));
                }
            }
            else if (opcion == 2)
            {
                size_t poder_trazacaminos_gastado = combate1.pelear();
                std::cout << "Poder de Trazacaminos total gastado " << poder_trazacaminos_gastado << std::endl;
            }
        }
    }

    return 0;
}