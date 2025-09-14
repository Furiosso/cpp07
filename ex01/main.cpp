#include <iostream>
#include <string>
#include <cctype>
#include "Iter.hpp"

// Simple template function to instantiate and pass to ::iter
template <typename T>
void template_print(const T x) {
    std::cout << x << " ";
}

template <typename T>
void template_increment(T& x) {
    x += 1;
}

void print_int(const int x) {
    std::cout << x << " ";
}

void print_double(const double x) {
    std::cout << x << " ";
}

void print_char(const char x) {
    std::cout << x << " ";
}

void print_string(const std::string& x) {
    std::cout << x << " ";
}

void print_ptr(const void* x) {
    std::cout << x << " ";
}

void increment_int(int& x) {
    ++x;
}

void multiply_double(double& x) {
    x *= 2.0;
}

void to_upper_char(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = std::toupper(c);
    }
}

void prepend_hello_string(std::string& x) {
    x = "hello_" + x;
}

int main() {
    int				int_arr[] = {1, 2, 3, 4, 5};
    double			double_arr[] = {1.1, 2.2, 3.3};
    char			char_arr[] = {'a', 'b', 'c'};
    std::string		str_arr[] = {"one", "two", "three"};
	void*			ptr_arr[] = {int_arr, double_arr, char_arr, str_arr};
	std::string*	str_ptr_arr[] = {str_arr, &str_arr[1], &str_arr[2]};
	size_t		len;

    // Test 1: Basic integer array with print function
    std::cout << "Test 1: Printing integer array" << std::endl;
    len = 5;
	std::cout << "Result:   ";
    ::iter(int_arr, len, print_int);
    std::cout << std::endl << "Expected: 1 2 3 4 5" << std::endl << std::endl;

    // Test 2: Double array with print function
    std::cout << "Test 2: Printing double array" << std::endl;
    len = 3;
	std::cout << "Result:   ";
    ::iter(double_arr, len, print_double);
    std::cout << std::endl << "Expected: 1.1 2.2 3.3" << std::endl << std::endl;

    // Test 3: Character array with print function
    std::cout << "Test 3: Printing char array" << std::endl;
    len = 3;
	std::cout << "Result:   ";
    ::iter(char_arr, len, print_char);
    std::cout << std::endl << "Expected: a b c" << std::endl << std::endl;

    // Test 4: String array with print function
    std::cout << "Test 4: Printing string array" << std::endl;
    len = 3;
	std::cout << "Result:   ";
    ::iter(str_arr, len, print_string);
    std::cout << std::endl << "Expected: one two three" << std::endl << std::endl;

    // Test 5: Pointer array with print function
    std::cout << "Test 5: Printing pointer array" << std::endl;
    len = 4;
	std::cout << "Result:   ";
    ::iter(ptr_arr, len, print_ptr);
    std::cout << std::endl << "Expected: " << int_arr << " " << double_arr << " "
	<< static_cast<void*>(char_arr) << " " << static_cast<void*>(str_arr) << std::endl << std::endl;

    // Test 6: Instantiated template function on integer array (print)
    std::cout << "Test 6: Instantiated template function on integer array (print)" << std::endl;
	len = 5;
    ::iter(int_arr, len, ::template_increment<int>);
	std::cout << "Result:   ";
	::iter(int_arr, len, print_int);
    std::cout << std::endl << "Expected: 2 3 4 5 6" << std::endl << std::endl;

    // Test 7: Instantiated template function on double array (print)
    std::cout << "Test 7: Instantiated template function on double array (print)" << std::endl;
	len = 3;
	std::cout << "Result:   ";
    ::iter(double_arr, len, ::template_print<double>);
    std::cout << std::endl << "Expected: 1.1 2.2 3.3" << std::endl << std::endl;

    // Test 8: Instantiated template function on string array (print)
    std::cout << "Test 8: Instantiated template function on string array (print)" << std::endl;
	len = 3;
	std::cout << "Result:   ";
    ::iter(str_arr, len, ::template_print<std::string>);
    std::cout << std::endl << "Expected: one two three" << std::endl << std::endl;

    // Test 9: Instantiated template function on void pointer array (print)
    std::cout << "Test 9: Instantiated template function on void pointer array (print)" << std::endl;
	len = 4;
	std::cout << "Result:   ";
    ::iter(ptr_arr, len, ::template_print<void*>);
    std::cout << std::endl << "Expected: " << int_arr << " " << double_arr << " "
	<< static_cast<void*>(char_arr) << " " << static_cast<void*>(str_arr) << std::endl << std::endl;

    // Test 10: Instantiated template function on pointer array (print)
    std::cout << "Test 10: Instantiated template function on pointer array (print)" << std::endl;
	len = 3;
	std::cout << "Result:   ";
    ::iter(str_ptr_arr, len, ::template_print<std::string*>);
    std::cout << std::endl << "Expected: " << str_ptr_arr[0] << " "
	<< str_ptr_arr[1] << " "
	<< str_ptr_arr[2] << std::endl << std::endl;

    // Test 11: Empty array with print function
    std::cout << "Test 11: Empty array" << std::endl;
    int empty_arr[] = {};
    len = 0;
    ::iter(empty_arr, len, print_int);
    std::cout << "(no output)" << std::endl << std::endl;

    // Test 12: Single-element array with print function
    std::cout << "Test 12: Single-element array" << std::endl;
    int single_arr[] = {42};
    len = 1;
	std::cout << "Result:   ";
    ::iter(single_arr, len, print_int);
    std::cout << std::endl << "Expected: 42" << std::endl << std::endl;

    // Test 13: Modifying operations on integer array (demonstration)
    std::cout << "Test 13: Modifying operations on integer array" << std::endl;
	std::cout << "Before: ";
	len = 5;
	::iter(int_arr, len, print_int);
    ::iter(int_arr, len, increment_int);
	std::cout << std::endl << "After: ";
	::iter(int_arr, len, print_int);
    std::cout << std::endl << "Expected: 2 3 4 5 6" << std::endl << std::endl;

    // Test 14: modifying operations on double array
    std::cout << "Test 14: modifying operations on double array" << std::endl;
	std::cout << "Before: ";
	len = 3;
	::iter(double_arr, len, print_double);
	std::cout << std::endl << "After: ";
    ::iter(double_arr, len, multiply_double);
	::iter(double_arr, len, print_double);
    std::cout << std::endl << "Expected: 2.2 4.4 6.6 " << std::endl << std::endl;

    // Test 15: modifying operations on char array
    std::cout << "Test 15: modifying operations on char array" << std::endl;
	std::cout << "Before: ";
	len = 3;
	::iter(char_arr, len, print_char);
	std::cout << std::endl << "After: ";
    ::iter(char_arr, len, to_upper_char);
	::iter(char_arr, len, print_char);
    std::cout << std::endl << "Expected: A B C " << std::endl << std::endl;

    // Test 16: modifying operations on string array
    std::cout << "Test 16: modifying operations on string array" << std::endl;
	std::cout << "Before: ";
	len = 3;
	::iter(str_arr, len, print_string);
	std::cout << std::endl << "After: ";
    ::iter(str_arr, len, prepend_hello_string);
	::iter(str_arr, len, print_string);
    std::cout << std::endl << "Expected: hello_one hello_two hello_three " << std::endl;

    return 0;
}
