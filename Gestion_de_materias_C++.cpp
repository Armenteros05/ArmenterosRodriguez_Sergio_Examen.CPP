#include <iostream>
#include <string>
#include <vector>

struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;  // Lista de materias
};
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << " años" << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
    std::cout << "Materias:";
    for (const std::string& materia : estudiante.materias) {
        std::cout << " " << materia;
    }
    std::cout << std::endl;
}