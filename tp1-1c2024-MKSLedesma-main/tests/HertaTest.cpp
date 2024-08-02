#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Herta.hpp"

class HertaTest : public ::testing::Test {
protected:
    const std::string RESPUESTA_AUTOMATICA = "[Respuesta automatica] Hola. En este momento no estoy disponible, "
                                             "y no me pondre en contacto contigo mas tarde.\n";
    const std::string RESPUESTAS_KURU[3] = {"KURU\n", "KURURIN\n", "KURU KURU\n"};
    const std::string RESPUESTA_HOLA = "Hola.\n";
    const std::string RESPUESTA_PROBLEMA = "No te preocupes. Ya esta solucionado.\n";
    const std::string RESPUESTA_PREOCUPADO = "De que te preocupas si yo estoy aqui?\n";
    const std::string RESPUESTA_SIMULADO = "La actualizacion del Universo Simulado ya esta lista, ven a probarla.\n";
    const std::string RESPUESTA_ERES_HERTA = "Quieres una selfie para demostrartelo o que?\n";
    const std::string RESPUESTA_MARIONETA = "Vaya, parece que la perdi. No me extrania que no la encuentre.\n";
    const std::string RESPUESTAS_INDETERMINADO[2] = {"Oh.\n", "...\n"};

    Herta herta{};
    std::string respuesta{};

    std::string capturar_respuesta(std::string mensaje);

    void reiniciar_herta();

    void SetUp() override;
};

std::string HertaTest::capturar_respuesta(std::string mensaje) {
    testing::internal::CaptureStdout();
    herta.responder(std::move(mensaje));
    return testing::internal::GetCapturedStdout();
}

void HertaTest::reiniciar_herta() {
    herta = Herta();
    capturar_respuesta("");
}

void HertaTest::SetUp() {
    capturar_respuesta("");
}

TEST_F(HertaTest, LaPrimeraRespuestaEsAutomatica) {
    herta = Herta();
    respuesta = capturar_respuesta("hola");
    ASSERT_EQ(respuesta, RESPUESTA_AUTOMATICA);
}

TEST_F(HertaTest, HertaRespondeCincoMensajesDeFormaManual) {
    for (int _ = 1; _ <= 5; _++) {
        respuesta = capturar_respuesta("hola");
        ASSERT_EQ(respuesta, RESPUESTA_HOLA);
    }
}

TEST_F(HertaTest, DespuesDeCincoRespuestasManualesLaRespuestaEsAutomatica) {
    for (int _ = 1; _ <= 5; _++) {
        capturar_respuesta("");
    }
    respuesta = capturar_respuesta("hola");
    ASSERT_EQ(respuesta, RESPUESTA_AUTOMATICA);
}

TEST_F(HertaTest, RespuestaManualKuru) {
    for (int _ = 1; _ <= 5; _++) {
        respuesta = capturar_respuesta("kuru");
        ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
    }
}

TEST_F(HertaTest, RespuestaManualKururin) {
    for (int _ = 1; _ <= 5; _++) {
        respuesta = capturar_respuesta("kururin");
        ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
    }
}

TEST_F(HertaTest, RespuestaManualKuruKururinEsAleatoria) {
    bool kuru = false, kururin = false, kuru_kuru = false;
    for (int i = 1; i <= 20; i++) {
        respuesta = capturar_respuesta("kuru");
        if (respuesta == RESPUESTAS_KURU[0]) {
            kuru = true;
        } else if (respuesta == RESPUESTAS_KURU[1]) {
            kururin = true;
        } else if (respuesta == RESPUESTAS_KURU[2]) {
            kuru_kuru = true;
        }
        if (i % 5 == 0) {
            reiniciar_herta();
        }
    }
    ASSERT_TRUE(kuru && kururin && kuru_kuru);
}

