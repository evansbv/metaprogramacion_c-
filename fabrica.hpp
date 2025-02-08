#ifndef FABRICA_HPP
#define FABRICA_HPP

#include <iostream>
#include <unordered_map>
#include <functional>
#include <memory>
#include <type_traits>

// =========================
// SISTEMA DE REGISTRO DE CLASES Y MÉTODOS CON TEMPLATES Y SFINAE
// =========================

class ObjetoBase {
public:
    virtual ~ObjetoBase() = default;
};

// Registro global de clases y métodos
class Fabrica {
private:
    using Constructor = std::function<std::shared_ptr<ObjetoBase>()>;
    using Metodo = std::function<void(ObjetoBase*)>;

    std::unordered_map<std::string, Constructor> clases;
    std::unordered_map<std::string, Metodo> metodos;

public:
    static Fabrica& instancia() {
        static Fabrica instancia;
        return instancia;
    }

    // Registrar una clase
    template <typename T>
    void registrarClase(const std::string& nombre) {
        static_assert(std::is_base_of<ObjetoBase, T>::value, "T debe heredar de ObjetoBase");
        clases[nombre] = []() { return std::make_shared<T>(); };
    }

    // Crear una instancia de una clase
    std::shared_ptr<ObjetoBase> crear(const std::string& nombre) {
        if (clases.find(nombre) != clases.end()) {
            return clases[nombre]();
        }
        throw std::runtime_error("Clase no registrada: " + nombre);
    }

    // Registrar un método si existe en la clase (SFINAE)
    template <typename T, typename = decltype(&T::mostrarInfo)>
    void registrarMetodo(const std::string& nombre) {
        metodos[nombre] = [](ObjetoBase* obj) {
            static_cast<T*>(obj)->mostrarInfo();
        };
    }

    // Invocar un método
    void invocarMetodo(const std::string& nombre, ObjetoBase* objeto) {
        if (metodos.find(nombre) != metodos.end()) {
            metodos[nombre](objeto);
        } else {
            throw std::runtime_error("Método no registrado: " + nombre);
        }
    }
};

// =========================
// MACROS PARA REGISTRO AUTOMÁTICO
// =========================

#define REGISTRAR_CLASE(T) Fabrica::instancia().registrarClase<T>(#T)
#define REGISTRAR_METODO(T, METODO) Fabrica::instancia().registrarMetodo<T>(#T "::" #METODO)

#endif // FABRICA_HPP
