#include "gacha.hpp"
#include <iostream>
using namespace std;

const int OPCION_GENERAR_MULTIPLES = 1;
const int OPCION_GENERAR_PERSONALIZADO = 2;
const int OPCION_EXPORTAR = 3;
const int OPCION_FINALIZAR = 4;

int main() {
    gacha gacha1;
    int opcion;
    size_t cantidad_saltos;

    cout << "Bienvenido a Honkai Star Rail" << endl;
    cout << "Sistema de Gacha iniciado, elija una opcion para continuar:" << endl;
    cout << "[" << OPCION_GENERAR_MULTIPLES << "] Generar salto multiple \n"
         << "[" << OPCION_GENERAR_PERSONALIZADO << "] Generar salto personalizado \n"
         << "[" << OPCION_EXPORTAR << "] Exportar saltos \n"
         << "[" << OPCION_FINALIZAR << "] Finalizar \n";

    cin >> opcion;

    while(opcion != OPCION_FINALIZAR)
    {
        if (opcion == OPCION_GENERAR_MULTIPLES)
        {
            vector<salto> mostrar = gacha1.generar_salto_multiple();
            cout << "----- Saltos -----" << endl;
            for (size_t i = 0; i < mostrar.tamanio(); i++)
            {
                cout << mostrar[i] << endl;
            }
            cout << "--------------------" << endl;
        }

        else if (opcion == OPCION_GENERAR_PERSONALIZADO)
        {
            cout << "Ingrese la cantidad de saltos a realizar: " << endl;
            cin >> cantidad_saltos;
            cout << "----- Saltos -----" << endl;
            vector<salto> mostrar = gacha1.generar_salto_multiple(cantidad_saltos);
            for (size_t i = 0; i < mostrar.tamanio(); i++)
            {
                cout << mostrar[i] << endl;
            }
            cout << "--------------------" << endl;
        }

        else if (opcion == OPCION_EXPORTAR)
        {
            gacha1.exportar_saltos();
        }

        else
        {
            cout << "Opcion invalida. Por favor, seleccione una opcion correcta" << endl;
        }

        cout << "[" << OPCION_GENERAR_MULTIPLES << "] Generar salto multiple \n"
             << "[" << OPCION_GENERAR_PERSONALIZADO << "] Generar salto personalizado \n"
             << "[" << OPCION_EXPORTAR << "] Exportar saltos \n"
             << "[" << OPCION_FINALIZAR << "] Finalizar \n";

        cin >> opcion;
    }

    return 0;
}
