#pragma once
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
};

double distance(const Point &p1, const Point &p2);
double cross(const Point &O, const Point &A, const Point &B);
double heronArea(const Triangle &t);
double area(const Triangle &t);
bool isDegenerate(const Triangle &t);
bool onBoundary(const Triangle &t, const Point &P);
bool contains(const Triangle &t, const Point &P);
bool containsCross(const Triangle &t, const Point &P);
double checkNumber(const string& prompt);
bool atTheTop(const Triangle& t, const Point& p);
void start();