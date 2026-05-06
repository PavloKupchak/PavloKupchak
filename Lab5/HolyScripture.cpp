#include "HolyScripture.h"
#include <iostream>

HolyScripture::HolyScripture() {}
HolyScripture::HolyScripture(std::string zavit_name) {
    std::cout << "! Constructor of HolyScripture class called" << std::endl;
    setZavit(zavit_name);
}

HolyScripture::~HolyScripture() {
    std::cout << "! Destructor of HolyScripture class called" << std::endl;
}

int HolyScripture::setZavit(std::string zavit_name) {
    zavit = zavit_name;
    return 1;
}