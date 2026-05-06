#ifndef TELEVISON_H
#define TELEVISON_H
#include <string>
#include <vector>
using namespace std;

class OldTV{
public:
    OldTV();
    OldTV(int serialNumber, double diagonal);
    int getSerialNumber() const;
    double getDiagonal() const;
    virtual void watch();
    virtual void showInfo() const;
    virtual ~OldTV();;
protected:
    int serialNumber;
    double diagonal;
};

#endif