#include "Koran.h"
#include <iostream>

Koran::Koran() {
    setName("Koran");
    setYear(610);
    setCountry("Saudi Arabia");
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