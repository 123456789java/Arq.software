#pragma once
#include "IMenuRepository.h"
#include <vector>
#include <algorithm>

class MenuRepositoryMemoria : public IMenuRepository {
    std::vector<Plato> platos;

public:
    void agregar(const Plato& p) override {
        platos.push_back(p);
    }

    bool eliminarPorNombre(const std::string& nombre) override {
        auto it = std::find_if(platos.begin(), platos.end(),
            [&](const Plato& p) { return p.getNombre() == nombre; });

        if (it != platos.end()) {
            platos.erase(it);
            return true;
        }
        return false;
    }

    std::vector<Plato> obtenerTodos() const override {
        return platos;
    }
};
