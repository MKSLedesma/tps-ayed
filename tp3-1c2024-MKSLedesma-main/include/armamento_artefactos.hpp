#ifndef AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#define AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#include <iostream>
#include "artefacto.hpp"
#include "lista_circular.hpp"

class armamento_artefactos {
private:
    lista_circular<artefacto> armamento;
    std::string uuid;
    std::string nombre_armamento;

public:
    //Constructor
    armamento_artefactos();

    //Pre: El archivo debe respetar el formato por linea: "ID,SET,TIPO,NIVEL,RAREZA"
    //Post: Construye un armamento_artefactos con los artefactos dentro del archivo.
    armamento_artefactos(std::string path_archivo);

    //Pre: El UUID debe ser un número único de 8 dígitos.
    //Post: Establece el UUID del usuario.
    void establecer_uuid();

    //Pre:
    //Post: Estable el nombre del armamento actual.
    void establecer_nombre_armamento();

    //Pre: No se pueden agregar artefactos repetidos.
    //Post: Agrega el artefacto al armamento actual.
    void agregar_artefacto(artefacto artefacto_a_agregar);

    //Pre:
    //Post: Imprime por pantalla el artefacto actual.
    void mostrar_artefacto_actual();

    //Pre:
    //Post: Imprime por pantalla el artefacto siguiente al actual.
    void mostrar_artefacto_siguiente();

    //Pre:
    //Post: Imprime por pantalla el artefacto anterior al actual.
    void mostrar_artefacto_anterior();

    //Pre:
    //Post: Imprime todos los artefactos en el armamento actual.
    void mostrar_artefactos();

    //Pre:
    //Post: Elimina el artefacto actual del armamento.
    void quitar_artefacto();

    //Pre:
    //Post: Devuelve True si el artefacto buscado se encuentra en el armamento.
    bool esta_agregado(artefacto artefacto_buscado);

    //Pre:
    //Post: Exporta el armamento actual a un archivo con el formato: "UUID-NOMBRE_ARMAMENTO.csv".
    void exportar_armamento();
};

#endif