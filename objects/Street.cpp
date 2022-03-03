#include "Street.h"

Street::Street() {}

Street::~Street() {}

void Street::setName(const std::string &n) {
    Street::name = n;
}

void Street::setLength(int l) {
    Street::length = l;
}

const std::string &Street::getName() const {
    return name;
}

int Street::getLength() const {
    return length;
}
