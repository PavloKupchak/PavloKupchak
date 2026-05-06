#ifndef SAMSUNG_H
#define SAMSUNG_H
#include "CableTV.h"
#include <string>
#include <vector>
using namespace std;

class SamsungTV : virtual public CableTV {
public:
    SamsungTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond, bool EnableAI);
    void watch() override;
    bool isEnableAI();
    void showInfo() const override;
    virtual ~SamsungTV();
protected:
    bool EnableAI;
};

#endif