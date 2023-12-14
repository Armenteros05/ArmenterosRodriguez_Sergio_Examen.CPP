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
void agregarMateria(Estudiante& estudiante, const std::string& materia) {
    estudiante.materias.push_back(materia);
}


void eliminarMateria(Estudiante& estudiante, const std::string& materia) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), materia);
    if (it != estudiante.materias.end()) {
        estudiante.materias.erase(it);
    }
}
int main() {
    // Creación de un objeto Estudiante
    Estudiante estudiante1;

    // Asignación de valores a los campos
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    // Agregar materias
    agregarMateria(estudiante1, "Matemáticas");
    agregarMateria(estudiante1, "Programación");
    agregarMateria(estudiante1, "Inglés");

    // Mostrar detalles del estudiante
    mostrarEstudiante(estudiante1);

    // Eliminar una materia
    eliminarMateria(estudiante1, "Programación");

    // Mostrar detalles del estudiante después de eliminar una materia
    mostrarEstudiante(estudiante1);

    return 0;
}