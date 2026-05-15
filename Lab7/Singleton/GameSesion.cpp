#include "GameSession.h"
#include <iostream>

using namespace std;

GameSession* GameSession::_instance = nullptr;
GameSession::GameSession() : _playerName("Pavlo"), _level(1), _gold(100), _experience(0) {
    cout << "[GameSession] Нову сесію створено для гравця \"" << _playerName << "\"" << endl;
}

GameSession* GameSession::GetInstance() {
    if (!_instance)
        _instance = new GameSession();
    return _instance;
}

void GameSession::Log(const string& message) {
    cout << "[Лог] " << message << endl;
}

void GameSession::LogWarning(const string& message) {
    cout << "[Попередження] " << message << endl;
}

void GameSession::LogError(const string& message) {
    cout << "[Помилка]   " << message << endl;
}

void GameSession::SetPlayerName(const string& name) {
    _playerName = name;
    Log("Ім'я гравця змінено на \"" + name + "\"");
}

void GameSession::AddExperience(int xp) {
    _experience += xp;
    Log("+" + to_string(xp) + " XP (всього: " + to_string(_experience) + ")");

    if (_experience >= _level * 200) {
        _level++;
        _experience = 0;
        Log("Новий рівень! Тепер рівень " + to_string(_level));
    }
}

void GameSession::AddGold(int amount) {
    _gold += amount;
    Log("+" + to_string(amount) + " золота (всього: " + to_string(_gold) + ")");
}

bool GameSession::SpendGold(int amount) {
    if (_gold < amount) {
        LogWarning("Недостатньо золота! Є: " + to_string(_gold) + ", потрібно: " + to_string(amount));
        return false;
    }
    _gold -= amount;
    Log("Витрачено " + to_string(amount) + " золота (залишок: " + to_string(_gold) + ")");
    return true;
}

void GameSession::PrintStatus() const {
    cout << "===========================================" << endl;
    cout << "  Гравець : " << _playerName    << endl;
    cout << "  Рівень  : " << _level         << endl;
    cout << "  Золото  : " << _gold          << endl;
    cout << "  Досвід  : " << _experience    << endl;
    cout << "===========================================" << endl;
}

int GameSession::GetLevel() const { 
    return _level; 
}

int GameSession::GetGold()  const { 
    return _gold;  
}