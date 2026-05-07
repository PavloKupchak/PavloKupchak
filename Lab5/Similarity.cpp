#include "Similarity.h"
#include <iostream>

Similarity::Similarity() {
    std::cout << "! Constructor of Similarity class called" << std::endl;
    setName("Biblia, Koran and Torah");
    setYear(0);
    setCountry("Different countries");
}

Similarity::~Similarity() {
    std::cout << "! Destructor of Similarity class called" << std::endl;
}

int Similarity::god() {
    std::cout << "Books have different gods" << std::endl;
    return 1;
}

int Similarity::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "Different" << std::endl;
    return 1;
}

