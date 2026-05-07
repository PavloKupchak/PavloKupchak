#pragma once 
#include "Biblia.h"
#include "Koran.h"
#include "Torah.h"

class Similarity : public Biblia, public Koran, public Torah {
public:
    Similarity();
    ~Similarity();
    int god() override;
    int god(std::string question) override;
};