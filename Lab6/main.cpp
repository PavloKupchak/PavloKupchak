#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    Dyhotomia_class dyh;
    dyh.setFunction([](double x) -> double {
        return x - 2 + sin(1 / x);
    });

    double a, b, eps;

    cout << "\nМетод дихотомії\n";
    cout << "Введіть інтервал a b: ";
    cin >> a >> b;
    cout << "Введіть допустиму похибку: ";
    cin >> eps;

    dyh.setTolerance(eps);

    auto printResult = [](const string &method, double root) {
        cout << fixed << setprecision(8);
        cout << method << ": x = " << root << "\n";
    };

    double xLeft, xRight;

    if (a < 0 && b > 0) {
        cout << "Інтервал проходить через 0\n";

        dyh.set_volumes(a, -1e-6);
        if (dyh.count(xLeft) == 0)
            printResult("Лівий корінь (дихотомія)", xLeft);
        else
            cout << "Помилка в лівій частині\n";

        dyh.set_volumes(1e-6, b);
        if (dyh.count(xRight) == 0)
            printResult("Правий корінь (дихотомія)", xRight);
        else
            cout << "Помилка в правій частині\n";
    } else {
        dyh.set_volumes(a, b);
        if (dyh.count(xLeft) == 0)
            printResult("Дихотомія", xLeft);
        else
            cout << "Помилка дихотомії\n";
    }

    cout << "\nМетод Ньютона\n";
    cout << "Введіть початкове наближення x0: ";
    double xNewton;
    cin >> xNewton;

    if (dyh.newton(xNewton) == 0)
        printResult("Ньютон", xNewton);
    else
        cout << "Метод Ньютона не збігся\n";

    cout << "\nКвадратне рівняння\n";
    double A, B, C;
    cout << "Введіть коефіцієнти A B C: ";
    cin >> A >> B >> C;

    double x1, x2;
    int roots = dyh.solveQuadratic(A, B, C, x1, x2);

    auto printQuadResult = [&x1, &x2](int n) {
        cout << fixed << setprecision(8);
        if (n == 2)
            cout << "Два корені: x1 = " << x1 << ", x2 = " << x2 << "\n";
        else if (n == 1)
            cout << "Один корінь: x = " << x1 << "\n";
        else if (n == 0)
            cout << "(Дійсних коренів немає)\n";
        else
            cout << "Помилка: коефіцієнт A = 0\n";
    };

    printQuadResult(roots);

    return 0;
}