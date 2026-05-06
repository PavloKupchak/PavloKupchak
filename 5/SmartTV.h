#ifndef SMARTTV_H
#define SMARTTV_H
#include "Philips.h"
#include "Samsung.h"
#include "LGTV.h"
#include <string>
#include <vector>

    using namespace std;

        class SmartTV : public PhilipsTV, public SamsungTV, public LGTV {
public:
    
    SmartTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond, bool EnableAI);
    void watch() override;
    bool isEnableAI();
    void showInfo() const override;
    void installApp(const string& appName);
    void uninstallApp(const string& appName);
    void launchApp(const string& appName);
            void connectToSmartHome();
            void setAmblightColor();
    virtual ~SmartTV();
private:
    vector<string> installedApps;
};

#endif