cmake_minimum_required(VERSION 3.22)
project(AyED_TP1_1c2024)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)

# Si crean otros archivos .cpp, los tienen que agregar acá de la forma:
#   "directorio/archivo.cpp"
set(ARCHIVOS_FUENTE "src/Herta.cpp")

add_executable(AyED_TP1_1c2024
        ${ARCHIVOS_FUENTE}
        main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")

add_subdirectory(tests)

target_sources(TPTests PRIVATE ${ARCHIVOS_FUENTE})