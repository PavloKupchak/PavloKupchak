#pragma once 
#include "Biblia.h"
#include "Koran.h"

class Similarity : public Biblia, public Koran {
public:
    Similarity();
    ~Similarity();
    int god() override;
    int god(std::string question) override;
};