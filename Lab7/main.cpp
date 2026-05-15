#include "Singleton/GameSession.h"
#include "Singleton/BattleSystem.h"
#include "Singleton/Merchant.h"
#include "Facade/AdventureFacade.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "\n! Singleton" << endl << endl;
    GameSession* session = GameSession::GetInstance();
    session->SetPlayerName("Kupchak");
    session->PrintStatus();

    BattleSystem battle;
    battle.DefeatEnemy("Гоблін", 80, 15);
    battle.DefeatEnemy("Орк Воїн", 150, 50);

    Merchant merchant;
    merchant.SellItem("Залізний меч", 40);
    merchant.SellItem("Драконяче доспілля", 300);

    GameSession* session2 = GameSession::GetInstance();
    cout << "\n[Test] session == session2: "
         << (session == session2 ? "true - один об'єкт" : "false") << endl;
    cout << endl;
    session->PrintStatus();



    cout << "\n! Facade" << endl << endl;
    AdventureFacade* facade = new AdventureFacade();
    facade->PrepareHero("Steve",   "Воїн", 1);
    facade->PrepareHero("Alex",    "Маг",    3);
    facade->PrepareHero("Shadow", "Шахрай", 2);
    cout << "Вартість підготовки Mage: " << facade->GetTotalPreparationCost("Маг") << " золота" << endl;

    delete facade;
    return 0;
}
