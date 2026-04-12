#include "Dyhotomia_class.h"
#include <iostream>
#include <cmath>

using namespace std;

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::set_volumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::f(double x) {
    return x - 2 + sin(1 / x);
}

double Dyhotomia_class::df(double x) {
    double h = 1e-6;
    return (f(x + h) - f(x - h)) / (2 * h);
}

int Dyhotomia_class::count(double &x) {
    double c;

    if (fabs(a) < 1e-12 || fabs(b) < 1e-12) {
        cout << "Інтервал торкається нуля" << endl;
        return -1;
    }

    if (f(a) * f(b) >= 0) {
        cout << "Однакові знаки на кінцях інтервалу" << endl;
        return -1;
    }

    while ((b - a) / 2 > eps) {
        c = (a + b) / 2;

        if (fabs(c) < 1e-12) {
            c = (c > 0) ? c + eps : c - eps;
        }

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    x = (a + b) / 2;
    return 0;
}

int Dyhotomia_class::newton(double &x) {
    int max_iter = 1000;

    for (int i = 0; i < max_iter; ++i) {
        if (fabs(x) < 1e-12) {
            cout << "Метод Ньютона досяг нуля" << endl;
            return -1;
        }

        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < 1e-12) {
            cout << "Похідна дорівнює нулю" << endl;
            return -1;
        }

        double x0 = x - fx / dfx;

        if (fabs(x0 - x) < eps) {
            x = x0;
            return 0;
        }

        x = x0;
    }

    cout << "Ньютон не збіжний" << endl;
    return -1;
}