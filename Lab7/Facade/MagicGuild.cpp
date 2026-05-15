#include "MagicGuild.h"

using namespace std;

string MagicGuild::LearnStartingSpell(const string& heroClass) const {
    if (heroClass == "Маг") return "Вогняна куля";
    if (heroClass == "Шахрай") return "Незамітний удар";
    if (heroClass == "Воїн") return "Бойовий крик";
    return "Немає заклинання";
}

int MagicGuild::GetManaPool(const string& heroClass) const {
    if (heroClass == "Маг") return 200;
    if (heroClass == "Шахрай") return 80;
    if (heroClass == "Воїн") return 40;
    return 10;
}

int MagicGuild::GetCost(const string& heroClass) const {
    if (heroClass == "Маг") return 80;
    if (heroClass == "Шахрай") return 40;
    if (heroClass == "Воїн") return 20;
    return 0;
}

string MagicGuild::GetDescription(const string& heroClass) const {
    return "Заклинання: " + LearnStartingSpell(heroClass) + ", Мана: " + to_string(GetManaPool(heroClass));
}