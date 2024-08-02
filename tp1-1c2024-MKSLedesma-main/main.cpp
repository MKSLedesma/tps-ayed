#include "Herta.hpp"
#include <iostream>
using namespace std;

int main() {
    Herta herta;

    cout << "Bienvenido al chat de Herta ¡prueba a conversar con ella!" << endl;
    cout << "Escribe <SALIR> para abandonar la conversacion." << endl;

    std::string mensaje;
    getline(cin, mensaje);
    //Añadi el metodo para convertir mensajes a mayuscula dentro del objeto Herta para que pudiera pasar los tests.
    while (mensaje != "SALIR")
    {
        herta.responder(mensaje);
        getline(cin, mensaje);
    }
    return 0;
}