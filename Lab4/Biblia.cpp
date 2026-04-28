#include "Biblia.h"
#include <iostream>

Biblia::Biblia() {
    setName("Biblia");
    setYear(0);
    setCountry("Unknown");
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