TEST_F(HertaTest, RespuestaManualKuruKururinNoEsCaseSensitive) {
    respuesta = capturar_respuesta("KURU");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));

    respuesta = capturar_respuesta("KURURIN");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualHola) {
    respuesta = capturar_respuesta("hola");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, RespuestaManualHolaNoEsCaseSensitive) {
    respuesta = capturar_respuesta("HoLa");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, RespuestaManualProblema) {
    respuesta = capturar_respuesta("problema");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, RespuestaManualProblemaNoEsCaseSensitive) {
    respuesta = capturar_respuesta("ProBleMa");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, RespuestaManualPreocupado) {
    respuesta = capturar_respuesta("preocupado");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);

    respuesta = capturar_respuesta("preocupada");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}

TEST_F(HertaTest, RespuestaManualPreocupadoNoEsCaseSensitive) {
    respuesta = capturar_respuesta("PreOcuPaDo");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);

    respuesta = capturar_respuesta("PreOcuPaDa");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}

TEST_F(HertaTest, RespuestaManualSimulado) {
    respuesta = capturar_respuesta("simulado");
    ASSERT_EQ(respuesta, RESPUESTA_SIMULADO);
}

TEST_F(HertaTest, RespuestaManualSimuladoNoEsCaseSensitive) {
    respuesta = capturar_respuesta("SimuLaDo");
    ASSERT_EQ(respuesta, RESPUESTA_SIMULADO);
}

TEST_F(HertaTest, RespuestaManualEresHerta) {
    respuesta = capturar_respuesta("Eres Herta?");
    ASSERT_EQ(respuesta, RESPUESTA_ERES_HERTA);
}

TEST_F(HertaTest, RespuestaManualEresHertaNoEsCaseSensitive) {
    respuesta = capturar_respuesta("ERES HERTA?");
    ASSERT_EQ(respuesta, RESPUESTA_ERES_HERTA);
}

TEST_F(HertaTest, RespuestaManualEresHertaElMensajeDebeSerExacto) {
    respuesta = capturar_respuesta("Eres Herta??");
    ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualMarioneta) {
    respuesta = capturar_respuesta("Y tu marioneta?");
    ASSERT_EQ(respuesta, RESPUESTA_MARIONETA);
}

TEST_F(HertaTest, RespuestaManualMarionetaNoEsCaseSensitive) {
    respuesta = capturar_respuesta("Y TU MARIONETA?");
    ASSERT_EQ(respuesta, RESPUESTA_MARIONETA);
}

TEST_F(HertaTest, RespuestaManualMarionetaElMensajeDebeSerExacto) {
    respuesta = capturar_respuesta("Y tu marioneta??");
    ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
}

TEST_F(HertaTest, RespuestaManualIndeterminado) {
    for (int _ = 1; _ <= 5; _++) {
        respuesta = capturar_respuesta("...");
        ASSERT_THAT(RESPUESTAS_INDETERMINADO, testing::Contains(respuesta));
    }
}

TEST_F(HertaTest, RespuestaManualIndeterminadoEsAleatoria) {
    bool oh = false, puntos_suspensivos = false;
    for (int i = 1; i <= 10; i++) {
        respuesta = capturar_respuesta("...");
        if (respuesta == RESPUESTAS_INDETERMINADO[0]) {
            oh = true;
        } else if (respuesta == RESPUESTAS_INDETERMINADO[1]) {
            puntos_suspensivos = true;
        }
        if (i % 5 == 0) {
            reiniciar_herta();
        }
    }
    ASSERT_TRUE(oh && puntos_suspensivos);
}

TEST_F(HertaTest, PrioridadRespuestaManualKuru) {
    respuesta = capturar_respuesta("kuru hola problema preocupado simulado");
    ASSERT_THAT(RESPUESTAS_KURU, testing::Contains(respuesta));
}

TEST_F(HertaTest, PrioridadRespuestaManualHola) {
    respuesta = capturar_respuesta("hola problema preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_HOLA);
}

TEST_F(HertaTest, PrioridadRespuestaManualProblema) {
    respuesta = capturar_respuesta("problema preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_PROBLEMA);
}

TEST_F(HertaTest, PrioridadRespuestaManualPreocupado) {
    respuesta = capturar_respuesta("preocupado simulado");
    ASSERT_EQ(respuesta, RESPUESTA_PREOCUPADO);
}