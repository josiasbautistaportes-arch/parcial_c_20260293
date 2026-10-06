# Análisis y diseño - Reto 18

## Entradas
- N, M: filas y columnas.
- L, U: límites de la reducción.
- Matriz de N x M enteros (tickets pendientes).

## Salidas
- Una línea por fila: eventos, impacto, racha máxima e inicio.
- Vector de eventos por columna.
- Fila prioritaria y columna destacada (0 si no hay eventos).
- Si algún dato es inválido: solo la palabra ERROR.

## Restricciones
- 1 <= N <= 30 y 1 <= M <= 30
- 0 <= L <= U <= 1000
- 0 <= valor <= 1000
- Todos los índices que se muestran son desde 1.

## Variables y arreglos
- matriz[30][30]: datos originales (no se modifica).
- eventos_fila[30], impacto_fila[30], racha_fila[30], inicio_fila[30]
- eventos_col[30]
- f (primer valor de la fila), x (valor actual), dif = f - x
- racha_actual, inicio_actual
- prioridad, columna_destacada, mayor

## Pseudocódigo: lectura y validación
1. Leer N y M. Si N < 1 o N > 30 o M < 1 o M > 30: imprimir ERROR y terminar.
2. Leer L y U. Si L < 0 o L > U o U > 1000: imprimir ERROR y terminar.
3. Leer la matriz. Si algún valor < 0 o > 1000: imprimir ERROR y terminar.

## Pseudocódigo: eventos e impacto
Para cada fila i:
- f = matriz[i][0]; eventos = 0; impacto = 0
- Para j desde 1 hasta M-1:
  - x = matriz[i][j]; dif = f - x
  - Si dif >= L y dif <= U: es evento
    - eventos = eventos + 1
    - impacto = impacto + dif + 1
    - eventos_col[j] = eventos_col[j] + 1

## Pseudocódigo: rachas
Dentro del mismo recorrido de la fila:
- Si hay evento:
  - Si racha_actual == 0: inicio_actual = j + 1
  - racha_actual = racha_actual + 1
  - Si racha_actual > racha_fila[i]: racha_fila[i] = racha_actual e inicio_fila[i] = inicio_actual
- Si no hay evento: racha_actual = 0
- Se usa ">" estricto para que, en empate, se conserve la racha que empezó primero.
- Si no hay eventos, racha e inicio quedan en 0.

## Pseudocódigo: prioridad y columna destacada
- prioridad = 0
- Para cada fila i con eventos > 0: es mejor que la actual si tiene mayor racha; en empate, mayor impacto; en empate, más eventos. Con comparaciones estrictas, el empate absoluto deja la fila menor.
- columna_destacada = 0, mayor = 0
- Para cada columna j: si eventos_col[j] > mayor, se actualiza (el ">" estricto deja la columna menor en empate).