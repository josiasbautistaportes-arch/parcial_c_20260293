/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Josías Bautista                             */
/*  Matricula: 2026-0293                                   */
/*  Seccion:   Sábados (9-12pm)                            */
/*  Practica:  Primer examen parcial                       */
/*  Fecha:     07/10/2026                                  */                       
/* Link Practica:                                          */
/***********************************************************/


#include <stdio.h>

int main(void)
{
    int N, M, L, U;
    int matriz[30][30];
    int i, j;
    int eventos_fila[30], impacto_fila[30], eventos_col[30];
    int f, x, dif;
    int racha_fila[30], inicio_fila[30];
    int racha_actual, inicio_actual;
    int prioridad, columna, mayor;

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
        racha_fila[i] = 0;
        inicio_fila[i] = 0;
        racha_actual = 0;
        inicio_actual = 0;

        for (j = 0; j < M; j++) {
            x = matriz[i][j];
            dif = f - x;

            /* Regla del reto: la primera columna nunca genera evento */
            if (j >= 1 && dif >= L && dif <= U) {
                eventos_fila[i]++;
                impacto_fila[i] += dif + 1;
                eventos_col[j]++;

                /* Si empieza una racha nueva se guarda su columna (base 1) */
                if (racha_actual == 0) {
                    inicio_actual = j + 1;
                }
                racha_actual++;

                /* Solo se reemplaza si es mayor, asi se conserva la que empezo primero */
                if (racha_actual > racha_fila[i]) {
                    racha_fila[i] = racha_actual;
                    inicio_fila[i] = inicio_actual;
                }
            } else {
                /* Una posicion sin evento interrumpe la racha */
                racha_actual = 0;
            }
        }

        printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
               i + 1, eventos_fila[i], impacto_fila[i], racha_fila[i], inicio_fila[i]);
    }
        /* Vector con la cantidad de eventos de cada columna */
    printf("COLUMNAS");
    for (j = 0; j < M; j++) {
        printf(" %d", eventos_col[j]);
    }
    printf("\n");

        /* Fila prioritaria: racha, luego impacto, luego eventos; en empate se queda la menor */
    prioridad = 0;
    for (i = 0; i < N; i++) {
        if (eventos_fila[i] > 0) {
            if (prioridad == 0
                || racha_fila[i] > racha_fila[prioridad - 1]
                || (racha_fila[i] == racha_fila[prioridad - 1]
                    && impacto_fila[i] > impacto_fila[prioridad - 1])
                || (racha_fila[i] == racha_fila[prioridad - 1]
                    && impacto_fila[i] == impacto_fila[prioridad - 1]
                    && eventos_fila[i] > eventos_fila[prioridad - 1])) {
                prioridad = i + 1;
            }
        }
    }

    /* Columna destacada: la de mas eventos; en empate, la menor */
    columna = 0;
    mayor = 0;
    for (j = 0; j < M; j++) {
        if (eventos_col[j] > mayor) {
            mayor = eventos_col[j];
            columna = j + 1;
        }
    }

    printf("PRIORIDAD %d\n", prioridad);
    printf("COLUMNA %d\n", columna);
    
    return 0;
}

