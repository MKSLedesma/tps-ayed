/* Trabajos e implementaciones realizadas por Elias Cuba y Mauricio Laganga. Colaboracion de Cristian Ledesma. */

#ifndef AYED_TPG_1C2024_PEDIDO_HPP
#define AYED_TPG_1C2024_PEDIDO_HPP

#include "local.hpp"

class Pedido {
private:
    Local origen;
    Local destino;
    int peso;
    int prioridad_pedido;

public:
    Pedido();

    Pedido(Local origen, Local destino, int peso) {
        this->origen = origen;
        this->destino = destino;
        this->peso = peso;
        prioridad_pedido = origen.obtener_prioridad() * peso;
    }

    bool operator<(const Pedido& pedido1) const {
        return prioridad_pedido < pedido1.prioridad_pedido;
    }

    int obtener_prioridad() const {
        return prioridad_pedido;
    }

    Local obtener_origen() {
        Local _origen = origen;
        return _origen;
    }

    Local obtener_destino() {
        Local _destino = destino;
        return _destino;
    }
};

#endif // AYED_TPG_1C2024_PEDIDO_HPP