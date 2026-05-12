#include "Avesta.h"
#include <iostream>

Avesta::Avesta() {
    std::cout << "! Constructor of Avesta class called" << std::endl;
    setName("Avesta");
    setYear(0);
    setCountry("Iran, Central Asia or Azerbaijan");
}

Avesta::~Avesta() {
    std::cout << "! Destructor of Avesta class called" << std::endl;
}

int Avesta::god() {
    std::cout << "The god of this bookd is: God" << std::endl;
    return 1;
}

int Avesta::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "God" << std::endl;
    return 1;
}