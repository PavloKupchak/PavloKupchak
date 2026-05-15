#include "QuestBoard.h"

using namespace std;

string QuestBoard::AssignStartingQuest(const string& heroClass) const {
    if (heroClass == "Воїн") return "Захистити село від гоблінів";
    if (heroClass == "Маг") return "повернути втрачений артефакт";
    if (heroClass == "Шахрай") return "Зашифрувати повідомлення";
    return "Зібрано 10 лісових ягід";
}

int QuestBoard::GetQuestReward(const string& heroClass) const {
    if (heroClass == "Воїн") return 200;
    if (heroClass == "Маг") return 180;
    if (heroClass == "Шахрай") return 160;
    return 50;
}

int QuestBoard::GetCost(const string&) const {
    return 0; 
}

string QuestBoard::GetDescription(const string& heroClass) const {
    return "Квест: " + AssignStartingQuest(heroClass) + " (нагорода: " + to_string(GetQuestReward(heroClass)) + " XP)";
}