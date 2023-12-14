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
    if (estudiante.numAsistencias < 50) {
        estudiante.asistencias[estudiante.numAsistencias] = {fecha, materia, estado};
        estudiante.numAsistencias++;
        std::cout << "Asistencia registrada con exito.\n";
    } else {
        throw AsistenciaException("No se pueden registrar mas asistencias. Limite alcanzado.");
    }
}
int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;
    estudiante1.numAsistencias = 0;

    try {
        registrarAsistencia(estudiante1, "2023-01-15", "Matematicas", "Asistio");
        registrarAsistencia(estudiante1, "2023-01-16", "Programacion", "Falta");
        registrarAsistencia(estudiante1, "2023-01-17", "Inglés", "Tardanza");
        registrarAsistencia(estudiante1, "2023-01-18", "Historia", "Asistio");
    } catch (const AsistenciaException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}