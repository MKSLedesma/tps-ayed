#include "gtest/gtest.h"
#include "lista_circular.hpp"

class lista_circular_test : public ::testing::Test {
protected:
    lista_circular<int> lista_circular1{};
    int dato{};
};

TEST_F(lista_circular_test, alta) {
    lista_circular1.alta(2);
    EXPECT_EQ(lista_circular1.actual(), 2);

    lista_circular1.alta(1);
    EXPECT_EQ(lista_circular1.actual(), 2);

    lista_circular1.avanzar();
    EXPECT_EQ(lista_circular1.actual(), 1);

    lista_circular1.alta(3);
    lista_circular1.retroceder();
    EXPECT_EQ(lista_circular1.actual(), 3);
}

TEST_F(lista_circular_test, actual_maneja_lista_vacia) {
    EXPECT_THROW(lista_circular1.actual(), lista_circular_exception);
}

TEST_F(lista_circular_test, baja) {
    lista_circular1.alta(1);
    dato = lista_circular1.baja();
    EXPECT_EQ(dato, 1);

    lista_circular1.alta(2);
    lista_circular1.alta(3);
    lista_circular1.avanzar();

    dato = lista_circular1.baja();
    EXPECT_EQ(dato, 3);
    EXPECT_EQ(lista_circular1.actual(), 2);
}

TEST_F(lista_circular_test, baja_maneja_lista_vacia) {
    EXPECT_THROW(lista_circular1.baja(), lista_circular_exception);
}

TEST_F(lista_circular_test, avanzar_caso_borde_un_solo_elemento) {
    lista_circular1.alta(1);
    EXPECT_EQ(lista_circular1.actual(), 1);
    lista_circular1.avanzar();
    EXPECT_EQ(lista_circular1.actual(), 1);
}

TEST_F(lista_circular_test, avanzar_no_lanza_excepcion_si_la_lista_esta_vacia) {
    EXPECT_NO_THROW(lista_circular1.avanzar());
}

TEST_F(lista_circular_test, retroceder_caso_borde_un_solo_elemento) {
    lista_circular1.alta(1);
    EXPECT_EQ(lista_circular1.actual(), 1);
    lista_circular1.retroceder();
    EXPECT_EQ(lista_circular1.actual(), 1);
}

TEST_F(lista_circular_test, retroceder_no_lanza_excepcion_si_la_lista_esta_vacia) {
    EXPECT_NO_THROW(lista_circular1.retroceder());
}

TEST_F(lista_circular_test, tamanio) {
    EXPECT_EQ(lista_circular1.tamanio(), 0);

    lista_circular1.alta(1);
    lista_circular1.alta(2);
    lista_circular1.alta(3);
    EXPECT_EQ(lista_circular1.tamanio(), 3);

    lista_circular1.baja();
    EXPECT_EQ(lista_circular1.tamanio(), 2);
}

TEST_F(lista_circular_test, vacio) {
    EXPECT_TRUE(lista_circular1.vacio());

    lista_circular1.alta(1);
    EXPECT_FALSE(lista_circular1.vacio());

    lista_circular1.baja();
    EXPECT_TRUE(lista_circular1.vacio());
}