#ifndef LGTV_H
#define LGTV_H
#include "CableTV.h"
#include <string>
#include <vector>


    using namespace std;

    class LGTV : virtual public CableTV{
    public:
        LGTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond);
    void connectToSmartHome();
    virtual ~LGTV();
};

#endif