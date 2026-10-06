#include <stdio.h>

int main(void)
{
    int N, M, L, U;
    int matriz[30][30];
    int i, j;

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

    return 0;
}

