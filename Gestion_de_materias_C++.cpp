#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Definición de la estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<std::string> materias;  // Lista de materias
};

// Función para mostrar los detalles de un estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << " años" << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    // Mostrar materias
    std::cout << "Materias:";
    for (const std::string& materia : estudiante.materias) {
        std::cout << " " << materia;
    }
    std::cout << std::endl;
}

// Función para agregar una materia al estudiante
void agregarMateria(Estudiante& estudiante, const std::string& materia) {
    estudiante.materias.push_back(materia);
}

// Función para eliminar una materia del estudiante
void eliminarMateria(Estudiante& estudiante, const std::string& materia) {
    auto it = std::find(estudiante.materias.begin(), estudiante.materias.end(), materia);
    if (it != estudiante.materias.end()) {
        estudiante.materias.erase(it);
    }
}

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    int opcion;

    do {
        std::cout << "\n--- Menú ---" << std::endl;
        std::cout << "1. Mostrar detalles del estudiante" << std::endl;
        std::cout << "2. Agregar materia" << std::endl;
        std::cout << "3. Eliminar materia" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "Selecciona una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEstudiante(estudiante1);
                break;
            case 2:
            {
                std::string nuevaMateria;
                std::cout << "Ingrese el nombre de la nueva materia: ";
                std::cin >> nuevaMateria;
                agregarMateria(estudiante1, nuevaMateria);
                std::cout << "Materia agregada con éxito." << std::endl;
            }
                break;
            case 3:
            {
                std::string materiaAEliminar;
                std::cout << "Ingrese el nombre de la materia a eliminar: ";
                std::cin >> materiaAEliminar;
                eliminarMateria(estudiante1, materiaAEliminar);
                std::cout << "Materia eliminada con éxito." << std::endl;
            }
                break;
            case 0:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo." << std::endl;
        }
    } while (opcion != 0);

    return 0;
}
