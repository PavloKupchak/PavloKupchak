#pragma once
#include "IHeroSystem.h"
#include <string>


class MagicGuild : public IHeroSystem {
public:
    std::string LearnStartingSpell(const std::string& heroClass) const;
    int GetManaPool(const std::string& heroClass) const;

    int GetCost(const std::string& heroClass) const override;
    std::string GetDescription(const std::string& heroClass) const override;
};