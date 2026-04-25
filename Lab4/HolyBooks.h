#pragma once
#include <string>

class HolyBooks
{
private:
    std::string name;
    int year;
    std::string country;

public:
    int setName(std::string name_book);
    int setYear(int year_found);
    int setCountry(std::string country_written);

    virtual int god();
    int showInfo();

protected:
    int religion();
};