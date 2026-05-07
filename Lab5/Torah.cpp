#include "Torah.h"
#include <iostream>

Torah::Torah() {
    std::cout << "! Constructor of Torah class called" << std::endl;
    setName("Torah");
    setYear(-1400);
    setCountry("Egypt/Israel");
}

Torah::~Torah() {
    std::cout << "! Destructor of Torah class called" << std::endl;
}

int Torah::god() {
    std::cout << "The god of this book is: Yahweh" << std::endl;
    return 1;
}

int Torah::god(std::string question) {
    std::cout << "Question: " << question << std::endl;
    std::cout << "Yahweh" << std::endl;
    return 1;
}