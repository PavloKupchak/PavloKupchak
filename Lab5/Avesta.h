#pragma once
#include "HolyBooks.h"

class Avesta : virtual public HolyBooks {
public:
    Avesta();
    ~Avesta();
    int god() override;
    int god(std::string question) override;
};  