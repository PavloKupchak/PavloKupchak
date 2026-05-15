#pragma once
#include "ILogger.h"
#include <string>

class GameSession : public ILogger {
private:
    GameSession();
    GameSession(const GameSession&) = delete;
    GameSession& operator=(const GameSession&) = delete;

    static GameSession* _instance;

    std::string _playerName;
    int _level;
    int _gold;
    int _experience;

public:
    static GameSession* GetInstance();
    
    void Log(const std::string& message) override;
    void LogWarning(const std::string& message) override;
    void LogError(const std::string& message) override;

    void SetPlayerName(const std::string& name);
    void AddExperience(int xp);
    void AddGold(int amount);
    bool SpendGold(int amount);
    void PrintStatus() const;

    int GetLevel() const;
    int GetGold() const;
};