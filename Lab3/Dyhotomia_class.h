#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class Dyhotomia_class {
public:
    Dyhotomia_class();
    ~Dyhotomia_class();
    void set_volumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    int count(double &x);
    int newton(double &x);

private:
    double a; 
    double b; 
    double eps;
    double f(double x);
    double df(double x);
};

#endif  