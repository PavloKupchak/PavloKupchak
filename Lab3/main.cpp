#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    Dyhotomia_class dyh;

    double a, b, eps;

    cout << endl;
    cout << "Введіть інтервал a, b: ";
    cin >> a >> b;

    cout << "Введіть допустиму похибку: ";
    cin >> eps;

    dyh.setTolerance(eps);

    double xLeft;
    double xRight;
    double xNewton;

    if (a < 0 && b > 0) {
        cout << "Інтервал проходить через 0\n";

        dyh.set_volumes(a, -1e-6);
        if (dyh.count(xLeft) == 0) {
            cout << "Лівий корінь (Дихотомія): "
                 << fixed << setprecision(6) << xLeft << endl;
        } else {
            cout << "Помилка на лівому інтервалі\n";
        }

        dyh.set_volumes(1e-6, b);
        if (dyh.count(xRight) == 0) {
            cout << "Правий корінь (Дихотомія): "
                 << fixed << setprecision(6) << xRight << endl;
        } else {
            cout << "Помилка на правому інтервалі\n";
        }
    }
    
    else {
        dyh.set_volumes(a, b);

        if (dyh.count(xLeft) == 0) {
            cout << "Дихотомія x = "
                 << fixed << setprecision(6) << xLeft << endl;
        } else {
            cout << "Помилка дихотомії\n";
        }
    }

    cout << "\nМетод Ньютона\n";
    cout << "Введіть початкове наближення x0: ";
    cin >> xNewton;

    if (dyh.newton(xNewton) == 0) {
        cout << "Ньютон x = "
             << fixed << setprecision(6) << xNewton << endl;
    } else {
        cout << "Помилка Ньютона\n";
    }

    return 0;
}