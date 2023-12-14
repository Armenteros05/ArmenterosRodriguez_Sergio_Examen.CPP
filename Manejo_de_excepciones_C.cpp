#include <stdio.h>
#include <string.h>

struct Asistencia {
    char fecha[11];
    char materia[50];
    char estado[20];
};

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia asistencias[50];
    int numAsistencias;
};

int registrarAsistencia(struct Estudiante* estudiante,
                        const char* fecha, const char* materia, const char* estado) {

    if (strlen(fecha) != 10 || fecha[4] != '-' || fecha[7] != '-') {
        printf("Error: Formato de fecha incorrecto. Utilice YYYY-MM-DD.\n");
        return 1;
    }

    int materiaRegistrada = 0;
    for (int i = 0; i < estudiante->numAsistencias; ++i) {
        if (strcmp(estudiante->asistencias[i].materia, materia) == 0) {
            materiaRegistrada = 1;
            break;
        }
    }

    if (!materiaRegistrada) {
        printf("Error: La materia no esta registrada para este estudiante.\n");
        return 1;
    }

    if (estudiante->numAsistencias < 50) {
        strcpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado);
        estudiante->numAsistencias++;
        printf("Asistencia registrada con exito.\n");
        return 0;  // Éxito
    } else {
        printf("Error: No se pueden registrar más asistencias. Limite alcanzado.\n");
        return 1;  // Código de error
    }
}

int main() {
    struct Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    estudiante1.numAsistencias = 0;

    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Mostrar detalles del estudiante\n");
        printf("2. Registrar nueva asistencia\n");
        printf("0. Salir\n");

        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nDetalles del estudiante:\n");
                printf("-----------------------\n");
                printf("Nombre: %s\n", estudiante1.nombre);
                printf("Edad: %d años\n", estudiante1.edad);
                printf("Promedio: %.2f\n", estudiante1.promedio);
                printf("Asistencias registradas: %d\n", estudiante1.numAsistencias);
                break;
            case 2:
            {
                char fecha[11];
                char materia[50];
                char estado[20];
                printf("Ingrese la fecha de la asistencia (YYYY-MM-DD): ");
                scanf("%s", fecha);
                printf("Ingrese la materia: ");
                scanf("%s", materia);
                printf("Ingrese el estado (Asistio, Falta, Tardanza): ");
                scanf("%s", estado);

                int resultado = registrarAsistencia(&estudiante1, fecha, materia, estado);
                if (resultado != 0) {
                    printf("No se pudo registrar la asistencia. Intentelo de nuevo.\n");
                }
            }
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }

    } while (opcion != 0);

    return 0;
}
