#pragma once 
#include "Biblia.h"
#include "Avesta.h"

class Similarity2 : public Biblia, public Avesta {
public:
    Similarity2();
    ~Similarity2();
    int god() override;
    int god(std::string question) override;
};