#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d \n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
}

int main() {

    struct Estudiante estudiante1;

    snprintf(estudiante1.nombre, sizeof(estudiante1.nombre), "Juan");
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;


    mostrarEstudiante(&estudiante1);

    return 0;
}
