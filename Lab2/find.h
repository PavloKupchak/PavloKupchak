#ifndef FIND_H
#define FIND_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;                  
    bool contains(const Point &P) const;  
};

double distance(const Point &p1, const Point &p2);
double cross(const Point &O, const Point &A, const Point &B);
double heronArea(const Triangle &t); 
double heronAreaFixed(const Triangle &t);     
double gaussArea(const Triangle &t);     
double perimeter(const Triangle &t);
bool isDegenerate(const Triangle &t);
bool onSegment(const Point &A, const Point &B, const Point &P);
bool onBoundary(const Triangle &t, const Point &P);
bool atTheTop(const Triangle &t, const Point &p);
bool containsCross(const Triangle &t, const Point &P);
double checkNumber(const string& prompt);
void start();

#endif