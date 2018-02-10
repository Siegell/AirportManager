//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_AIRPORTMANAGER_H
#define AIRPORTMANAGER_AIRPORTMANAGER_H

#include "Airport.h"


class AirportManager {
    vector<Airport> airports;
public:

    AirportManager();

    explicit AirportManager(const vector<Airport> &airports);

    void save();

    void UI_start();
};


#endif //AIRPORTMANAGER_AIRPORTMANAGER_H
