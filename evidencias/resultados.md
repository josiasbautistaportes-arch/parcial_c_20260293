# Resultados de los 17 casos oficiales

Se compiló con `gcc -std=c11 -Wall -Wextra 20260293.c -o reto` y se probó cada caso con:

```bash
./reto < 20260293/pruebas/caso_XX.in
```

En Windows con Git Bash el programa imprime los saltos de línea como `\r\n`. Por eso, al comparar con el archivo `.out` se quitó el `\r` con `tr -d '\r'`.

| Caso | Objetivo | Resultado |
|---|---|---|
| 01 | Ejemplo explicado | OK |
| 02 | Dimensión mínima: 1 x 1 | OK |
| 03 | Igualdad con límites y meseta | OK |
| 04 | Una fila, cambios y valores extremos | OK |
| 05 | Una columna, comparación entre filas | OK |
| 06 | Empates, rachas separadas y final de fila | OK |
| 07 | Límites: debajo, igual y encima | OK |
| 08 | Matriz máxima 30 x 30 | OK |
| 09 | Dimensión inválida: cero | OK |
| 10 | Dimensión inválida: más de 30 | OK |
| 11 | Límites invertidos | OK |
| 12 | Límite fuera de rango | OK |
| 13 | Matriz con valor negativo | OK |
| 14 | Matriz con valor mayor que 1000 | OK |
| 15 | Límite superior inválido | OK |
| 16 | Eventos activos de la regla particular | OK |
| 17 | Ausencia total de eventos | OK |

Resultado: los 17 casos coinciden con la salida esperada.