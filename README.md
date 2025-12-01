# Ejemplo de Arquitectura de 3 Capas en C++ – Gestor de Menú

Este proyecto implementa un **módulo de gestión de menú de restaurante** usando:

- Arquitectura de **3 capas** (presentación, negocio y acceso a datos).
- **Principios SOLID**.
- Patrones de diseño:
  - Creacional: **Singleton**
  - Estructural: **Facade**
  - Comportamiento: **Strategy**

---

## 1. Resumen del caso de uso y funcionalidades

El sistema es un **gestor de menú de restaurante** que permite administrar los platos disponibles desde una interfaz de consola.

**Caso de uso principal:**  
El administrador del restaurante puede **gestionar el menú** de platos.

**Funcionalidades implementadas:**

1. **Agregar plato al menú**
   - El usuario ingresa el nombre del plato.
   - El sistema registra el nuevo plato en el repositorio en memoria.
   - Muestra un mensaje de confirmación.

2. **Eliminar plato del menú**
   - El usuario indica el nombre del plato a eliminar.
   - Si el plato existe, se elimina del menú y se muestra un mensaje.
   - Si no existe, se informa al usuario.

3. **Mostrar menú actual**
   - El sistema recupera todos los platos almacenados.
   - Aplica una estrategia de ordenamiento (por nombre).
   - Muestra el menú en consola.

4. **Salir del sistema**
   - Permite cerrar la aplicación desde el menú principal.

---

## 2. Arquitectura de 3 capas

La aplicación está organizada en una arquitectura de **tres capas**:

- **Capa de Presentación (`presentacion`)**  
  Encargada de la interacción con el usuario mediante la consola.
  - Muestra el menú de opciones.
  - Recibe la entrada del usuario.
  - Llama a la lógica de negocio a través de una fachada.

- **Capa de Lógica de Negocio (`negocio`)**  
  Contiene las reglas de negocio y la lógica principal del sistema.
  - Gestión de platos (agregar, eliminar, listar).
  - Aplicación de la estrategia de ordenamiento del menú.
  - Implementación de patrones de diseño (Singleton, Facade, Strategy).

- **Capa de Acceso a Datos (`datos`)**  
  Gestiona cómo se almacenan y se recuperan los platos.
  - Implementación de un repositorio en memoria mediante `std::vector`.

---

## 3. Tecnologías usadas

- **Lenguaje:** C++  
- **Entorno/IDE:** Visual Studio Code  
- **Compilador:** `g++` (MinGW / MSYS2)  
- **Librerías estándar usadas:**
  - `<iostream>` para entrada/salida en consola.
  - `<vector>` para almacenar la lista de platos.
  - `<string>` para manejar los nombres de los platos.
  - `<algorithm>` para búsqueda y ordenamiento.

---

## 4. Estructura de carpetas

```text
Arq.software/
└── src/
    ├── datos/
    │   ├── IMenuRepository.h
    │   └── MenuRepositoryMemoria.h
    ├── negocio/
    │   ├── IOrdenamientoEstrategia.h
    │   ├── MenuFacade.h
    │   ├── MenuService.h
    │   ├── OrdenarPorNombre.h
    │   └── Plato.h
    └── presentacion/
        ├── main.cpp
        └── MenuUI.h
