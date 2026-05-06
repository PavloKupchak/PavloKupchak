#include "NewZavit.h"
#include "Koran.h"
#include "Biblia.h"
#include "Similarity.h"
#include <iostream>

int main() {
    std::cout << "======================================================" << std::endl;
    HolyBooks* book1 = new NewZavit("New Zavit", "27", "Greek");
    book1->showInfo();
    book1->showInfo("Hebrew, Aramaic, Ancient Greek");
    book1->god();
    book1->god("Who created this religion?");

    std::cout << "======================================================" << std::endl;
    HolyBooks* book2 = new Koran();
    book2->showInfo();
    book2->showInfo("Arabic");
    book2->god();
    book2->god("Who created this religion?");

    std::cout << "======================================================" << std::endl;
    Similarity* book3 = new Similarity();
    book3->showInfo();
    book3->god();
    book3->god("Who is the god of this books?");

    std::cout << "======================================================" << std::endl;
    delete book1;
    std::cout << std::endl;
    delete book2;
    std::cout << std::endl;
    delete book3;
    std::cout << std::endl;

    return 0;
}