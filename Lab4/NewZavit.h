#pragma once
#include "HolyScripture.h"
#include <string>

class NewZavit : public HolyScripture
{
private:
    std::string countOfBooks;
    std::string primaryLanguage;


public:
    NewZavit(std::string zavit_name, std::string countOfBooks, std::string primaryLanguage);

    int setCountOfBooks(std::string countOfBooksNewZavit);
    int setPrimaryLanguage(std::string primaryLanguageNewZavit);
};