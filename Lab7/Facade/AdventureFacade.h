#pragma once
#include "IHeroSystem.h"
#include "EquipmentVault.h"
#include "MagicGuild.h"
#include "StatsCalculator.h"
#include "QuestBoard.h"
#include <string>

class AdventureFacade{
private:
    EquipmentVault* _vault;
    MagicGuild* _guild;
    StatsCalculator* _stats;
    QuestBoard* _board;

public:
    AdventureFacade();
    ~AdventureFacade();

    void PrepareHero(const std::string& name, const std::string& heroClass, int level) const;
    int  GetTotalPreparationCost(const std::string& heroClass) const;
};