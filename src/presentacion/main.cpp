#include "MenuUI.h"
#include "../negocio/MenuService.h"
#include "../negocio/OrdenarPorNombre.h"
#include "../datos/MenuRepositoryMemoria.h"

// Definición del miembro estático de MenuService (Singleton)
MenuService* MenuService::instance = nullptr;

int main() {
    IMenuRepository* repo = new MenuRepositoryMemoria();
    IOrdenamientoEstrategia* estrategia = new OrdenarPorNombre();

    MenuService* service = MenuService::getInstance(repo, estrategia);
    MenuFacade facade(service);
    MenuUI ui(&facade);

    ui.mostrarMenuPrincipal();
    return 0;
}
