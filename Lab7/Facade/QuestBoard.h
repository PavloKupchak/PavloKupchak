#pragma once
#include "IHeroSystem.h"
#include <string>

class QuestBoard : public IHeroSystem {
public:
    std::string AssignStartingQuest(const std::string& heroClass) const;
    int GetQuestReward(const std::string& heroClass) const;

    int GetCost(const std::string& heroClass) const override;
    std::string GetDescription(const std::string& heroClass) const override;
};