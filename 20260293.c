#include <stdio.h>

int main(void)
{
    int N, M, L, U;
    int matriz[30][30];
    int i, j;
    int eventos_fila[30], impacto_fila[30], eventos_col[30];
    int f, x, dif;

    /* Se leen las dimensiones y se validan antes de leer cualquier otro dato */
    scanf("%d %d", &N, &M);
    if (N < 1 || N > 30 || M < 1 || M > 30) {
        printf("ERROR\n");
        return 0;
    }

    /* Se leen los limites de la reduccion y se validan */
    scanf("%d %d", &L, &U);
    if (L < 0 || L > U || U > 1000) {
        printf("ERROR\n");
        return 0;
    }

    /* Se carga la matriz y cada valor se valida al leerlo */
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
                printf("ERROR\n");
                return 0;
            }
        }
    }
        /* Se limpia el vector de eventos por columna */
    for (j = 0; j < M; j++) {
        eventos_col[j] = 0;
    }

    /* Se analiza cada fila usando como referencia su primer valor */
    for (i = 0; i < N; i++) {
        f = matriz[i][0];
        eventos_fila[i] = 0;
        impacto_fila[i] = 0;

        for (j = 0; j < M; j++) {
            x = matriz[i][j];
            dif = f - x;

            /* Regla del reto: la primera columna nunca genera evento */
            if (j >= 1 && dif >= L && dif <= U) {
                eventos_fila[i]++;
                impacto_fila[i] += dif + 1;
                eventos_col[j]++;
            }
        }

        /* Salida temporal para comprobar esta etapa */
        printf("FILA %d EVENTOS %d IMPACTO %d\n", i + 1, eventos_fila[i], impacto_fila[i]);
    }
    return 0;
}

