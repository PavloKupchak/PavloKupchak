#include <iostream>
#include <string>
#include <vector>
#include "ColorTV.h"
using namespace std;

ColorTV::ColorTV(int serialNumber, double diagonal, int colorDepth) 
    : OldTV(serialNumber, diagonal) {
    this->colorDepth = colorDepth;
    cout << "[+]ColorTV created\n";
}

ColorTV::~ColorTV() {
    cout << "[-]ColorTV destroyed\n";
}

void ColorTV::watch() { 
    cout << "Watching color TV\n"; 
}

int ColorTV::getColorDepth() const { 
    return this->colorDepth; 
}

void ColorTV::showInfo() const {
    OldTV::showInfo();
    cout << "Color Depth: " << this->colorDepth << "\n";
}