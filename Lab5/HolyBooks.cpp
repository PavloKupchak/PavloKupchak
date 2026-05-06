#include "HolyBooks.h"
#include <iostream>

HolyBooks::HolyBooks() {
    std::cout << "! Constructor of HolyBooks class called" << std::endl;
    name = "Unknown";
    year = 0;
    country = "Unknown";
}

HolyBooks::~HolyBooks() {
    std::cout << "! Destructor of HolyBooks class called" << std::endl;
}

int HolyBooks::setName(std::string name_book) { 
    name = name_book; return 1; 
}

int HolyBooks::setYear(int year_found) { 
    year = year_found; return 1; 

}
int HolyBooks::setCountry(std::string country_written) { 
    country = country_written; return 1; 
}

int HolyBooks::god() {
    std::cout << std::endl;
    std::cout << "The god of this book is:" << std::endl;
    return 1;
}

int HolyBooks::god(std::string question) {
    std::cout << std::endl;
    std::cout << "Question: " << question << std::endl;
    std::cout << "The god of this book is:" << std::endl;
    return 1;
}

int HolyBooks::religion() {
    std::cout << name << " was written in " << country << " in the year " << year << std::endl;
    return 1;
}

int HolyBooks::showInfo() {
    std::cout << std::endl;
    return religion();
}

int HolyBooks::showInfo(std::string language) {
    std::cout << "Language: " << language << std::endl;
    std::cout << std::endl;
    return religion();
}