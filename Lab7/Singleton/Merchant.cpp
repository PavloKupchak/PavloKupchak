#include "Merchant.h"
#include "GameSession.h"
#include <iostream>

using namespace std;

void Merchant::SellItem(const string& itemName, int price) {
    cout << "\n[Торговець] Продаю \"" << itemName << "\" за " << price << " золота" << endl;

    GameSession* session = GameSession::GetInstance();

    if (!session->SpendGold(price))
        session->LogError("Угоду скасовано - недостатньо коштів");
    else
        session->Log("Покупку здійснено: " + itemName);
}