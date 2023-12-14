#include <iostream>
#include <vector>
#include <string>

struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};
struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Asistencia> asistencias;  // Lista de asistencias
};