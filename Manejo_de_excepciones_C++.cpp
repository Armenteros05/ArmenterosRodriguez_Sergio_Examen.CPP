#include <iostream>
#include <stdexcept>
#include <string>

class AsistenciaException : public std::exception {
private:
    std::string mensaje;

public:
    AsistenciaException(const std::string& mensaje) : mensaje(mensaje) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    Asistencia asistencias[50];
    int numAsistencias;
};

void registrarAsistencia(Estudiante& estudiante, const std::string& fecha,
                         const std::string& materia, const std::string& estado) {
    if (fecha.length() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        throw AsistenciaException("Formato de fecha incorrecto. Utilice YYYY-MM-DD.");
    }
    bool materiaRegistrada = false;
    for (int i = 0; i < estudiante.numAsistencias; ++i) {
        if (estudiante.asistencias[i].materia == materia) {
            materiaRegistrada = true;
            break;
        }
    }

    if (!materiaRegistrada) {
        throw AsistenciaException("La materia no esta registrada para este estudiante.");
    }

    if (estudiante.numAsistencias < 50) {
        estudiante.asistencias[estudiante.numAsistencias] = {fecha, materia, estado};
        estudiante.numAsistencias++;
        std::cout << "Asistencia registrada con exito.\n";
    } else {
        throw AsistenciaException("No se pueden registrar más asistencias. Limite alcanzado.");
    }
}

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    estudiante1.numAsistencias = 0;

    int opcion;

    do {
        std::cout << "\n--- Menu ---" << std::endl;
        std::cout << "1. Mostrar detalles del estudiante" << std::endl;
        std::cout << "2. Registrar nueva asistencia" << std::endl;
        std::cout << "0. Salir" << std::endl;

        std::cout << "Selecciona una opcion: ";
        std::cin >> opcion;

        try {
            switch (opcion) {
                case 1:
                    std::cout << "\nDetalles del estudiante:\n";
                    std::cout << "-----------------------\n";
                    std::cout << "Nombre: " << estudiante1.nombre << std::endl;
                    std::cout << "Edad: " << estudiante1.edad << " años" << std::endl;
                    std::cout << "Promedio: " << estudiante1.promedio << std::endl;
                    std::cout << "Asistencias registradas: " << estudiante1.numAsistencias << std::endl;
                    break;
                case 2:
                {
                    std::string fecha, materia, estado;
                    std::cout << "Ingrese la fecha de la asistencia (YYYY-MM-DD): ";
                    std::cin >> fecha;
                    std::cout << "Ingrese la materia: ";
                    std::cin.ignore();
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
        } catch (const AsistenciaException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
