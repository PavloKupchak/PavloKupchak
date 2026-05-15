#pragma once
#include "IHeroSystem.h"
#include <string>

class StatsCalculator : public IHeroSystem {
public:
    int CalcHealth(const std::string& heroClass, int level) const;
    int CalcAttack(const std::string& heroClass, int level) const;

    int GetCost(const std::string& heroClass) const override;
    std::string GetDescription(const std::string& heroClass) const override;
};