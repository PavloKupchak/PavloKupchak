#pragma once
#include "HolyBooks.h"

class Koran : virtual public HolyBooks {
public:
    Koran();
    ~Koran();
    int god() override;
    int god(std::string question) override;
};