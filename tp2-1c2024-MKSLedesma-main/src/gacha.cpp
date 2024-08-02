#include "gacha.hpp"
#include "generador_salto.hpp"
#include <random>
#include <fstream>
#include <iostream>

const int PITY_5_ESTRELLAS = 89;
const int PITY_4_ESTRELLAS = 9;


gacha::gacha(int contador_saltos_5_estrellas, int contador_saltos_4_estrellas)
{
    this->contador_saltos_5_estrellas = 0;
    this->contador_saltos_4_estrellas = 0;
}

int gacha::generar_probabilidad()
{
    return rand() % 100 + 1;
}

salto gacha::generar_salto()
{
    int probabilidad_gacha = generar_probabilidad();

    salto salto;

    if (contador_saltos_5_estrellas == PITY_5_ESTRELLAS)
    {
        salto = generador_salto::generar_salto_5_estrellas();
        contador_saltos_5_estrellas = 0;
        contador_saltos_4_estrellas++;
    }

    else if (contador_saltos_4_estrellas == PITY_4_ESTRELLAS)
    {
        salto = generador_salto::generar_salto_4_estrellas();
        contador_saltos_4_estrellas = 0;
        contador_saltos_5_estrellas++;
    }

    else if (probabilidad_gacha == 1)
    {
        salto = generador_salto::generar_salto_5_estrellas();
        contador_saltos_5_estrellas = 0;
        contador_saltos_4_estrellas++;
    }

    else if (probabilidad_gacha >= 2 && probabilidad_gacha <= 11)
    {
        salto = generador_salto::generar_salto_4_estrellas();
        contador_saltos_4_estrellas = 0;
        contador_saltos_5_estrellas++;
    }

    else
    {
        salto = generador_salto::generar_salto_3_estrellas();
        contador_saltos_5_estrellas++;
        contador_saltos_4_estrellas++;
    }

    return salto;
}

vector<salto> gacha::generar_salto_multiple()
{
    return generar_salto_multiple(10);
}

vector<salto> gacha::generar_salto_multiple(size_t cantidad)
{
    vector<salto> saltos;

    for (size_t i = 0; i < cantidad; i++)
    {
        saltos.alta(generar_salto());
        saltos_generados.alta(saltos[i]);
    }

    std::cout << "Saltos generados exitosamente" << std::endl;

    return saltos;
}

void gacha::exportar_saltos()
{
    std::ofstream archivo("registro_saltos.csv");

    if (archivo.is_open())
    {
        for (size_t i = 0; i < saltos_generados.tamanio(); i++)
        {
            archivo << saltos_generados[i] << "\n";
        }
        archivo.close();

        std::cout << "Saltos exportados exitosamente en registro_saltos.cvs" << std::endl;
    }
    else
    {
        throw std::runtime_error("Error al abrir el archivo");
    }
}