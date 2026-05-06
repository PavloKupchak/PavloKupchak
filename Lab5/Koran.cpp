#include "Koran.h"
#include <iostream>

Koran::Koran() {
    std::cout << "! Constructor of Koran class called" << std::endl;
    setName("Koran");
    setYear(610);
    setCountry("Saudi Arabia");
}

Koran::~Koran() {
    std::cout << "! Destructor of Koran class called" << std::endl;
}

int Koran::god() {
    std::cout << "The god of this book is: Allah" << std::endl;
    return 1;
}

int Koran::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "Allah" << std::endl;
    return 1; 
}