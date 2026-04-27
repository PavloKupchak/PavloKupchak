#include "Biblia.h"
#include <iostream>

Biblia::Biblia() {
    setName("Biblia");
    setYear(0);
    setCountry("Unknown");
}

void Biblia::god() {
    std::cout << "The god of this book is: God" << std::endl;
}