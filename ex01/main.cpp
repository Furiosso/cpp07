#include <iostream>
#include "Iter.hpp"

// Test functions to pass to ::iter (todas toman por referencia para coincidir con ::iter)
void print_int(int& x) {
    std::cout << x << " ";
}

void print_double(double& x) {
    std::cout << x << " ";
}

void print_char(char& x) {
    std::cout << x << " ";
}

// Funciones modificadoras (ya toman por referencia)
void increment(int& x) {
    ++x;
}

void multiply_by_two(double& x) {
    x *= 2.0;
}

void to_upper(char& x) {
    if (x >= 'a' && x <= 'z') {
        x = x - 'a' + 'A';
    }
}

int main() {
    // Test 1: Integer array with print function
    std::cout << "Test 1: Printing integer array\n";
    int int_arr[] = {1, 2, 3, 4, 5};
    size_t int_len = 5;
    ::iter(int_arr, int_len, print_int);
    std::cout << "\nExpected output: 1 2 3 4 5\n\n";

    // Test 2: Integer array with increment function
    std::cout << "Test 2: Incrementing integer array\n";
    std::cout << "Before: ";
    ::iter(int_arr, int_len, print_int);
    ::iter(int_arr, int_len, increment);
    std::cout << "\nAfter: ";
    ::iter(int_arr, int_len, print_int);
    std::cout << "\nExpected output: 2 3 4 5 6\n\n";

    // Test 3: Double array with print function
    std::cout << "Test 3: Printing double array\n";
    double double_arr[] = {1.1, 2.2, 3.3};
    size_t double_len = 3;
    ::iter(double_arr, double_len, print_double);
    std::cout << "\nExpected output: 1.1 2.2 3.3\n\n";

    // Test 4: Double array with multiply_by_two function
    std::cout << "Test 4: Multiplying double array by 2\n";
    std::cout << "Before: ";
    ::iter(double_arr, double_len, print_double);
    ::iter(double_arr, double_len, multiply_by_two);
    std::cout << "\nAfter: ";
    ::iter(double_arr, double_len, print_double);
    std::cout << "\nExpected output: 2.2 4.4 6.6\n\n";

    // Test 5: Character array with print function
    std::cout << "Test 5: Printing char array\n";
    char char_arr[] = {'a', 'b', 'c'};
    size_t char_len = 3;
    ::iter(char_arr, char_len, print_char);
    std::cout << "\nExpected output: a b c\n\n";

    // Test 6: Character array with to_upper function
    std::cout << "Test 6: Converting char array to uppercase\n";
    std::cout << "Before: ";
    ::iter(char_arr, char_len, print_char);
    ::iter(char_arr, char_len, to_upper);
    std::cout << "\nAfter: ";
    ::iter(char_arr, char_len, print_char);
    std::cout << "\nExpected output: A B C\n\n";

    // Test 7: Empty array
    std::cout << "Test 7: Empty array\n";
    int empty_arr[] = {};
    ::iter(empty_arr, 0, print_int);
    std::cout << "(no output)\n\n";

    // Test 8: Single-element array
    std::cout << "Test 8: Single-element array\n";
    int single_arr[] = {42};
    ::iter(single_arr, 1, print_int);
    std::cout << "\nExpected output: 42\n";

    return 0;
}