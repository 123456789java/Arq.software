#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class MenuSingleton {
private:
    static MenuSingleton* instance;
    std::vector<std::string> platos;

    // Constructor privado
    MenuSingleton() {
        platos.push_back("Pollo a la plancha");
        platos.push_back("Ensalada mixta");
        platos.push_back("Sopa de fideos");
    }

public:
    // Obtener unica instancia
    static MenuSingleton* getInstance() {
        if (instance == nullptr) {
            instance = new MenuSingleton();
        }
        return instance;
    }

    // Agregar plato
    void agregarPlato(const std::string& plato) {
        platos.push_back(plato);
        std::cout << "Plato agregado: " << plato << std::endl;
    }

    // Eliminar plato
    void eliminarPlato(const std::string& plato) {
        auto it = std::find(platos.begin(), platos.end(), plato);
        if (it != platos.end()) {
            platos.erase(it);
            std::cout << "Plato eliminado: " << plato << std::endl;
        } else {
            std::cout << "El plato no existe en el menu." << std::endl;
        }
    }

    // Mostrar menu
    void mostrarMenu() {
        std::cout << "\n---- MENU DEL RESTAURANTE ----\n";
        for (const auto& p : platos) {
            std::cout << "- " << p << std::endl;
        }
    }
};

// Inicializar puntero estatico
MenuSingleton* MenuSingleton::instance = nullptr;


int main() {
    MenuSingleton* menu = MenuSingleton::getInstance();
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
            menu->agregarPlato(plato);
            break;

        case 2:
            std::cout << "Escribe el plato que deseas eliminar: ";
            std::getline(std::cin, plato);
            menu->eliminarPlato(plato);
            break;

        case 3:
            menu->mostrarMenu();
            break;

        case 4:
            std::cout << "Saliendo del sistema...\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
