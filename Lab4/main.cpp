#include "NewZavit.h"
#include "Koran.h"
#include "Biblia.h"

int main() {
    HolyBooks* book1 = new NewZavit("New Zavit", "27", "Greek");
    book1->showInfo();
    book1->god();
    delete book1;

    HolyBooks* book2 = new Koran();
    book2->showInfo();
    book2->god();
    delete book2;

    return 0;
}