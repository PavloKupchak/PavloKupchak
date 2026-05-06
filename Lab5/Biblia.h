#pragma once
#include "HolyBooks.h"

class Biblia : virtual public HolyBooks {
public:
    Biblia();
    ~Biblia();
    int god() override;
    int god(std::string question) override;
};