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