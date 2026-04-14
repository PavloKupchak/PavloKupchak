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

    double xDYHOTOMIA;     
    double xNEWTON;  

    if (a < 0 && b > 0) {
        cout << "Інтервал проходить через 0\n";

        double delta = 1e-6;
        dyh.set_volumes(a, -delta);
        if (dyh.count(xDYHOTOMIA) == 0) {
            cout << "Лівий корінь (Дихотомія): " 
                 << fixed << setprecision(6) << xDYHOTOMIA << endl;
        } else {
            cout << "Помилка на лівому інтервалі\n";
        }

        dyh.set_volumes(delta, b);
        if (dyh.count(xNEWTON) == 0) {
            cout << "Правий корінь (Дихотомія): " 
                 << fixed << setprecision(6) << xNEWTON << endl;
        } else {
            cout << "Помилка на правому інтервалі\n";
        }
    }
    else {
        dyh.set_volumes(a, b);

        if (dyh.count(xDYHOTOMIA) == 0) {
            cout << "Дихотомія x = " 
                 << fixed << setprecision(6) << xDYHOTOMIA << endl;
        } else {
            cout << "Помилка дихотомії\n";
        }
    }

    cout << "\nМетод Ньютона\n";
    cout << "Введіть початкове наближення x0: ";
    cin >> xNEWTON;

    if (dyh.newton(xNEWTON) == 0) {
        cout << "Ньютон x = " << fixed << setprecision(6) << xNEWTON << endl << endl;
    } else {
        cout << "Помилка Ньютона\n";
    }

    return 0;
}