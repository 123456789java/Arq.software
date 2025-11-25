#pragma once
#include <string>

class Plato {
    std::string nombre;
public:
    Plato(const std::string& n) : nombre(n) {}
    const std::string& getNombre() const { return nombre; }
};
