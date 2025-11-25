#pragma once
#include "IOrdenamientoEstrategia.h"
#include <algorithm>

class OrdenarPorNombre : public IOrdenamientoEstrategia {
public:
    void ordenar(std::vector<Plato>& platos) const override {
        std::sort(platos.begin(), platos.end(),
            [](const Plato& a, const Plato& b) {
                return a.getNombre() < b.getNombre();
            });
    }
};
