#ifndef CABLE_TV_H
#define CABLE_TV_H
#include "ColorTV.h"
#include <string>
#include <vector>
using namespace std;

class CableTV : virtual public ColorTV {
public:
    CableTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond);
    void watch() override;
    int getCountPackagesPerSecond() const;
    void showInfo() const override;
    virtual ~CableTV();
protected:
    int countPackagesPerSecond;
};

#endif