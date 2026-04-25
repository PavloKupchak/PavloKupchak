#include "HolyScripture.h"
#include <iostream>

HolyScripture::HolyScripture() {}

HolyScripture::HolyScripture(std::string zavit_name) {
    setZavit(zavit_name);
}

int HolyScripture::setZavit(std::string zavit_name) {
    zavit = zavit_name;
    return 1;
}