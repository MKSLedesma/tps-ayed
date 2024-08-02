#include "Herta.hpp"
#include <iostream>
using namespace std;

const int OPCION_1 = 0;
const int OPCION_2 = 1;

Herta::Herta(int cantidad_respuestas_manuales, bool primer_mensaje)
{
    this->cantidad_respuestas_manuales = 0;
    this->primer_mensaje = true;
}

std::string Herta::convertir_mayuscula(std::string cadena)
{
    for (size_t i = 0; i < cadena.length(); i++)
    {
        cadena[i] = char(toupper(cadena[i]));
    }
    return cadena;
}

void Herta::responder_automatico()
{
    cout << "[Respuesta automatica] Hola. En este momento no estoy disponible, y no me pondre en contacto contigo mas tarde." << endl;
}
void Herta::responder_kuru_aleatorio()
{
    int indice_aleatorio = rand() % 3;

    if (indice_aleatorio == OPCION_1)
    {
        cout << "KURU" << endl;
    }
    else if (indice_aleatorio == OPCION_2)
    {
        cout << "KURU KURU" << endl;
    }
    else
    {
        cout << "KURURIN" << endl;
    }
}
void Herta::responder_hola()
{
    cout << "Hola." << endl;
}
void Herta::responder_problema()
{
    cout << "No te preocupes. Ya esta solucionado." << endl;
}
void Herta::responder_preocupado()
{
    cout << "De que te preocupas si yo estoy aqui?" << endl;
}
void Herta::responder_simulado()
{
    cout << "La actualizacion del Universo Simulado ya esta lista, ven a probarla." << endl;
}
void Herta::responder_eres_herta()
{
    cout << "Quieres una selfie para demostrartelo o que?" << endl;
}
void Herta::responder_marioneta()
{
    cout << "Vaya, parece que la perdi. No me extrania que no la encuentre." << endl;
}
void Herta::responder_indefinido_aleatorio()
{
    if (rand() % 2 == 0)
    {
        cout << "Oh." << endl;
    }
    else
    {
        cout << "..." << endl;
    }
}

void Herta::responder(std::string mensaje)
{
    std::string mensaje_mayuscula = convertir_mayuscula(mensaje);

    if (primer_mensaje)
    {
        responder_automatico();
        primer_mensaje = false;
    }

    else if (cantidad_respuestas_manuales < 5) {
        if ((mensaje_mayuscula.find("KURU") != string::npos) || (mensaje_mayuscula.find("KURURIN") != string::npos))
        {
            responder_kuru_aleatorio();
        }
        else if (mensaje_mayuscula.find("HOLA") != string::npos)
        {
            responder_hola();
        }
        else if ((mensaje_mayuscula.find("PROBLEMA") != string::npos))
        {
            responder_problema();
        }
        else if ((mensaje_mayuscula.find("PREOCUPADO") != string::npos) || (mensaje_mayuscula.find("PREOCUPADA") != string::npos))
        {
            responder_preocupado();
        }
        else if ((mensaje_mayuscula.find("SIMULADO") != string::npos))
        {
            responder_simulado();
        }
        else if (mensaje_mayuscula == "ERES HERTA?")
        {
            responder_eres_herta();
        }
        else if (mensaje_mayuscula == "Y TU MARIONETA?")
        {
            responder_marioneta();
        }
        else
        {
            responder_indefinido_aleatorio();
        }
        cantidad_respuestas_manuales++;
    }

    else
    {
        responder_automatico();
    }
}
