#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

#include <functional>

class Dyhotomia_class {
public:
    Dyhotomia_class();
    ~Dyhotomia_class();

    void set_volumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    void setFunction(std::function<double(double)> func);

    int count(double &x);
    int newton(double &x);

    int solveQuadratic(double A, double B, double C, double &x1, double &x2);

private:
    double a;
    double b;
    double eps;
    std::function<double(double)> f;
    std::function<double(double)> df;
};

#endif