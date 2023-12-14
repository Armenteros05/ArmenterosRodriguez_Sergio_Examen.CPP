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
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << " años" << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    std::cout << "Asistencias:\n";
    for (const Asistencia& asistencia : estudiante.asistencias) {
        std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia
                  << ", Estado: " << asistencia.estado << std::endl;
    }
}
void registrarAsistencia(Estudiante& estudiante, const std::string& fecha,
                         const std::string& materia, const std::string& estado) {
    Asistencia nuevaAsistencia = {fecha, materia, estado};
    estudiante.asistencias.push_back(nuevaAsistencia);
    std::cout << "Asistencia registrada con éxito.\n";
}
int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 8.5;

    registrarAsistencia(estudiante1, "2023-01-15", "Matemáticas", "Asistió");
    registrarAsistencia(estudiante1, "2023-01-16", "Programación", "Falta");
    registrarAsistencia(estudiante1, "2023-01-17", "Inglés", "Tardanza");

    mostrarEstudiante(estudiante1);

    return 0;
}