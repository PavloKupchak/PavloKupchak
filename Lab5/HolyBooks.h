#pragma once
#include <string>

class HolyBooks {
private:
    std::string name;
    int year;
    std::string country;

public:
    HolyBooks();
    virtual ~HolyBooks();

    int setName(std::string name_book);
    int setYear(int year_found);
    int setCountry(std::string country_written);

    virtual int god();
    virtual int god(std::string question);
    int showInfo();
    int showInfo(std::string language);

protected:
    int religion();
};