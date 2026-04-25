#include "Biblia.h"
#include <iostream>

Biblia::Biblia() {
    setName("Biblia");
    setYear(0);
    setCountry("Unknown");
}

int Biblia::god() {
    std::cout << "The god of this book is: God" << std::endl;
    return 1;
}