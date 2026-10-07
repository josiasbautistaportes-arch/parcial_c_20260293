# Parcial de algoritmos en C

- Estudiante: Josías Bautista
- Matrícula: 20260293
- Reto asignado: Reto 18: Soporte: reducción respecto al registro inicial

## Descripción
El programa analiza una matriz de N x M. Cada fila es un equipo de soporte, cada columna es un día y cada valor son los tickets pendientes.

**Entrada:** una primera línea con `N M L U` y después N filas con M enteros. Se pueden separar con espacios o saltos de línea.

**Restricciones:** 1 <= N, M <= 30; 0 <= L <= U <= 1000; 0 <= cada valor <= 1000. Si algo falla, el programa imprime solamente `ERROR`.

**Salida:**
```text
FILA i EVENTOS e IMPACTO s RACHA r INICIO b
COLUMNAS c1 c2 ... cM
PRIORIDAD f
COLUMNA k
```
Los índices se imprimen desde 1. Si no hay eventos, `PRIORIDAD` y `COLUMNA` valen 0.

**Lógica:** en cada fila se toma como referencia el primer valor (`f`). Desde la segunda columna, un valor `x` genera un evento si `f - x` está entre L y U. Su impacto es `f - x + 1`. Por fila se cuentan eventos e impacto y se busca la racha más larga de eventos seguidos (si hay empate, la que empieza primero). También se cuentan los eventos de cada columna. La fila prioritaria se elige por racha, luego impacto, luego eventos y luego el menor número de fila. La columna destacada es la de más eventos, y en empate la menor.

## Compilación y ejecución
Sistema: Windows, con Git Bash y VS Code. Compilador: gcc 15.2.0 (MSYS2).

```bash
gcc -std=c11 -Wall -Wextra 20260293.c -o reto
./reto < 20260293/pruebas/caso_01.in
```

## Diseño
El análisis y el pseudocódigo están en `analisis/`.

## Pruebas
Los casos de entrada y salida esperada están en `20260293/pruebas/`.
Mis resultados, la prueba de escritorio y dos pruebas propias justificadas están en `evidencias/`.
En Windows el programa imprime `\r\n`, por eso al comparar con los archivos `.out` se quita el `\r` con `tr -d '\r'`.

## Estado actual
El programa está completo y cumple las validaciones, eventos, impactos, rachas, conteo por columna, prioridad y columna destacada. Los 17 casos oficiales dan el resultado esperado y compila sin warnings. No tengo errores conocidos.