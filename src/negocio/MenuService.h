#pragma once
#include <string>
#include <vector>
#include "Plato.h"
#include "../datos/IMenuRepository.h"
#include "IOrdenamientoEstrategia.h"

class MenuService {
private:
    static MenuService* instance;
    IMenuRepository* repo;
    IOrdenamientoEstrategia* estrategia;

    // Constructor privado (Singleton)
    MenuService(IMenuRepository* r, IOrdenamientoEstrategia* e)
        : repo(r), estrategia(e) {
        // Platos iniciales (como en tu código original)
        repo->agregar(Plato("Pollo a la plancha"));
        repo->agregar(Plato("Ensalada mixta"));
        repo->agregar(Plato("Sopa de fideos"));
    }

public:
    static MenuService* getInstance(IMenuRepository* r,
                                    IOrdenamientoEstrategia* e) {
        if (instance == nullptr) {
            instance = new MenuService(r, e);
        }
        return instance;
    }

    void agregarPlato(const std::string& nombre) {
        repo->agregar(Plato(nombre));
    }

    bool eliminarPlato(const std::string& nombre) {
        return repo->eliminarPorNombre(nombre);
    }

    std::vector<Plato> obtenerMenu() const {
        auto lista = repo->obtenerTodos();
        if (estrategia) {
            estrategia->ordenar(lista);
        }
        return lista;
    }
};
