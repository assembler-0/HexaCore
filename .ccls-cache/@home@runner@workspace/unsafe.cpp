#include <iostream>
#include <cstring> // For strcpy

void unsafeFunction() {
    char buffer[10]; // A small buffer of 10 bytes
    std::cout << "Enter a string: ";
    std::cin >> buffer; // No bounds checking on input
    std::cout << "You entered: " << buffer << std::endl;
}

int* danglingPointer() {
    int localValue = 42;
    return &localValue; // Returning the address of a local variable (dangling pointer)
}

int main() {
    // Demonstrating buffer overflow
    unsafeFunction();

    // Demonstrating dangling pointer
    int* ptr = danglingPointer();
    std::cout << "Dangling pointer value: " << *ptr << std::endl; // Undefined behavior

    // Demonstrating double delete
    int* doubleDelete = new int(100);
    delete doubleDelete;
    delete doubleDelete; // Double delete - undefined behavior

    // Demonstrating memory leak
    int* memoryLeak = new int[10]; // Memory allocated but never freed

    return 0; // Memory leak persists
}
