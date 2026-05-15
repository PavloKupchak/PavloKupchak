#include "AdventureFacade.h"
#include <iostream>

using namespace std;

AdventureFacade::AdventureFacade() {
    _vault = new EquipmentVault();
    _guild = new MagicGuild();
    _stats = new StatsCalculator();
    _board = new QuestBoard();
}

AdventureFacade::~AdventureFacade() {
    delete _vault;
    delete _guild;
    delete _stats;
    delete _board;
}

void AdventureFacade::PrepareHero(const string& name, const string& heroClass, int level) const {
    cout << "===========================================" << endl;
    cout << "  Герой  : " << name << endl;
    cout << "  Клас   : " << heroClass << "  Рівень: "  << level << endl;
    cout << "===========================================" << endl;
    cout << "  " << _vault->GetDescription(heroClass) << endl;
    cout << "  Вартість спорядження: " << _vault->GetCost(heroClass) << " золота" << endl;
    cout << "  " << _guild->GetDescription(heroClass) << endl;
    cout << "  Здоров'я: "     << _stats->CalcHealth(heroClass, level) << "  Атака: "  << _stats->CalcAttack(heroClass, level) << endl;
    cout << "  " << _board->GetDescription(heroClass) << endl;
    cout << "===========================================" << endl;
    cout << "  Загальна вартість: " << GetTotalPreparationCost(heroClass) << " золота" << endl;
    cout << "===========================================" << endl << endl;
}

int AdventureFacade::GetTotalPreparationCost(const string& heroClass) const {
    return _vault->GetCost(heroClass) + _guild->GetCost(heroClass) + _stats->GetCost(heroClass) + _board->GetCost(heroClass);
}