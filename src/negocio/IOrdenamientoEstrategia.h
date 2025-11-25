#pragma once
#include <vector>
#include "Plato.h"

class IOrdenamientoEstrategia {
public:
    virtual void ordenar(std::vector<Plato>& platos) const = 0;
    virtual ~IOrdenamientoEstrategia() = default;
};
