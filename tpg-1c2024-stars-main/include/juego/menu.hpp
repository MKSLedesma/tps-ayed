#ifndef AYED_TPG_1C2024_MENU_HPP
#define AYED_TPG_1C2024_MENU_HPP

#include "juego_principal.hpp"
#include "juego_secundario.hpp"
#include "iostream"
#include <string>


using namespace std;

class Menu {
private:

    const string OPCION_INVALIDA = "Opcion invalida, por favor elija otra";
    const string TITULO_MENU = "Bienvenido al Callejón Aurum \n";
    const string FIN_JUEGO = "Gracias por jugar!";
    const string MENU_MINIJUEGO_SECUNDARIO = "¿Desea jugar el minijuego secundario? Podras ver que senderos optimizar segun cantidad de pedidos \n 0- NO/SALIR \n 1- Jugar";

public:

    // Pre: -
    // Post: Invoca al juego principal y te da la opcion de jugar al secundario.
    void menu_inicial();
    // Pre: -
    // Post:Muestra el menú del juego secundario y devuelve true si se elige jugar.
    bool jugar_juego_secundario();

};

void Menu::menu_inicial() {
    std::cout << TITULO_MENU << std::endl;

    JuegoPrincipal juego_principal;
    juego_principal.jugar();

    bool entrada_juego_secundario = jugar_juego_secundario();

    if (entrada_juego_secundario) {
        JuegoSecundario juego_secundario(juego_principal.obtener_grafo());
        juego_secundario.obtener_caminos_transitados();
    }

    std::cout << FIN_JUEGO << std::endl;
}
bool Menu::jugar_juego_secundario(){
    bool entrada;
    int opcion_elegida;
    bool salida_menu = false;

    while (!salida_menu) {

        cout << MENU_MINIJUEGO_SECUNDARIO << endl;
        cin >> opcion_elegida;

        switch (opcion_elegida) {
            case 0:
                entrada = false;
                salida_menu = true;
                break;
            case 1:
                entrada = true;
                salida_menu = true;
                break;
            default:
                cout << OPCION_INVALIDA << endl;
                break;
        }
    }
    return entrada;
}



#endif //AYED_TPG_1C2024_MENU_HPP
