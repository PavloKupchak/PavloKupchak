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
    return sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
}

double gaussArea(const Triangle &t) {
    return fabs(
        (t.A.x * (t.B.y - t.C.y) +
         t.B.x * (t.C.y - t.A.y) +
         t.C.x * (t.A.y - t.B.y))) / 2;
}

double perimeter(const Triangle &t) {
    return distance(t.A, t.B) +
           distance(t.B, t.C) +
           distance(t.C, t.A);
}

bool Triangle::contains(const Point &P) const {
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();
    return fabs(S_main - S_sum) < (1e-9);

}

double Triangle::area() const {
    return heronArea(*this);
}

bool isDegenerate(const Triangle &t) {
    return t.area() < 1e-9;
}

bool onSegment(const Point &A, const Point &B, const Point &P) { 
    return fabs(cross(A, B, P)) < 1e-9 &&
           min(A.x, B.x) - 1e-9 <= P.x && P.x <= max(A.x, B.x) + 1e-9 &&
           min(A.y, B.y) - 1e-9 <= P.y && P.y <= max(A.y, B.y) + 1e-9;
}

bool onBoundary(const Triangle &t, const Point &P) {
    return onSegment(t.A, t.B, P) ||
           onSegment(t.B, t.C, P) ||
           onSegment(t.C, t.A, P);
}

bool atTheTop(const Triangle& t, const Point& p) {
    return (fabs(p.x - t.A.x) < 1e-9 && fabs(p.y - t.A.y) < 1e-9) || 
           (fabs(p.x - t.B.x) < 1e-9 && fabs(p.y - t.B.y) < 1e-9) || 
           (fabs(p.x - t.C.x) < 1e-9 && fabs(p.y - t.C.y) < 1e-9);
}

bool containsCross(const Triangle &t, const Point &P) {
    double d1 = cross(t.A, t.B, P);
    double d2 = cross(t.B, t.C, P);
    double d3 = cross(t.C, t.A, P);

    bool has_neg = (d1 < -1e-9) || (d2 < -1e-9) || (d3 < -1e-9);
    bool has_pos = (d1 > 1e-9) || (d2 > 1e-9) || (d3 > 1e-9);

    return !(has_neg && has_pos);
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
            cout << "Помилка! Введіть число" << endl;
        }
    }
}

void start() {
    Triangle T;

    cout << "Введіть координати трикутника:" << endl;
    T.A.x = checkNumber("Ax: ");
    T.A.y = checkNumber("Ay: ");
    cout << endl;

    T.B.x = checkNumber("Bx: ");
    T.B.y = checkNumber("By: ");
    cout << endl;

    T.C.x = checkNumber("Cx: ");
    T.C.y = checkNumber("Cy: ");

    if ((fabs(T.A.x - T.B.x) < 1e-9 && fabs(T.A.y - T.B.y) < 1e-9) ||
        (fabs(T.B.x - T.C.x) < 1e-9 && fabs(T.B.y - T.C.y) < 1e-9) ||
        (fabs(T.C.x - T.A.x) < 1e-9 && fabs(T.C.y - T.A.y) < 1e-9)) {
        cout << "Трикутник має однакові вершини!" << endl;
        return;
    }

    if (isDegenerate(T)) {
        cout << "Трикутник вироджений!" << endl;
        return;
    }

    int n;
    while (true) {
        cout << "\nКількість точок: ";
        n = (int)checkNumber("");
        if (n > 0) break;
        cout << "Кількість точок має бути більшою за 0" << endl;
    }
    
    for (int i = 0; i < n; ++i) {
        Point p;
        
        cout << "\nТочка " << i + 1 << ":" << endl;
        p.x = checkNumber("x: ");
        p.y = checkNumber("y: ");
        
        cout << "\nПлоща (Герон): " << heronArea(T) << endl;
        cout << "Площа (Гаусс): " << gaussArea(T) << endl;
        cout << "Периметр: " << perimeter(T) << endl;

        cout << "\nМетод площ:" << endl;
        if (atTheTop(T, p))
            cout << "На вершині" << endl;
        else if (onBoundary(T, p))
            cout << "На межі" << endl;
        else if (T.contains(p))
            cout << "Всередині" << endl;
        else
            cout << "Поза трикутником" << endl;

        cout << "\nМетод векторів:" << endl;
        if (atTheTop(T, p))
            cout << "На вершині" << endl;
        else if (onBoundary(T, p))
            cout << "На межі" << endl;
        else if (containsCross(T, p))
            cout << "Всередині" << endl;
        else
            cout << "Поза трикутником" << endl;
    }
}