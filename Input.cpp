#include "Input.hpp"
#include <iostream>
#include <limits>

// Programmer's name: TAN ISSEY | 26103162
// Purpose: Reads a positive number, rejecting invalid or non-positive input.
double readPositiveNumber(const std::string& prompt) 
{
    double value;
    while (true) 
    {
        std::cout << prompt;
        if (std::cin >> value && value > 0) return value;
        std::cout << "Invalid input. Please enter a positive number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Programmer's name: TAN ISSEY | 26103162
// Purpose: Reads an integer and rejects invalid input.
int readInteger(const std::string& prompt) 
{
    int value;
    while (true) 
    {
        std::cout << prompt;
        if (std::cin >> value) return value;
        std::cout << "Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
