#include <gtest/gtest.h>
#include "clases.hpp"

// Test: Creación de clases registradas
TEST(FabricaTest, CrearClasesRegistradas) {
    EXPECT_NO_THROW(Fabrica::instancia().crear("Usuario"));
    EXPECT_NO_THROW(Fabrica::instancia().crear("Administrador"));
}

// Test: Creación de clases no registradas
TEST(FabricaTest, CrearClaseNoRegistrada) {
    EXPECT_THROW(Fabrica::instancia().crear("Inexistente"), std::runtime_error);
}

// Test: Invocar métodos registrados
TEST(FabricaTest, InvocarMetodosRegistrados) {
    std::shared_ptr<ObjetoBase> usuario = Fabrica::instancia().crear("Usuario");
    std::shared_ptr<ObjetoBase> admin = Fabrica::instancia().crear("Administrador");

    EXPECT_NO_THROW(Fabrica::instancia().invocarMetodo("Usuario::mostrarInfo", usuario.get()));
    EXPECT_NO_THROW(Fabrica::instancia().invocarMetodo("Administrador::mostrarInfo", admin.get()));
}

// Test: Invocar métodos no registrados
TEST(FabricaTest, InvocarMetodoNoRegistrado) {
    std::shared_ptr<ObjetoBase> usuario = Fabrica::instancia().crear("Usuario");
    EXPECT_THROW(Fabrica::instancia().invocarMetodo("Usuario::noExiste", usuario.get()), std::runtime_error);
}

// Test: Registro seguro de clases y métodos
TEST(FabricaTest, RegistroSeguro) {
    // Prueba que el compilador no permita registrar clases inválidas
    // static_assert falla si intentamos registrar una clase que no herede de ObjetoBase
    class ClaseInvalida {};

    // Esta línea generaría un error de compilación si se descomenta
    // Fabrica::instancia().registrarClase<ClaseInvalida>("ClaseInvalida");

    // Aseguramos que las clases registradas no fallen
    EXPECT_NO_THROW(REGISTRAR_CLASE(Usuario));
    EXPECT_NO_THROW(REGISTRAR_CLASE(Administrador));
    EXPECT_NO_THROW(REGISTRAR_METODO(Usuario, mostrarInfo));
    EXPECT_NO_THROW(REGISTRAR_METODO(Administrador, mostrarInfo));
}
