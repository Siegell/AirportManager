//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_DISPATCHER_H
#define AIRPORTMANAGER_DISPATCHER_H

#include <ostream>
#include "Worker.h"

class Dispatcher : public Worker {
    string position;
    double frequency;
public:
    Dispatcher();

    Dispatcher(const string &Name, const string &position, double frequency);

    friend ostream &operator<<(ostream &os, const Dispatcher &dispatcher);
};


#endif //AIRPORTMANAGER_DISPATCHER_H
