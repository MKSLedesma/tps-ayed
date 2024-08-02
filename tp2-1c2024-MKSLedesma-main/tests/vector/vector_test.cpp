
#include "gtest/gtest.h"
#include "vector.hpp"

class vector_test : public ::testing::Test {
protected:
    vector<int> vector1{};
    int dato{};
};

TEST_F(vector_test, Alta) {
    vector1.alta(1);
    EXPECT_EQ(vector1[0], 1);

    vector1.alta(2);
    EXPECT_EQ(vector1[1], 2);

    vector1.alta(3);
    EXPECT_EQ(vector1[2], 3);
}

TEST_F(vector_test, AltaIndice) {
    vector1.alta(1, 0);
    EXPECT_EQ(vector1[0], 1);

    vector1.alta(2, 0);
    EXPECT_EQ(vector1[0], 2);

    vector1.alta(3, 1);
    EXPECT_EQ(vector1[1], 3);

    vector1.alta(4, 3);
    EXPECT_EQ(vector1[3], 4);
}

TEST_F(vector_test, AltaIndiceManejaIndiceMayorACantidadDeDatos) {
    EXPECT_THROW(vector1.alta(1, 1), vector_exception);

    vector1.alta(1);
    EXPECT_THROW(vector1.alta(2, 2), vector_exception);
}

TEST_F(vector_test, OperadorAcceso) {
    vector1.alta(1);
    vector1.alta(2, 0);
    vector1.alta(3);

    EXPECT_EQ(vector1[0], 2);
    EXPECT_EQ(vector1[1], 1);
    EXPECT_EQ(vector1[2], 3);
}

TEST_F(vector_test, OperadorAccesoManejaVectorVacio) {
    EXPECT_THROW(vector1[0], vector_exception);
}

TEST_F(vector_test, OperadorAccesoManejaIndiceMayorOIgualACantidadDeDatos) {
    vector1.alta(1);

    EXPECT_NO_THROW(vector1[0]);
    EXPECT_THROW(vector1[1], vector_exception);
    EXPECT_THROW(vector1[2], vector_exception);
}

TEST_F(vector_test, Baja) {
    vector1.alta(1);
    vector1.alta(2);

    dato = vector1.baja();
    EXPECT_EQ(dato, 2);

    dato = vector1.baja();
    EXPECT_EQ(dato, 1);
}

TEST_F(vector_test, BajaIndice) {
    vector1.alta(1);
    vector1.alta(2);
    vector1.alta(3);
    vector1.alta(4);

    dato = vector1.baja(1);
    EXPECT_EQ(dato, 2);

    dato = vector1.baja(0);
    EXPECT_EQ(dato, 1);

    dato = vector1.baja(1);
    EXPECT_EQ(dato, 4);

    dato = vector1.baja(0);
    EXPECT_EQ(dato, 3);
}

TEST_F(vector_test, BajaManejaVectorVacio) {
    EXPECT_THROW(vector1.baja(), vector_exception);
}


TEST_F(vector_test, BajaIndiceManejaVectorVacio) {
    EXPECT_THROW(vector1.baja(0), vector_exception);
}

TEST_F(vector_test, BajaIndiceManejaIndiceMayorOIgualACantidadDeDatos) {
    vector1.alta(1);
    EXPECT_THROW(vector1.baja(1), vector_exception);
    EXPECT_THROW(vector1.baja(2), vector_exception);
    EXPECT_NO_THROW(vector1.baja(0));
}

TEST_F(vector_test, Vacio) {
    EXPECT_TRUE(vector1.vacio());

    vector1.alta(1);
    EXPECT_FALSE(vector1.vacio());

    vector1.baja();
    EXPECT_TRUE(vector1.vacio());
}

TEST_F(vector_test, Tamanio) {
    EXPECT_EQ(vector1.tamanio(), 0);

    vector1.alta(1);
    vector1.alta(2);
    vector1.alta(3);
    EXPECT_EQ(vector1.tamanio(), 3);

    vector1.baja();
    EXPECT_EQ(vector1.tamanio(), 2);
}