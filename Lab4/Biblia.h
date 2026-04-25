#pragma once
#include "HolyBooks.h"

class Biblia : public HolyBooks
{
public:
    Biblia();
    int god() override;
};