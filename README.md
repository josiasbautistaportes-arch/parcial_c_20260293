# Parcial de algoritmos en C

- Estudiante: Josías Bautista
- Matrícula: 20260293
- Reto asignado: Reto 18: Soporte: reducción respecto al registro inicial

## Descripción
El programa recibe una matriz de N filas y M columnas. Cada fila es un equipo de soporte, cada columna es un día y cada número es la cantidad de tickets pendientes. Con eso muestra un informe en consola.

Entrada: en la primera línea van N, M, L y U. Después van las N filas con M números cada una. Los números pueden ir separados por espacios o por saltos de línea.

Restricciones: N y M entre 1 y 30, L y U entre 0 y 1000 con L menor o igual que U, y cada valor de la matriz entre 0 y 1000. Si algo no se cumple, el programa imprime solamente ERROR.

Salida:
```text
FILA i EVENTOS e IMPACTO s RACHA r INICIO b
COLUMNAS c1 c2 ... cM
PRIORIDAD f
COLUMNA k
```
Hay una línea FILA por cada fila. Los números de fila y de columna empiezan en 1. Si no hay ningún evento, PRIORIDAD y COLUMNA salen en 0.

Cómo funciona: en cada fila uso el primer valor como referencia (f). Desde la segunda columna, un valor x es un evento si f - x está entre L y U. El impacto de ese evento es f - x + 1. Por cada fila cuento los eventos, sumo los impactos y busco la racha más larga de eventos seguidos. Si hay dos rachas iguales, me quedo con la que empieza primero. También cuento los eventos de cada columna. La fila prioritaria es la de racha más larga; si empatan se mira el impacto, luego los eventos y luego el número de fila más chico. La columna destacada es la que tiene más eventos y, si empatan, la de número menor.

## Compilación y ejecución
Lo hice en Windows, con Git Bash y VS Code. El compilador es gcc 15.2.0 (MSYS2).

```bash
gcc -std=c11 -Wall -Wextra 20260293.c -o reto
./reto < 20260293/pruebas/caso_01.in
```

## Diseño
El análisis y el pseudocódigo están en `analisis/`.

## Pruebas
Los casos del profesor están en `20260293/pruebas/`.
Mis resultados, la prueba de escritorio y mis dos pruebas propias con su justificación están en `evidencias/`.
En Windows el programa agrega un `\r` al final de cada línea. Por eso, para comparar con los archivos `.out`, uso `tr -d '\r'`.

## Estado actual
El programa está terminado. Compila sin warnings y los 17 casos del profesor dan la salida esperada. No conozco errores.