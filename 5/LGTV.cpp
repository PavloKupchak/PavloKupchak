#include <iostream>
#include <string>
#include <vector>
#include "LGTV.h"
using namespace std;

LGTV::LGTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond) 
    : OldTV(serialNumber, diagonal), 
      ColorTV(serialNumber, diagonal, colorDepth), 
      CableTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond) {
    cout << "[+]LGTV created\n";
}

LGTV::~LGTV() {
    cout << "[-]LGTV destroyed\n";
}

void LGTV::connectToSmartHome() { 
    cout << "Connected to SmartHouse\n"; 
}