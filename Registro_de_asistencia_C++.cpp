#include <iostream>
#include <vector>
#include <string>

// Definición de la estructura Asistencia
struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};

// Definición de la estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Asistencia> asistencias;  // Lista de asistencias
};

// Función para mostrar los detalles de un estudiante, incluyendo asistencias
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << "" << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    // Mostrar asistencias
    std::cout << "Asistencias:\n";
    for (const Asistencia& asistencia : estudiante.asistencias) {
        std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia
                  << ", Estado: " << asistencia.estado << std::endl;
    }
}

// Función para registrar la asistencia de un estudiante
void registrarAsistencia(Estudiante& estudiante, const std::string& fecha,
                         const std::string& materia, const std::string& estado) {
    Asistencia nuevaAsistencia = {fecha, materia, estado};
    estudiante.asistencias.push_back(nuevaAsistencia);
    std::cout << "Asistencia registrada con exito.\n";
}

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    int opcion;

    do {
        std::cout << "\n--- Menu ---" << std::endl;
        std::cout << "1. Mostrar detalles del estudiante" << std::endl;
        std::cout << "2. Registrar nueva asistencia" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEstudiante(estudiante1);
                break;
            case 2:
            {
                std::string fecha, materia, estado;
                std::cout << "Ingrese la fecha de la asistencia (YYYY-MM-DD): ";
                std::cin >> fecha;
                std::cout << "Ingrese la materia: ";
                std::cin.ignore();  // Limpiar el buffer del teclado
                std::getline(std::cin, materia);
                std::cout << "Ingrese el estado (Asistio, Falta, Tardanza): ";
                std::cin >> estado;

                registrarAsistencia(estudiante1, fecha, materia, estado);
            }
                break;
            case 0:
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opcion no válida. Intentalo de nuevo." << std::endl;
        }
    } while (opcion != 0);

    return 0;
}
