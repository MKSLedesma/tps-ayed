#include "gtest/gtest.h"
#include "gacha.hpp"

class gacha_test : public ::testing::Test {
protected:
    gacha gacha1{};
    vector<salto> salto_multiple;
    salto salto_simple{};
    bool cinco_estrellas{};
    bool cuatro_estrellas{};
    bool tres_estrellas{};

    void determinar_rareza(salto salto);

    void SetUp() override;
};

void gacha_test::determinar_rareza(salto salto) {
    switch (salto.obtener_rareza()) {
        case CINCO_ESTRELLAS:
            cinco_estrellas = true;
            break;
        case CUATRO_ESTRELLAS:
            cuatro_estrellas = true;
            break;
        case TRES_ESTRELLAS:
            tres_estrellas = true;
            break;
    }
}

void gacha_test::SetUp() {
    cinco_estrellas = false;
    cuatro_estrellas = false;
    tres_estrellas = false;
}

TEST_F(gacha_test, EnNoventaSaltosSimplesSeDebenGenerarTodasLasRarezas) {
    for (int i = 0; i < 90; i++) {
        salto_simple = gacha1.generar_salto();
        determinar_rareza(salto_simple);
    }
    while (salto_simple.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto_simple = gacha1.generar_salto();
        determinar_rareza(salto_simple);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(gacha_test, EnNueveSaltosMultiplesSeDebenGenerarTodasLasRarezas) {
    for (int i = 0; i < 9; i++) {
        salto_multiple = gacha1.generar_salto_multiple();
        for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
            salto_simple = salto_multiple[j];
            determinar_rareza(salto_simple);
        }
    }
    while (salto_simple.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto_simple = gacha1.generar_salto();
        determinar_rareza(salto_simple);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(gacha_test, EnUnSaltoMultipleSeDebenGenerarTodasLasRarezas) {
    salto_multiple = gacha1.generar_salto_multiple(90);
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        salto_simple = salto_multiple[j];
        determinar_rareza(salto_simple);
    }
    while (salto_simple.obtener_rareza() == CUATRO_ESTRELLAS) {
        salto_simple = gacha1.generar_salto();
        determinar_rareza(salto_simple);
    }
    ASSERT_TRUE(cinco_estrellas && cuatro_estrellas && tres_estrellas);
}

TEST_F(gacha_test, EnDiezSaltosSimplesSeDebeGenerarUnCuatroEstrellasOMejor) {
    for (int i = 0; i < 10; i++) {
        determinar_rareza(gacha1.generar_salto());
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}

TEST_F(gacha_test, EnUnSaltoMultipleSeDebeGenerarUnCuatroEstrellasOMejor) {
    salto_multiple = gacha1.generar_salto_multiple();
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        determinar_rareza(salto_multiple[j]);
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}

TEST_F(gacha_test, EnUnSaltoMultipleCantidadSeDebeGenerarUnCuatroEstrellasOMejor) {
    salto_multiple = gacha1.generar_salto_multiple(10);
    for (size_t j = 0; j < salto_multiple.tamanio(); j++) {
        determinar_rareza(salto_multiple[j]);
    }
    ASSERT_TRUE(cinco_estrellas || cuatro_estrellas);
}