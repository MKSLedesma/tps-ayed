#include "armamento_artefactos.hpp"
#include <fstream>
#include <sstream>
const size_t MAXIMO_ARTEFACTOS = 6;

armamento_artefactos::armamento_artefactos() {
}

armamento_artefactos::armamento_artefactos(std::string path_archivo)
{
    std::ifstream archivo(path_archivo);
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo " << path_archivo << std::endl;
    }
    else
    {
        std::string linea;
        while (getline(archivo, linea))
        {
            std::istringstream ss(linea);
            std::string id_string;
            std::string set;
            std::string tipo1_string;
            std::string nivel_string;
            std::string rareza1_string;

            std::getline(ss, id_string, ',');
            int id = std::stoi(id_string);
            std::getline(ss, set, ',');
            std::getline(ss, tipo1_string, ',');
            tipo tipo1 = artefacto::string_a_tipo(tipo1_string);
            std::getline(ss, nivel_string, ',');
            size_t nivel = std::stoull(nivel_string);
            std::getline(ss, rareza1_string, ',');
            rareza rareza1 = artefacto::string_a_rareza(rareza1_string);

            armamento.alta(artefacto(id, set, tipo1, nivel, rareza1));
        }
    }
}

void armamento_artefactos::establecer_uuid() {
    std::string uuid_usuario;
    std::cout << "Ingrese su UUID (8 digitos)\n";
    std::cin >> uuid_usuario;
    while (uuid_usuario.length() != 8)
    {
        std::cout << "El UUID debe contener 8 digitos\n";
        std::cin >> uuid_usuario;
    }
    uuid = uuid_usuario;
}

void armamento_artefactos::establecer_nombre_armamento() {
    std::string nombre_armamento_usuario;
    std::cout << "Ingrese el nombre de su nuevo armamento (sin espacios)\n";
    std::cin >> nombre_armamento_usuario;
    nombre_armamento = nombre_armamento_usuario;
}

void armamento_artefactos::agregar_artefacto(artefacto artefacto_a_agregar)
{
    if (armamento.tamanio() < MAXIMO_ARTEFACTOS && !esta_agregado(artefacto_a_agregar))
    {
        armamento.alta(artefacto_a_agregar);
    }
    else if (esta_agregado(artefacto_a_agregar))
    {
        std::cout << "No puedes agregar artefactos repetidos \n";
    }
    else
    {
        std::cout << "El armamento esta lleno, es imposible añadir mas artefactos" << std::endl;
    }
}

void armamento_artefactos::mostrar_artefacto_actual() {
    std::cout << armamento.actual() << std::endl;
}

void armamento_artefactos::mostrar_artefacto_siguiente() {
    armamento.avanzar();
    std::cout << armamento.actual() << std::endl;
}

void armamento_artefactos::mostrar_artefacto_anterior() {
    armamento.retroceder();
    std::cout << armamento.actual() << std::endl;
}

void armamento_artefactos::mostrar_artefactos() {
    if (!armamento.vacio())
    {
        artefacto primero = armamento.actual();
        do
        {
            std::cout << armamento.actual() << std::endl;
            armamento.avanzar();
        }
        while (primero != armamento.actual());
    }
    else
    {
        std::cout << "El armamento esta vacio\n";
    }

}

void armamento_artefactos::quitar_artefacto() {
    armamento.baja();
}

bool armamento_artefactos::esta_agregado(artefacto artefacto_buscado) {
    bool encontrado = false;
    if (!armamento.vacio())
    {
        artefacto primer_artefacto = armamento.actual();
        do
        {
            if (armamento.actual() == artefacto_buscado)
            {
                encontrado = true;
                primer_artefacto = armamento.actual();
            }
            armamento.avanzar();
        }
        while (primer_artefacto != armamento.actual());
    }
    return encontrado;
}

void armamento_artefactos::exportar_armamento() {
    std::string nombre_archivo = uuid + "-" + nombre_armamento + ".csv";
    std::ofstream archivo(nombre_archivo);

    if (archivo.is_open())
    {
        if (!armamento.vacio())
        {
            artefacto primero = armamento.actual();
            archivo << armamento.actual() << "\n";
            armamento.avanzar();
            while (primero != armamento.actual())
            {
                archivo << armamento.actual() << "\n";
                armamento.avanzar();
            }
            archivo.close();
            std::cout << "Saltos exportados exitosamente en " << nombre_archivo << std::endl;
        }
        else
        {
            std::cout << "El armamento esta vacio\n";
            archivo.close();
        }
    }
}