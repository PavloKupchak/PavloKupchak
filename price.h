#ifndef PRICE_H
#define PRICE_H

<<<<<<< HEAD
#include <iostream>
#include <cstdio>

=======
>>>>>>> 8ee2bb1 (lab1)
struct Price {
    int hryvnia;
    short int kop;  
};

void transfer(Price& cina);
void add(Price& total, const Price& item);
<<<<<<< HEAD
void multiply(Price& item, int quantity);
void round(Price& cina);
void print(const Price& cina);
void Total(FILE* file, Price& total);
=======
void multiply(Price& cina, int quantity);
void round(Price& cina);
void print(const Price& cina);
>>>>>>> 8ee2bb1 (lab1)

#endif