#include "clases.hpp"

int main() {
    try {
        // Crear objetos dinámicamente
        std::shared_ptr<ObjetoBase> usuario = Fabrica::instancia().crear("Usuario");
        std::shared_ptr<ObjetoBase> admin = Fabrica::instancia().crear("Administrador");

        // Invocar métodos reflejados
        Fabrica::instancia().invocarMetodo("Usuario::mostrarInfo", usuario.get());
        Fabrica::instancia().invocarMetodo("Administrador::mostrarInfo", admin.get());

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
