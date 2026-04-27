#include "Koran.h"
#include <iostream>

Koran::Koran() {
    setName("Koran");
    setYear(610);
    setCountry("Saudi Arabia");
}

void Koran::god() {
    std::cout << "The god of this book is: Allah" << std::endl;
}