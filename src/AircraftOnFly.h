//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_AIRCRAFTONFLY_H
#define AIRPORTMANAGER_AIRCRAFTONFLY_H

#include <ostream>
#include "Aircraft.h"
#include "AircraftOnParking.h"
#include "Pilot.h"

class AircraftOnFly : public Aircraft {
    string departureAirportCode;
    string arrivalAirportCode;
    vector<string> route;
    string routeNumber;
    vector<Pilot> pilots;
public:
    AircraftOnFly();

    AircraftOnFly(const string &bortNumber, const string &departureAirportCode, const string &arrivalAirportCode,
                  const vector<string> &route, const string &routeNumber, const vector<Pilot> &pilots);

    friend ostream &operator<<(ostream &os, const AircraftOnFly &fly);
};


#endif //AIRPORTMANAGER_AIRCRAFTONFLY_H
