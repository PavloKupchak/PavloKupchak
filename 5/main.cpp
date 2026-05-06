#include "television.h"
#include "ColorTV.h"
#include "CableTV.h"
#include "Samsung.h"
#include "LGTV.h"
#include "Philips.h"
#include "SmartTV.h"
#include <iostream>
using namespace std;

int main() {
    cout << "--- SmartTV (diamond problem solved) ---" << endl;
    cout << "конструктори\n";
    SmartTV* smart = new SmartTV(7007, 75.0, 64, 600, true);
    cout << "деструктори\n";
    delete smart;

    return 0;
}