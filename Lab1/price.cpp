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
  int round = cina.kop % 10;
  cina.kop = cina.kop / 10 * 10; 

  if (round >= 8) {
    cina.kop += 10;  
   }
    transfer(cina);
}

void print(const Price& cina) {
    cout << cina.hryvnia << " hrn " << cina.kop << " kop" << endl;
}

void Total(FILE* file, Price& total) {
    Price item;
    int quantity;

    while (true) {

        int result = fscanf(file, "%d %hd %d", &item.hryvnia, &item.kop, &quantity);
        if (result == -1) break;

        if (result != 3) {
            cout << "Format error!" << endl;
            return;
        }

        if (item.hryvnia < 0 || item.kop < 0 || quantity < 0) {
            cout << "Negative values aren't allowed!" << endl;
            return;
        }

        if (item.kop >= 100) {
            cout << "Incorrect number!" << endl;
            return;
        }

        multiply(item, quantity);
        add(total, item);
    }

    cout << "Total price: "; print(total);
    round(total);
    cout << "Before payment: "; print(total);
}
