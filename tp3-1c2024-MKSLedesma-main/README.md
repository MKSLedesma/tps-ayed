[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Z4l11-L-)
# AyED / AYP2 - TP3 1c2024

<p align="center">
   <img src="Banner.jpg" alt="TP3: Quality of Life"><br>
</p>

### Estudiante: LEDESMA, CRISTIAN - 111426

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

> // COMPLETAR CON LINEA DE COMPILACIÓN //

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

Para distribuciones de Linux, se pueden utilizar los scripts presentes en el directorio raíz para compilar y ejecutar
la suite de tests. Requiere:

1. [g++](https://gcc.gnu.org/)
2. [CMake](https://cmake.org/)
3. [Valgrind](https://valgrind.org/)

Que se pueden instalar por terminal:

> sudo apt-get install // PROGRAMA //

# Aclaraciones adicionales:

//Dentro de artefacto.hpp añadi dos metodos para convertir de string a tipo y de string a rareza
para evitar errores a la hora de importar un archivo || Añadi un booleano "esta_agregado" en armamentos para 
evitar agregar artefactos repetidos || Añadi el UUID y el nombre del armamento como atributo privado para evitar 
conflictos a la hora de exportar
//