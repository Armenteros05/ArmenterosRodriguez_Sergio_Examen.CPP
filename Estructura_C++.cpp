#include <iostream>
#include <string>

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
};
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << "" << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}
int main() {
    Estudiante estudiante1;

    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    mostrarEstudiante(estudiante1);

    return 0;
}