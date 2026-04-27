#include "NewZavit.h"
#include "Koran.h"
#include "Biblia.h"

int main()
{
    HolyBooks* book;

    book = new NewZavit("New Zavit", "27", "Greek");
    book->showInfo();
    book->god();

    book = new Koran();
    book->showInfo();
    book->god();

    return 0;
}