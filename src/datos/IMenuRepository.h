#pragma once
#include <vector>
#include <string>
#include "../negocio/Plato.h"

class IMenuRepository {
public:
    virtual void agregar(const Plato& p) = 0;
    virtual bool eliminarPorNombre(const std::string& nombre) = 0;
    virtual std::vector<Plato> obtenerTodos() const = 0;
    virtual ~IMenuRepository() = default;
};
