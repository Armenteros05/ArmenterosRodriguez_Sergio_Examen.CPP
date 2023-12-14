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