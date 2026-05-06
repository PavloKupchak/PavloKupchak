#include "Biblia.h"
#include <iostream>

Biblia::Biblia() {
    std::cout << "! Constructor of Biblia class called" << std::endl;
    setName("Biblia");
    setYear(0);
    setCountry("Unknown");
}

Biblia::~Biblia() {
    std::cout << "! Destructor of Biblia class called" << std::endl;
}

int Biblia::god() {
    std::cout << "The god of this bookd is: God" << std::endl;
    return 1;
}

int Biblia::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "God" << std::endl;
    return 1;
}