#include "Dyhotomia_class.h"
#include <iostream>
#include <cmath>

using namespace std;

Dyhotomia_class::Dyhotomia_class() {
    eps = 1e-6;

    f = [](double x) -> double {
        return x - 2 + sin(1 / x);
    };

    df = [this](double x) -> double {
        const double h = 1e-6;
        return (f(x + h) - f(x - h)) / (2 * h);
    };
}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::set_volumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

void Dyhotomia_class::setFunction(function<double(double)> func) {
    f = func;
}

int Dyhotomia_class::count(double &x) {
    auto nearZero = [](double v, double tol = 1e-12) -> bool {
        return fabs(v) < tol;
    };

    if (nearZero(a) || nearZero(b)) {
        cout << "Інтервал торкається нуля" << endl;
        return -1;
    }

    if (f(a) * f(b) >= 0) {
        cout << "Однакові знаки на кінцях інтервалу" << endl;
        return -1;
    }

    auto bisectStep = [this, &nearZero]() -> double {
        double c = (a + b) / 2;
        if (nearZero(c)) {
            c = (c > 0) ? c + eps : c - eps;
        }
        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
        return c;
    };

    while ((b - a) / 2 > eps) {
        bisectStep();
    }

    x = (a + b) / 2;
    return 0;
}

int Dyhotomia_class::newton(double &x) {
    const int max_iter = 1000;

    auto newtonStep = [this](double &NEWx) -> int {
        double fx  = f(NEWx);
        double dfx = df(NEWx);

        if (fabs(dfx) < 1e-12) {
            cout << "Похідна дорівнює нулю" << endl;
            return -1;
        }

        NEWx = NEWx - fx / dfx;
        return 0;
    };

    if (fabs(x) < 1e-12) {
        cout << "Початкове наближення x0 не може бути 0" << endl;
        return -1;
    }

    for (int i = 0; i < max_iter; ++i) {
        double x_ = x;

        if (newtonStep(x) != 0) return -1;
        cout << "Ітерація " << i + 1 << ": x = " << x << endl;
        if (fabs(x - x_) < eps) return 0;
    }

    cout << "Метод Ньютона не збігся" << endl;
    return -1;
}

int Dyhotomia_class::solveQuadratic(double A, double B, double C, double &x1, double &x2) {

    auto discriminant = [A, B, C]() -> double {
        return B * B - 4 * A * C;
    };

    if (fabs(A) < 1e-12) {
        cout << "Коефіцієнт A = 0: рівняння не квадратне" << endl;
        return -1;
    }

    double D = discriminant();

    if (D > 0) {
        auto twoRoots = [A, B, D](double &koryn1, double &koryn2) {
            double sqrtD = sqrt(D);
            koryn1 = (-B + sqrtD) / (2 * A);
            koryn2 = (-B - sqrtD) / (2 * A);
        };
        twoRoots(x1, x2);
        return 2;
    } else if (fabs(D) < 1e-12) {
        x1 = x2 = -B / (2 * A);
        return 1;
    } else {
        auto complexRoots = [A, B, D]() {
            double B_ = -B / (2 * A);
            double koryn = sqrt(-D) / (2 * A);
            cout << "Комплексні корені: "
                 << B_ << " ± " << koryn << "i" << endl;
        };
        complexRoots();
        return 0;
    }
}