#include "find.h"

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(const Triangle &t) {
    return heronArea(t);
}

bool isDegenerate(const Triangle &t) {
    return area(t) < 1e-9;
}

bool onBoundary(const Triangle &t, const Point &P) {
    double d1 = cross(t.A, t.B, P);
    double d2 = cross(t.B, t.C, P);
    double d3 = cross(t.C, t.A, P);
    return (fabs(d1) < 1e-9 || fabs(d2) < 1e-9 || fabs(d3) < 1e-9);
}

bool contains(const Triangle &t, const Point &P) {
    Triangle T1 = {t.A, t.B, P};
    Triangle T2 = {t.B, t.C, P};
    Triangle T3 = {t.C, t.A, P};
    double Ssum = area(T1) + area(T2) + area(T3);
    return fabs(area(t) - Ssum) < 1e-9;
}

bool containsCross(const Triangle &t, const Point &P) {
    double d1 = cross(t.A, t.B, P);
    double d2 = cross(t.B, t.C, P);
    double d3 = cross(t.C, t.A, P);
    return (d1 >= 0 && d2 >= 0 && d3 >= 0) ||
           (d1 <= 0 && d2 <= 0 && d3 <= 0);
}

bool atTheTop(const Triangle& t, const Point& p) {
    return (fabs(p.x - t.A.x) < 1e-9 && fabs(p.y - t.A.y) < 1e-9) || 
           (fabs(p.x - t.B.x) < 1e-9 && fabs(p.y - t.B.y) < 1e-9) || 
           (fabs(p.x - t.C.x) < 1e-9 && fabs(p.y - t.C.y) < 1e-9);
}

double checkNumber(const string& prompt) {
    string line;
    double x;

    while (true) {
        cout << prompt;
        getline(cin, line);

        stringstream ss(line);
        if (ss >> x && ss.eof()) {
            return x;
        } else {
            cout << "Помилка! Введіть число\n";
        }
    }
}

void start() {
    Triangle T;
    cout << "Введіть координати вершин трикутника:" << endl;
    T.A.x = checkNumber("Ax: ");
    T.A.y = checkNumber("Ay: ");
    cout << endl;
    T.B.x = checkNumber("Bx: ");
    T.B.y = checkNumber("By: ");
    cout << endl;
    T.C.x = checkNumber("Cx: ");
    T.C.y = checkNumber("Cy: ");

    if (T.A.x == T.B.x && T.A.y == T.B.y || 
        T.B.x == T.C.x && T.B.y == T.C.y || 
        T.C.x == T.A.x && T.C.y == T.A.y) {
        cout << "Трикутник не може мати однакові вершини!" << endl;
        return;
    }

    if (isDegenerate(T)) {
        cout << "Трикутник є виродженим!" << endl;
        return;
    }

    int n;
    while (true) {
        cout << endl;
        n = (int)checkNumber("Введіть кількість точок: ");
        if (n > 0) break;
        cout << "Кількість точок повинна бути додатною!" << endl;
    }
    
    for (int i = 0; i < n; ++i) {
        Point p;
        cout << endl;
        cout << "Точка " << i + 1 << ": " << endl;
        p.x = checkNumber("x: ");
        p.y = checkNumber("y: ");

        cout << endl;
        cout << "Метод площ: " << endl;
        if (atTheTop(T, p))
            cout << "Точка на вершині" << endl;
        else if (onBoundary(T, p))
            cout << "Точка на межі" << endl;
        else if (contains(T, p))
            cout << "Точка всередині" << endl;
        else
            cout << "Точка поза трикутником" << endl;

        cout << endl;
        cout << "Метод векторів:" << endl;
        if (atTheTop(T, p))
            cout << "Точка на вершині" << endl;
        else if (onBoundary(T, p))
            cout << "Точка на межі" << endl;
        else if (containsCross(T, p))
            cout << "Точка всередині" << endl;
        else
            cout << "Точка поза трикутником" << endl;
    }
}