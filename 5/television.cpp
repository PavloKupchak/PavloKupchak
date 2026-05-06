#include "television.h"
#include <iostream>

using namespace std;



OldTV::OldTV(int serialNumber, double diagonal) {
    this->serialNumber = serialNumber;
    this->diagonal = diagonal;
    cout << "[+]OldTV created\n";
}

OldTV::~OldTV() {
    cout << "[-]OldTV destroyed\n";
}

int OldTV::getSerialNumber() const { 
    return this->serialNumber; 
}

double OldTV::getDiagonal() const { 
    return this->diagonal; 
}

void OldTV::watch() { 
    cout << "Watching TV\n"; 
}

void OldTV::showInfo() const {
    cout << "Serial Number: " << this->serialNumber << "\n";
    cout << "Diagonal: " << this->diagonal << "\n";
}
