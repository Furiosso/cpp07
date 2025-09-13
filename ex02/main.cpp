#include <iostream>
#include <string>
#include "Array.hpp"  // Tu implementación aquí

int main()
{
    std::cout << "=== Test 1: Constructor vacío ===" << std::endl;
    ::Array<int> a1;
    std::cout << "Tamaño: " << a1.size() << std::endl;  // Esperado: 0
    bool exception_caught = false;
    try {
        a1[0];  // Debe lanzar std::exception (sin asignar a var)
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Excepción lanzada para índice fuera de rango en array vacío" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: No se lanzó excepción en array vacío" << std::endl;
    }

    std::cout << "\n=== Test 2: Constructor con tamaño n (inicialización por defecto) ===" << std::endl;
    ::Array<int> a2(5);
    std::cout << "Tamaño: " << a2.size() << std::endl;  // Esperado: 5
    std::cout << "Primer elemento: " << a2[0] << " (debería ser 0)" << std::endl;
    std::cout << "Último elemento: " << a2[4] << " (debería ser 0)" << std::endl;
    exception_caught = false;
    try {
        a2[5];  // Fuera de rango (sin var)
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Excepción lanzada para índice 5" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: No se lanzó excepción para índice fuera de rango" << std::endl;
    }
    try {
        a2[10];  // Muy fuera
    } catch (const std::exception& e) {
        std::cout << "OK: Excepción para índice muy fuera de rango" << std::endl;
    }

    std::cout << "\n=== Test 3: Constructor por copia ===" << std::endl;
    Array<int> a3 = a2;  // Copia
    std::cout << "Tamaño a2: " << a2.size() << ", Tamaño a3: " << a3.size() << std::endl;  // Ambos 5
    a3[0] = 42;
    std::cout << "a2[0] después de modificar copia: " << a2[0] << " (no debe ser 42)" << std::endl;
    std::cout << "a3[0]: " << a3[0] << " (debe ser 42)" << std::endl;
    a2[0] = 10;
    std::cout << "a3[0] después de modificar original: " << a3[0] << " (no debe ser 10)" << std::endl;
    std::cout << "a2[0]: " << a2[0] << " (debe ser 10)" << std::endl;

    std::cout << "\n=== Test 4: Operador de asignación ===" << std::endl;
    Array<int> a4(3);  // Tamaño diferente
    a4[0] = 99;  // Modificamos antes
    a4 = a3;  // Asignación
    std::cout << "Tamaño a4 después de asignación: " << a4.size() << std::endl;  // Debe ser 5
    a4[1] = 100;
    std::cout << "a3[1] después de modificar asignado: " << a3[1] << " (no debe ser 100)" << std::endl;
    std::cout << "a4[1]: " << a4[1] << " (debe ser 100)" << std::endl;

    // Test auto-asignación
    Array<int> a5;
    a5 = a5;  // No debe crashear
    std::cout << "Auto-asignación OK (tamaño: " << a5.size() << ")" << std::endl;

    std::cout << "\n=== Test 5: Con tipo std::string ===" << std::endl;
    Array<std::string> s1;  // Vacío
    std::cout << "Tamaño string vacío: " << s1.size() << std::endl;  // 0
    Array<std::string> s2(2);  // Con tamaño
    std::cout << "Tamaño string: " << s2.size() << std::endl;  // 2
    std::cout << "s2[0] por defecto: '" << s2[0] << "' (debe ser vacío)" << std::endl;
    s2[0] = "Hola";
    std::cout << "s2[0] asignado: '" << s2[0] << "'" << std::endl;
    Array<std::string> s3 = s2;  // Copia
    s3[0] = "Mundo";
    std::cout << "s2[0] después copia/modif: '" << s2[0] << "' (aún Hola)" << std::endl;
    std::cout << "s3[0]: '" << s3[0] << "' (Mundo)" << std::endl;
    s2 = s3;  // Asignación
    std::cout << "s2[0] después asignación: '" << s2[0] << "' (debe ser Mundo, tamaño " << s2.size() << ")" << std::endl;
    exception_caught = false;
    try {
        s2[3];  // Fuera de rango (sin var)
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Excepción string fuera de rango" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: No excepción string fuera de rango" << std::endl;
    }

    std::cout << "\n=== Test 6: Array de tamaño 0 con acceso ===" << std::endl;
    Array<double> d1(0);
    std::cout << "Tamaño double 0: " << d1.size() << std::endl;
    exception_caught = false;
    try {
        d1[0];  // Sin var
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Excepción en array tamaño 0" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: Acceso a array vacío sin excepción" << std::endl;
    }

    std::cout << "\n=== Todos los tests completados. Si ves solo 'OK' y tamaños correctos, ¡bien!" << std::endl;
    return 0;
}