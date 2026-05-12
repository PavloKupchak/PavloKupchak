#include "Similarity2.h"
#include <iostream>

Similarity2::Similarity2() {
    std::cout << "! Constructor of Similarity2 class called" << std::endl;
    setName("Biblia and Avesta");
    setYear(0);
    setCountry("Different countries");
}

Similarity2::~Similarity2() {
    std::cout << "! Destructor of Similarity2 class called" << std::endl;
}

int Similarity2::god() {
    std::cout << "Books have different gods" << std::endl;
    return 1;
}

int Similarity2::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "Different" << std::endl;
    return 1;
}

