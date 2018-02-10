//
// Created by siegell on 2/9/18.
//

#include "Pilot.h"

Pilot::Pilot() = default;

Pilot::Pilot(const string &Name, const string &rank) : Worker(Name), rank(rank) {}

ostream &operator<<(ostream &os, const Pilot &pilot) {
    os << static_cast<const Worker &>(pilot) << pilot.rank << ";";
    return os;
}
