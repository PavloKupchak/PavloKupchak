#pragma once
#include <string>

class HolyBooks {
private:
    std::string name;
    int year;
    std::string country;

public:
    HolyBooks() = default;

    virtual ~HolyBooks() = default;

    int setName(std::string name_book);
    int setYear(int year_found);
    int setCountry(std::string country_written);

    virtual void god();
    void showInfo();

protected:
    void religion();
};