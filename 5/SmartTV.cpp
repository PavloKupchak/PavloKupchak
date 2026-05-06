#include "SmartTV.h"
#include <iostream>
using namespace std;

SmartTV::SmartTV(int serialNumber, double diagonal, int colorDepth,
                 int countPackagesPerSecond, bool enableAI)
    : OldTV(serialNumber, diagonal),
      ColorTV(serialNumber, diagonal, colorDepth),
      CableTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond),
      SamsungTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond, enableAI),
      LGTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond),
      PhilipsTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond) {
    cout << "      [+] SmartTV created\n";
}
SmartTV::~SmartTV() { cout << "      [-] SmartTV destroyed\n"; }
void SmartTV::watch() { cout << "Watching SmartTV\n"; }
void SmartTV::showInfo() const {
    SamsungTV::showInfo();
    cout << "SmartHome: ";
    LGTV::showInfo();  
    cout << "Ambilight: ";
    PhilipsTV::showInfo(); 
}
void SmartTV::installApp(const string& appName) {
    installedApps.push_back(appName);
    cout << "Installed: " << appName << "\n";
}
void SmartTV::uninstallApp(const string& appName) {
    for (auto it = installedApps.begin(); it != installedApps.end(); ++it) {
        if (*it == appName) {
            installedApps.erase(it);
            cout << "Uninstalled: " << appName << "\n";
            return;
        }
    }
    cout << "App not found: " << appName << "\n";
}
void SmartTV::launchApp(const string& appName) {
    for (const auto& app : installedApps)
        if (app == appName) { cout << "Launching: " << appName << "\n"; return; }
    cout << "App not found: " << appName << "\n";
}
bool SmartTV::isEnableAI() { return SamsungTV::isEnableAI(); }
void SmartTV::connectToSmartHome() { LGTV::connectToSmartHome(); }
void SmartTV::setAmblightColor() { PhilipsTV::setAmblightColor(); }
