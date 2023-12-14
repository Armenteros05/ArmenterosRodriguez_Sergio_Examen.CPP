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