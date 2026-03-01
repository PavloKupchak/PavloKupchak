#include <iostream>
#include <cstdio>
#include "price.h"

using namespace std;

void transfer(Price& cina) {
    if (cina.kop >= 100) {
        cina.hryvnia = cina.hryvnia + cina.kop / 100;
        cina.kop = cina.kop % 100;
    }
}

void add(Price& total, const Price& item) {
    total.hryvnia = total.hryvnia + item.hryvnia;
    total.kop = total.kop + item.kop;
    transfer(total);
}

void multiply(Price& item, int quantity) {
    item.hryvnia = item.hryvnia * quantity;
    item.kop = item.kop * quantity;
    transfer(item);
}

void round(Price& cina) {
    int ostatok = cina.kop % 10;
    if (ostatok >= 5)
        cina.kop = cina.kop + (10 - ostatok);
    else
        cina.kop = cina.kop - ostatok;
    transfer(cina);
}

void print(const Price& cina) {
    cout << cina.hryvnia << " hrn " << cina.kop << " kop" << endl;
}

void Total(FILE* file, Price& total){
    Price item;
    int quantity;

    while (fscanf(file, "%d %hi %d", &item.hryvnia, &item.kop, &quantity) == 3){
        multiply(item, quantity);
        add(total, item);
    }
}
