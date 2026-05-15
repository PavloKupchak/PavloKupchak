#include "StatsCalculator.h"

using namespace std;

int StatsCalculator::CalcHealth(const string& heroClass, int level) const {
    int base = 50;
    if (heroClass == "Воїн") base = 120;
    else if (heroClass == "Маг")  base = 60;
    else if (heroClass == "Шахрай") base = 80;
    return base + (level - 1) * 20;
}

int StatsCalculator::CalcAttack(const string& heroClass, int level) const {
    int base = 5;
    if (heroClass == "Воїн") base = 18;
    else if (heroClass == "Маг") base = 10;
    else if (heroClass == "Шахрай") base = 14;
    return base + (level - 1) * 3;
}

int StatsCalculator::GetCost(const string&) const {
    return 0; 
}

string StatsCalculator::GetDescription(const string& heroClass) const {
    return "Здоров'я: " + to_string(CalcHealth(heroClass, 1)) + ", Атака: " + to_string(CalcAttack(heroClass, 1));
}