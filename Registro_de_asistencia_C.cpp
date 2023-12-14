#include <stdio.h>
#include <string.h>

// Definición de la estructura Asistencia
struct Asistencia {
    char fecha[11];  // YYYY-MM-DD + null terminator
    char materia[50];
    char estado[20];
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Asistencia asistencias[50];  // Lista de asistencias (máximo 50 asistencias)
    int numAsistencias;  // Número actual de asistencias
};

// Función para mostrar los detalles de un estudiante, incluyendo asistencias
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d años\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    // Mostrar asistencias
    printf("Asistencias:\n");
    for (int i = 0; i < estudiante->numAsistencias; ++i) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}

// Función para registrar la asistencia de un estudiante
void registrarAsistencia(struct Estudiante* estudiante,
                         const char* fecha, const char* materia, const char* estado) {
    if (estudiante->numAsistencias < 50) {
        strcpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
        strcpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado);
        estudiante->numAsistencias++;
        printf("Asistencia registrada con exito.\n");
    } else {
        printf("No se pueden registrar mas asistencias. Limite alcanzado.\n");
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
        printf("\n--- Menu ---\n");
        printf("1. Mostrar detalles del estudiante\n");
        printf("2. Registrar nueva asistencia\n");
        printf("0. Salir\n");

        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarEstudiante(&estudiante1);
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

                registrarAsistencia(&estudiante1, fecha, materia, estado);
            }
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no válida. Intentalo de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

