#pragma once
#include "HolyBooks.h"

class Torah : virtual public HolyBooks {
    public:
        Torah();
        ~Torah();
        int god() override;
        int god(std::string question) override;
};