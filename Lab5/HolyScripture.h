#pragma once
#include "Biblia.h"
#include <string>

class HolyScripture : virtual public Biblia {
protected:
    std::string zavit;

public:
    HolyScripture();
    HolyScripture(std::string zavit_name);

    int setZavit(std::string zavit_name);
    ~HolyScripture();
};