# Pruebas propias

## Prueba propia 1: racha larga, rachas separadas y empate de columnas

Entrada:
```text
2 6 2 5
10 7 8 5 10 7
9 6 9 6 9 6
```

Salida esperada:
```text
FILA 1 EVENTOS 4 IMPACTO 17 RACHA 3 INICIO 2
FILA 2 EVENTOS 3 IMPACTO 12 RACHA 1 INICIO 2
COLUMNAS 0 2 1 2 0 2
PRIORIDAD 1
COLUMNA 2
```

Justificación:
- En la fila 1, f = 10. Las columnas 2, 3 y 4 son eventos seguidos (diferencias 3, 2 y 5). La racha es de 3 y empieza en la columna 2. La columna 5 vale 10, la diferencia es 0 y corta la racha. La columna 6 es otro evento, pero su racha es de solo 1.
- En la fila 2, f = 9. Los eventos están separados por valores iguales a f, así que ninguna racha pasa de 1 y se queda la primera (inicio 2).
- Las columnas 2, 4 y 6 tienen 2 eventos cada una. Gana la menor, la 2.
- La fila 1 es la prioritaria porque tiene la racha más larga.

## Prueba propia 2: desempates de la fila prioritaria

Entrada:
```text
3 4 1 10
20 15 20 12
30 21 40 22
30 21 40 22
```

Salida esperada:
```text
FILA 1 EVENTOS 2 IMPACTO 15 RACHA 1 INICIO 2
FILA 2 EVENTOS 2 IMPACTO 19 RACHA 1 INICIO 2
FILA 3 EVENTOS 2 IMPACTO 19 RACHA 1 INICIO 2
COLUMNAS 0 3 0 3
PRIORIDAD 2
COLUMNA 2
```

Justificación:
- Las tres filas tienen racha 1, así que ese criterio empata.
- La fila 1 tiene impacto 15 y las filas 2 y 3 tienen 19, así que la fila 1 queda fuera.
- Las filas 2 y 3 empatan en todo y gana la de número menor, la 2.
- El 40 de la fila 2 es mayor que f y el 20 de la fila 1 es igual a f, así que ninguno es evento.
- Las columnas 2 y 4 tienen 3 eventos cada una. Gana la 2.