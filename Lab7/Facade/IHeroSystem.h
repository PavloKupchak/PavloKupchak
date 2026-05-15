#pragma once
#include <string>

class IHeroSystem {
public:
    virtual int GetCost(const std::string& heroClass) const = 0;
    virtual std::string GetDescription(const std::string& heroClass) const = 0;
    virtual ~IHeroSystem() = default;
};