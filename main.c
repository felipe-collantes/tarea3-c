#include <stdio.h>

int main() {
    float notas[5][3];
    int i, j;

    // INGRESO DE NOTAS CON VALIDACIÓN
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            do {
                printf("Ingrese nota estudiante %d materia %d: ", i+1, j+1);
                scanf("%f", &notas[i][j]);
            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // RESULTADOS POR ESTUDIANTE
    for(i = 0; i < 5; i++) {
        float suma = 0;
        float alta = notas[i][0];
        float baja = notas[i][0];

        for(j = 0; j < 3; j++) {
            suma += notas[i][j];

            if(notas[i][j] > alta) alta = notas[i][j];
            if(notas[i][j] < baja) baja = notas[i][j];
        }

        printf("\nEstudiante %d\n", i+1);
        printf("Promedio: %.2f\n", suma/3);
        printf("Nota mayor: %.2f\n", alta);
        printf("Nota menor: %.2f\n", baja);
    }

    // RESULTADOS POR MATERIA
    for(j = 0; j < 3; j++) {
        float suma = 0;
        float alta = notas[0][j];
        float baja = notas[0][j];
        int aprobados = 0, reprobados = 0;

        for(i = 0; i < 5; i++) {
            suma += notas[i][j];

            if(notas[i][j] > alta) alta = notas[i][j];
            if(notas[i][j] < baja) baja = notas[i][j];

            if(notas[i][j] >= 6)
                aprobados++;
            else
                reprobados++;
        }

        printf("\nMateria %d\n", j+1);
        printf("Promedio: %.2f\n", suma/5);
        printf("Nota mayor: %.2f\n", alta);
        printf("Nota menor: %.2f\n", baja);
        printf("Aprobados: %d\n", aprobados);
        printf("Reprobados: %d\n", reprobados);
    }

    return 0;
}