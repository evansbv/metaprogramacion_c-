#ifndef CLASES_HPP
#define CLASES_HPP

#include "fabrica.hpp"

class Usuario : public ObjetoBase {
public:
    void mostrarInfo() {
        std::cout << "Soy un Usuario registrado en el sistema.\n";
    }
};

class Administrador : public ObjetoBase {
public:
    void mostrarInfo() {
        std::cout << "Soy un Administrador con permisos avanzados.\n";
    }
};

// =========================
// REGISTRO AUTOMÁTICO
// =========================

struct Registro {
    Registro() {
        REGISTRAR_CLASE(Usuario);
        REGISTRAR_CLASE(Administrador);
        REGISTRAR_METODO(Usuario, mostrarInfo);
        REGISTRAR_METODO(Administrador, mostrarInfo);
    }
} registro;

#endif // CLASES_HPP
