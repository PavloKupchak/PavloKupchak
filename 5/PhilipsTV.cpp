#include<iostream>
#include<string>
#include<vector>
#include "Philips.h"
using namespace std;

PhilipsTV::PhilipsTV(int serialNumber, double diagonal, int colorDepth, int countPackagesPerSecond) 
    : OldTV(serialNumber, diagonal), 
      ColorTV(serialNumber, diagonal, colorDepth), 
      CableTV(serialNumber, diagonal, colorDepth, countPackagesPerSecond)
{
    cout << "[+]PhilipsTV created\n";
}

PhilipsTV::~PhilipsTV() {
    cout << "[-]PhilipsTV destroyed\n";
}

void PhilipsTV::setAmblightColor() { 
    cout << "Sync. with picture\n"; 
}