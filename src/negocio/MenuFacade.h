#pragma once
#include <string>
#include <iostream>
#include "MenuService.h"

class MenuFacade {
    MenuService* service;

public:
    MenuFacade(MenuService* s) : service(s) {}

    void agregarPlato(const std::string& nombre) {
        service->agregarPlato(nombre);
        std::cout << "Plato agregado: " << nombre << std::endl;
    }

    void eliminarPlato(const std::string& nombre) {
        if (service->eliminarPlato(nombre)) {
            std::cout << "Plato eliminado: " << nombre << std::endl;
        } else {
            std::cout << "El plato no existe en el menu.\n";
        }
    }

    void mostrarMenu() {
        auto lista = service->obtenerMenu();
        std::cout << "\n---- MENU DEL RESTAURANTE ----\n";
        for (const auto& p : lista) {
            std::cout << "- " << p.getNombre() << std::endl;
        }
    }
};
