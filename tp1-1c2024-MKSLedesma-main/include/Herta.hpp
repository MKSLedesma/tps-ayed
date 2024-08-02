#ifndef TP1_1C2024_HERTA_HPP
#define TP1_1C2024_HERTA_HPP

#include <string>

class Herta {
private:
    int cantidad_respuestas_manuales;
    bool primer_mensaje;

    //PRECONDICIONES: Recibir una cadena de caracteres.
    //POSTCONDICIONES: Devuelve un string en mayusculas de la cadena original.
    std::string convertir_mayuscula(std::string cadena);

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta predefinida automatica.
    void responder_automatico();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta aleatoria entre variaciones de "KURU".
    void responder_kuru_aleatorio();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el caso "Hola".
    void responder_hola();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el caso "problema".
    void responder_problema();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el caso "preocupado".
    void responder_preocupado();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el caso "simulado".
    void responder_simulado();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el mensaje "Eres Herta?".
    void responder_eres_herta();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta para el mensaje "Y tu marioneta?".
    void responder_marioneta();

    //PRECONDICIONES:
    //POSTCONDICIONES: Imprime una respuesta aleatoria entre "Oh..." y "..." para mensajes indefinidos.
    void responder_indefinido_aleatorio();

public:
    //Constructor
    Herta(int cantidad_respuestas_automaticas = 0,
          bool primer_mensaje = true);

    //PRECONDICIONES: Recibe una cadena de caracteres que contenga un mensaje.
    //POSTCONDICIONES: Imprime por pantalla una respuesta para los casos planteados.
    void responder(std::string mensaje);
};

#endif