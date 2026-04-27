#include "HolyBooks.h"
#include <iostream>

int HolyBooks::setName(std::string name_book) {
    name = name_book;
    return 1;
}

int HolyBooks::setYear(int year_found) {
    year = year_found;
    return 1;
}

int HolyBooks::setCountry(std::string country_written) {
    country = country_written;
    return 1;
}

void HolyBooks::god() {
    std::cout << "The god of this book is:" << std::endl;
}

void HolyBooks::religion() {
    std::cout << name << " was written in " << country
              << " in the year " << year << std::endl;
}

void HolyBooks::showInfo() {
    religion();
}