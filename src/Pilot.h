//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_PILOT_H
#define AIRPORTMANAGER_PILOT_H

#include <ostream>
#include "Worker.h"

class Pilot : public Worker {
    string rank;
public:
    Pilot();

    Pilot(const string &Name, const string &rank);

    friend ostream &operator<<(ostream &os, const Pilot &pilot);
};


#endif //AIRPORTMANAGER_PILOT_H
