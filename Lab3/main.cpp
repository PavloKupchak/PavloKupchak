#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main() {
    Dyhotomia_class dyh;

    double a, b, eps;

    cout << "Введіть інтервал a,b: ";
    cin >> a >> b;

    cout << "Введіть допустиму похибку: ";
    cin >> eps;

    dyh.setTolerance(eps);

    double x;

    if (a < 0 && b > 0) {
        cout << "Інтервал проходить через 0\n";

        dyh.set_volumes(a, -eps);
        if (dyh.count(x) == 0) {
            cout << "Лівий корінь (Дихотомія): " << x << endl;
            if (dyh.newton(x) == 0)
                cout << "Лівий корінь (Ньютона): " << x << endl;
        }

        dyh.set_volumes(eps, b);
        if (dyh.count(x) == 0) {
            cout << "Правий корінь (Дихотомія): " << x << endl;
            if (dyh.newton(x) == 0)
                cout << "Правий корінь (Ньютона): " << x << endl;
        }
    }
    else {
        dyh.set_volumes(a, b);

        if (dyh.count(x) == 0) {
            cout << "Дихотомія x = " << x << endl;

            if (dyh.newton(x) == 0)
                cout << "Ньютон x = " << x << endl;
        } else {
            cout << "Помилка дихотомії" << endl;
        }
    }

    return 0;
}