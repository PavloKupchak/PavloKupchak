#include <iostream>
#include <cstdio>
#include "price.h"

using namespace std;

void multiply(Price& item, int quantity) {
    long AllKop = (long)item.hryvnia * 100 + item.kop;
    AllKop *= quantity;
    item.hryvnia = AllKop / 100;
    item.kop = AllKop % 100;
}

void add(Price& all, const Price& item) {
    long allKop = (long)all.hryvnia * 100 + all.kop;
    long itemKop = (long)item.hryvnia * 100 + item.kop;

    allKop += itemKop;
    all.hryvnia = allKop / 100;
    all.kop = allKop % 100;
}

void round(Price& cina) {
    int ostatok = cina.kop % 10;
    cina.kop = (cina.kop / 10) * 10;
    if (ostatok >= 8) {
        cina.kop += 10;
    }

    if (cina.kop >= 100) {
        cina.hryvnia += 1;
        cina.kop -= 100;
    }
}

void print(const Price& cina) {
    cout << cina.hryvnia << " hrn " << cina.kop << " kop" << endl;
}

void Total(FILE* file, Price& total) {
    Price item;
    int quantity;
    char name[50];

    while (true) {

        int result = fscanf(file, "%49s %d %hd %d", name, &item.hryvnia, &item.kop, &quantity);
        if (result == EOF) break;

        if (result != 4) {
            cout << "Format error!" << endl;
            return;
        }

        if (item.hryvnia < 0 || item.kop < 0 || quantity < 0) {
            cout << "Negative values aren't allowed!" << endl;
            return;
        }

        multiply(item, quantity);
        add(total, item);
    }

    cout << "Total price: "; print(total);
    round(total);
    cout << "Before payment: "; print(total);
}
