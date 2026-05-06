#ifndef COLOR_TV_H
#define COLOR_TV_H
#include "television.h"
#include <string>
#include <vector>
using namespace std;

class ColorTV : virtual public OldTV {
public:
    ColorTV(int serialNumber, double diagonal, int colorDepth);
    void watch() override;
    int getColorDepth() const;
    void showInfo() const override;
    virtual ~ColorTV();
protected:
    int colorDepth;
};

#endif