#include "BattleSystem.h"
#include "GameSession.h"
#include <iostream>

using namespace std;

void BattleSystem::DefeatEnemy(const string& enemyName, int xpReward, int goldReward) {
    cout << "\n[Бій] Переможено: " << enemyName << endl;
    GameSession* session = GameSession::GetInstance();
    session->AddExperience(xpReward);
    session->AddGold(goldReward);
}