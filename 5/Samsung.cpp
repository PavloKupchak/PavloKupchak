#include <iostream>
#include <string>
#include <vector>
#include "Samsung.h"

SamsungTV::SamsungTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond, bool EnableAI) 
    : OldTV(serialNumber, diagonal), 
    ColorTV(serialNumber, diagonal, colorDepth), 
    CableTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond) {
    this->EnableAI = EnableAI;
    cout << "[+]SamsungTV created\n";
}

SamsungTV::~SamsungTV() {
    cout << "[-]SamsungTV destroyed\n";
}

void SamsungTV::watch() { 
    cout << "Watching SamsungTV\n"; 
}

bool SamsungTV::isEnableAI() { 
    return this->EnableAI; 
}

void SamsungTV::showInfo() const {
    CableTV::showInfo();
    cout << "AI Enabled: " << (this->EnableAI ? "Yes" : "No") << "\n";
}
