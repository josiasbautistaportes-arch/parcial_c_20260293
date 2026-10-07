# Prueba de escritorio - Caso 01

Entrada:
```text
3 5 5 15
8 18 34 12 28
28 12 8 23 34
12 23 18 8 38
```
N = 3, M = 5, L = 5, U = 15.
Regla: hay evento si j >= 1 y 5 <= f-x <= 15. Impacto = f-x+1.

## Fila 1 (f = 8)
| Columna | x | f-x | Evento | Impacto |
|---|---|---|---|---|
| 1 | 8 | - | 0 (primera lectura) | 0 |
| 2 | 18 | -10 | 0 | 0 |
| 3 | 34 | -26 | 0 | 0 |
| 4 | 12 | -4 | 0 | 0 |
| 5 | 28 | -20 | 0 | 0 |

Resultado: eventos 0, impacto 0, racha 0, inicio 0.

## Fila 2 (f = 28)
| Columna | x | f-x | Evento | Impacto |
|---|---|---|---|---|
| 1 | 28 | - | 0 (primera lectura) | 0 |
| 2 | 12 | 16 | 0 (16 es mayor que 15) | 0 |
| 3 | 8 | 20 | 0 (20 es mayor que 15) | 0 |
| 4 | 23 | 5 | 1 (5 está entre 5 y 15) | 6 |
| 5 | 34 | -6 | 0 | 0 |

Resultado: eventos 1, impacto 6. La única racha es la columna 4, por eso racha 1 e inicio 4.

## Fila 3 (f = 12)
| Columna | x | f-x | Evento | Impacto |
|---|---|---|---|---|
| 1 | 12 | - | 0 (primera lectura) | 0 |
| 2 | 23 | -11 | 0 | 0 |
| 3 | 18 | -6 | 0 | 0 |
| 4 | 8 | 4 | 0 (4 es menor que 5) | 0 |
| 5 | 38 | -26 | 0 | 0 |

Resultado: eventos 0, impacto 0, racha 0, inicio 0.

## Eventos por columna
Solo hubo un evento, en la fila 2, columna 4. El vector queda: 0 0 0 1 0.

## Prioridad y columna destacada
- Solo la fila 2 tiene eventos (racha 1), así que PRIORIDAD = 2.
- La columna con más eventos es la 4 (1 evento), así que COLUMNA = 4.

## Salida final
```text
FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
FILA 2 EVENTOS 1 IMPACTO 6 RACHA 1 INICIO 4
FILA 3 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0
COLUMNAS 0 0 0 1 0
PRIORIDAD 2
COLUMNA 4
```