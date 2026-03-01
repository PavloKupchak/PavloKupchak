
#ifndef PRICE_H
#define PRICE_H

#include <iostream>
#include <cstdio>

struct Price {
    int hryvnia;
    short int kop;
};

void transfer(Price& cina);
void add(Price& total, const Price& item);
void multiply(Price& item, int quantity);
void round(Price& cina);
void print(const Price& cina);
void Total(FILE* file, Price& total);

#endif
