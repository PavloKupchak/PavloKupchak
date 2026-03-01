#include <iostream>
#include <cstdio>
#include "price.h"
using namespace std;

int main() {
    FILE* my_file = fopen("items.txt", "r");
    if (!my_file) { 
        cout << "File opening error"; return 1; 
    }
    
    Price total = {0,0};
    Total(my_file, total);
    fclose(my_file);

    cout << "Total price: "; print(total);
    round(total);
    cout << "Before payment: "; print(total);
};