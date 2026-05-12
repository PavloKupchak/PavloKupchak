#include "NewZavit.h"
#include "Koran.h"
#include "Biblia.h"
#include "Torah.h"
#include "Avesta.h"
#include "Similarity.h"
#include "Similarity2.h"
#include <iostream>

// int main() {
//     std::cout << "======================================================" << std::endl;
//     HolyBooks* book1 = new NewZavit("New Zavit", "27", "Greek");
//     book1->showInfo();
//     book1->showInfo("Hebrew, Aramaic, Ancient Greek");
//     book1->god();
//     book1->god("Who created this religion?");

//     std::cout << "======================================================" << std::endl;
//     HolyBooks* book2 = new Koran();
//     book2->showInfo();
//     book2->showInfo("Arabic");
//     book2->god();
//     book2->god("Who created this religion?");

//     std::cout << "======================================================" << std::endl;
//     HolyBooks* book3 = new Torah();
//     book3->showInfo();
//     book3->showInfo("Hebrew");
//     book3->god();
//     book3->god("Who created this religion?");

//     std::cout << "======================================================" << std::endl;
//     Similarity* book4 = new Similarity();
//     book4->showInfo();
//     book4->god();
//     book4->god("Who is the god of this books?");

//     std::cout << "======================================================" << std::endl;
//     Similarity2* book5 = new Similarity2();
//     book5->showInfo();
//     book5->god();
//     book5->god("Who is the god of this books?");

//     std::cout << "======================================================" << std::endl;
//     delete book1;
//     std::cout << std::endl;
//     delete book2;
//     std::cout << std::endl;
//     delete book3;
//     std::cout << std::endl;
//     delete book4;
//     std::cout << std::endl;
//     delete book5;
//     std::cout << std::endl;

//     return 0;
// }

int main() {
    std::cout << "======================================================" << std::endl;
    std::cout << "Constructors" << std::endl;
    Similarity* book = new Similarity();
    book->showInfo();
    book->god();
    book->god("Who is the god of this books?");
    std::cout << "======================================================" << std::endl;
    std::cout << "Destructors" << std::endl;
    delete book;
    std::cout << std::endl;

    std::cout << "======================================================" << std::endl;
    std::cout << "Constructors" << std::endl;
    Similarity2* book2 = new Similarity2();
    book2->showInfo();
    book2->god();
    book2->god("Who is the god of this books?");
    std::cout << "======================================================" << std::endl;
    std::cout << "Destructors" << std::endl;
    delete book2;
    std::cout << std::endl;
    
    return 0;
}