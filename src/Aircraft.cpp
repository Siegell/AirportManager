//
// Created by siegell on 2/9/18.
//

#include "Aircraft.h"

Aircraft::Aircraft() = default;

Aircraft::Aircraft(const string &bortNumber) : bortNumber(bortNumber){}

ostream &operator<<(ostream &os, const Aircraft &aircraft) {
    os << aircraft.bortNumber << ";";
    return os;
}
