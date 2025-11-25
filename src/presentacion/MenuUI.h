#pragma once
#include <iostream>
#include <string>
#include "../negocio/MenuFacade.h"

class MenuUI {
    MenuFacade* facade;

public:
    MenuUI(MenuFacade* f) : facade(f) {}

    void mostrarMenuPrincipal() {
        int opcion = 0;
        std::string plato;

        while (opcion != 4) {
            std::cout << "\n===== SISTEMA DE GESTION DE MENU =====\n";
            std::cout << "1. Agregar plato\n";
            std::cout << "2. Eliminar plato\n";
            std::cout << "3. Mostrar menu\n";
            std::cout << "4. Salir\n";
            std::cout << "Elige una opcion: ";
            std::cin >> opcion;
            std::cin.ignore();

            switch (opcion) {
            case 1:
                std::cout << "Escribe el nombre del plato a agregar: ";
                std::getline(std::cin, plato);
                facade->agregarPlato(plato);
                break;
            case 2:
                std::cout << "Escribe el plato que deseas eliminar: ";
                std::getline(std::cin, plato);
                facade->eliminarPlato(plato);
                break;
            case 3:
                facade->mostrarMenu();
                break;
            case 4:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
            }
        }
    }
};
