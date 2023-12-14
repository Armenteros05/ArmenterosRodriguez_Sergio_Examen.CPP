#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    char materias[10][50];  // Lista de materias (máximo 10 materias, cada una con un máximo de 50 caracteres)
    int numMaterias;  // Número actual de materias
};

// Función para mostrar los detalles de un estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d \n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    // Mostrar materias
    printf("Materias:");
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        printf(" %s", estudiante->materias[i]);
    }
    printf("\n");
}

// Función para agregar una materia al estudiante
void agregarMateria(struct Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < 10) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
    } else {
        printf("No se pueden agregar mas materias. Limite alcanzado.\n");
    }
}

// Función para eliminar una materia del estudiante
void eliminarMateria(struct Estudiante* estudiante, const char* materia) {
    for (int i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            // Desplazar las materias restantes para llenar el espacio eliminado
            for (int j = i; j < estudiante->numMaterias - 1; ++j) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            return;
        }
    }
    printf("La materia \"%s\" no se encontro.\n", materia);
}

int main() {
    struct Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    estudiante1.numMaterias = 0;

    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Mostrar detalles del estudiante\n");
        printf("2. Agregar materia\n");
        printf("3. Eliminar materia\n");
        printf("0. Salir\n");

        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarEstudiante(&estudiante1);
                break;
            case 2:
            {
                char nuevaMateria[50];
                printf("Ingrese el nombre de la nueva materia: ");
                scanf("%s", nuevaMateria);
                agregarMateria(&estudiante1, nuevaMateria);
                printf("Materia agregada con exito.\n");
            }
                break;
            case 3:
            {
                char materiaAEliminar[50];
                printf("Ingrese el nombre de la materia a eliminar: ");
                scanf("%s", materiaAEliminar);
                eliminarMateria(&estudiante1, materiaAEliminar);
                printf("Materia eliminada con exito.\n");
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
