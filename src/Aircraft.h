//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_AIRCRAFT_H
#define AIRPORTMANAGER_AIRCRAFT_H

#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Aircraft {
protected:
    string bortNumber;
public:
    Aircraft();

    explicit Aircraft(const string &bortNumber);

    friend ostream &operator<<(ostream &os, const Aircraft &aircraft);
};


#endif //AIRPORTMANAGER_AIRCRAFT_H
