#include <iostream>
#include <string>
#include <vector>
#include "CableTV.h"
    using namespace std;


CableTV::CableTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond) 
    : OldTV(serialNumber, diagonal),
     ColorTV(serialNumber, diagonal, colorDepth) {
    this->countPackagesPerSecond = countPackagesPerSecond;
    cout << "[+]CableTV created\n";
}

CableTV::~CableTV() {
    cout << "[-]CableTV destroyed\n";
}

void CableTV::watch() {
    cout << "Watching cable TV with " << this->countPackagesPerSecond << " packages per second\n";
}

int CableTV::getCountPackagesPerSecond() const { 
    return this->countPackagesPerSecond; 
}

void CableTV::showInfo() const {
    ColorTV::showInfo();
    cout << "Count Packages Per Second: " << this->countPackagesPerSecond << "\n";
}