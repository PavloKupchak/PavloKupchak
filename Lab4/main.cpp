#include "NewZavit.h"
#include "Koran.h"

int main()
{
    Koran koran;
    NewZavit newZavit("New Zavit", "27", "Greek");

    newZavit.god();
    newZavit.showInfo();

    koran.god();
    koran.showInfo();

    return 0;
}