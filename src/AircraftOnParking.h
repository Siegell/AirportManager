//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_AIRCRAFTONPARKING_H
#define AIRPORTMANAGER_AIRCRAFTONPARKING_H

#include <ostream>
#include "Aircraft.h"
#include "AircraftOnFly.h"

class AircraftOnParking : public Aircraft{
    string parkingNumber;
public:
    AircraftOnParking();

    AircraftOnParking(const string &bortNumber, const string &parkingNumber);

    virtual ~AircraftOnParking();

    friend ostream &operator<<(ostream &os, const AircraftOnParking &parking);
};


#endif //AIRPORTMANAGER_AIRCRAFTONPARKING_H
