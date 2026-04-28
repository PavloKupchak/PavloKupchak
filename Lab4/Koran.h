#pragma once
#include "HolyBooks.h"

class Koran : public HolyBooks {
public:
    Koran();
    int god() override;
    int god(std::string question) override;
};