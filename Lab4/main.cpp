#include "NewZavit.h"
#include "Koran.h"
#include "Biblia.h"

int main() {
    HolyBooks* book;
    book = new NewZavit("New Zavit", "27", "Greek");
    book->showInfo();
    book->showInfo("Hebrew, Aramaic, Ancient Greek");
    book->god();
    book->god("Who created this religion?");
    delete book;

    book = new Koran();
    book->showInfo();
    book->showInfo("Arabic");
    book->god();
    book->god("Who created this religion?");
    delete book;

    return 0;
}