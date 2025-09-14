#include <iostream>
#include <string>
#include "Array.hpp"  // Tu implementación aquí

int main()
{
    std::cout << "=== Test 1: Default constructor ===" << std::endl;
    Array<int> a1;
    std::cout << "Size: " << a1.size() << std::endl
	<< "Expected: 0" << std::endl;
    bool exception_caught = false;
    try {
        a1[0];
    }
	catch (const std::exception& e)
	{
        exception_caught = true;
        std::cout << "OK: Exception thrown" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: Exception not thrown" << std::endl;
    }

    std::cout << "\n=== Test 2: Parametrized constructor ===" << std::endl;
    Array<int> a2(5);
    std::cout << "Size: " << a2.size() << std::endl
	<< "Expected: 5" << std::endl;
    std::cout << "First element: " << a2[0] << " | Expected: 0" << std::endl;
    std::cout << "Last element: " << a2[4] << " | Expected: 0" << std::endl;
    exception_caught = false;
    try {
        a2[5];
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Exception thrown" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: Exception thrown" << std::endl;
    }
    try {
        a2[10];
    } catch (const std::exception& e) {
        std::cout << "OK: Exception thrown" << std::endl;
    }

    std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
    Array<int> a3 = a2;  // Copia
    std::cout << "Size a2: " << a2.size() << ", Size a3: " << a3.size() << std::endl
	<< "Expected: 5 for both" << std::endl;
    a3[0] = 42;
    std::cout << "a2[0] after copy modification: " << a2[0] << " | Expected: 0" << std::endl;
    std::cout << "a3[0]: " << a3[0] << " | Expected: 42" << std::endl;
    a2[0] = 10;
    std::cout << "a3[0] after modification of original array: " << a3[0] << " | Expected: 42" << std::endl;
    std::cout << "a2[0]: " << a2[0] << " | Expected: 10" << std::endl;

    std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
    Array<int> a4(3);
    a4[0] = 99;
    a4 = a3;
    std::cout << "Size a4 after asignation: " << a4.size() << std::endl
	<< "Expected: 5" << std::endl;
    a4[1] = 100;
    std::cout << "a3[1] after modify assigned array: " << a3[1] << " | Expected: 0" << std::endl;
    std::cout << "a4[1]: " << a4[1] << " | Expected: 100" << std::endl;

    Array<int> a5;
    a5 = a5;
    std::cout << "Auto-asignation OK .Size: " << a5.size() << " | Expected: 0" << std::endl;

    std::cout << "\n=== Test 5: string ===" << std::endl;
    Array<std::string> s1;
    std::cout << "Size default string array: " << s1.size() << " | Expected: 0" << std::endl;
    Array<std::string> s2(2);
    std::cout << "Size string array: " << s2.size() << " | Expected: 2" << std::endl;
    std::cout << "s2[0]: \"" << s2[0] << "\" | Expected: \"\"" << std::endl;
    s2[0] = "Hello";
    std::cout << "s2[0] assigned: '" << s2[0] << "'" << " | Expected: Hello" << std::endl;
    Array<std::string> s3 = s2;
    s3[0] = "World";
    std::cout << "s2[0] after copy/modif: '" << s2[0] << "' | Expected: Hello" << std::endl;
    std::cout << "s3[0]: '" << s3[0] << "' | Expected: World" << std::endl;
    s2 = s3;
    std::cout << "s2[0] after asignation: '" << s2[0] << "' | Expected: World. Size: " << s2.size() << std::endl;
    exception_caught = false;
    try {
        s2[3];
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Exception string out of range" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: No exception" << std::endl;
    }

    std::cout << "\n=== Test 6: Size 0 array ===" << std::endl;
    Array<double> d1(0);
    std::cout << "Size double 0: " << d1.size() << std::endl;
    exception_caught = false;
    try {
        d1[0];
    } catch (const std::exception& e) {
        exception_caught = true;
        std::cout << "OK: Exception thrown" << std::endl;
    }
    if (!exception_caught) {
        std::cout << "ERROR: Access to empty array" << std::endl;
    }
	std::cout << "\n=== Test 7: Matrix Array<Array<int>> ===" << std::endl;
	Array<Array<int> > matrix(2);
	matrix[0] = Array<int>(3);
	matrix[1] = Array<int>(3);
	matrix[0][0] = 42;
	matrix[0][1] = 43;
	matrix[1][0] = 44;
	std::cout << "matrix[0][0]: " << matrix[0][0] << " | Expected: 42" << std::endl;
	std::cout << "matrix[0][1]: " << matrix[0][1] << " | Expected: 43)" << std::endl;
	std::cout << "matrix[1][0]: " << matrix[1][0] << " | Expected: 44)" << std::endl;
	exception_caught = false;
	try
	{
    	matrix[2][0]; // Fuera de rango en filas
	} catch (const std::exception& e) {
    	exception_caught = true;
    	std::cout << "OK: Exception out of range" << std::endl;
	}
	if (!exception_caught) {
    	std::cout << "ERROR: No exception" << std::endl;
	}
	try {
    	matrix[0][3]; // Fuera de rango en columnas
	} catch (const std::exception& e) {
    	std::cout << "OK: Exception out of range" << std::endl;
}
}