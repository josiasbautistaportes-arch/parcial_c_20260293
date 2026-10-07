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
- En la fila 1, f = 10. Las columnas 2, 3 y 4 son eventos seguidos (diferencias 3, 2 y 5, que tocan los dos límites). Eso da racha 3 con inicio en la columna 2. La columna 5 vale 10, la diferencia es 0 y rompe la racha, y la columna 6 forma otra racha de 1.
- En la fila 2, f = 9. Los eventos están separados por valores iguales a f, así que ninguna racha pasa de 1 y se conserva la primera (inicio 2).
- Las columnas 2, 4 y 6 empatan con 2 eventos. Se elige la menor, la columna 2.
- La fila 1 gana la prioridad por tener mayor racha.

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
- Las tres filas tienen racha 1, así que el primer criterio empata.
- La fila 1 tiene impacto 15 y las filas 2 y 3 tienen impacto 19. La fila 1 queda descartada por el segundo criterio.
- Las filas 2 y 3 empatan en racha, impacto y eventos, y gana la de menor número: la 2.
- El valor 40 de la fila 2 es mayor que f, y el valor 20 de la fila 1 es igual a f. Ninguno genera evento.
- Las columnas 2 y 4 empatan con 3 eventos, y se elige la menor: la 2.