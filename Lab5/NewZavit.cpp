#include "NewZavit.h"
#include <iostream>

NewZavit::NewZavit(std::string zavit_name, std::string countOfBooksNewZavit, std::string primaryLanguageNewZavit) : HolyScripture(zavit_name) {
    setCountOfBooks(countOfBooksNewZavit);
    setPrimaryLanguage(primaryLanguageNewZavit);
    std::cout << "! Constructor of NewZavit class called" << std::endl;
    std::cout << std::endl;
    std::cout << "It's: " << zavit_name << " with count of books: " << countOfBooks << " and primary language: " << primaryLanguage << std::endl;
}

NewZavit::~NewZavit() {
    std::cout << "! Destructor of NewZavit class called" << std::endl;
}

int NewZavit::setCountOfBooks(std::string countOfBooksNewZavit) {
    countOfBooks = countOfBooksNewZavit;
    return 1;
}

int NewZavit::setPrimaryLanguage(std::string primaryLanguageNewZavit) {
    primaryLanguage = primaryLanguageNewZavit;
    return 1;
}