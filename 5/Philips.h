#ifndef PHILIPS_H
#define PHILIPS_H
#include "CableTV.h"
#include <string>
#include <vector>
using namespace std;

class PhilipsTV : virtual public CableTV{
public:
    PhilipsTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond);
    void setAmblightColor();
    virtual ~PhilipsTV();
};

#endif