#include "EquipmentVault.h"

using namespace std;

string EquipmentVault::IssueWeapon(const string& heroClass) const {
    if (heroClass == "Воїн") return "Широкий меч";
    if (heroClass == "Маг") return "Посох аркану";
    if (heroClass == "Шахрай") return "Двоїсті кинджали";
    return "Дерев'яний клуб";
}

string EquipmentVault::IssueArmor(const string& heroClass) const {
    if (heroClass == "Воїн") return "Шолом";
    if (heroClass == "Маг") return "Тканина";
    if (heroClass == "Шахрай") return "Шкіряна жилет";
    return "Порваний одяг";
}

int EquipmentVault::GetCost(const string& heroClass) const {
    if (heroClass == "Воїн") return 150;
    if (heroClass == "Маг") return 120;
    if (heroClass == "Шахрай") return 90;
    return 20;
}

string EquipmentVault::GetDescription(const string& heroClass) const {
    return "Зброя: " + IssueWeapon(heroClass) + ", Броня: " + IssueArmor(heroClass);
}