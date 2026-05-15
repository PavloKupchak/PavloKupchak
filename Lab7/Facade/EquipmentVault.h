#pragma once
#include "IHeroSystem.h"
#include <string>

class EquipmentVault : public IHeroSystem {
public:
    std::string IssueWeapon(const std::string& heroClass) const;
    std::string IssueArmor (const std::string& heroClass) const;

    int GetCost(const std::string& heroClass) const override;
    std::string GetDescription(const std::string& heroClass) const override;
};