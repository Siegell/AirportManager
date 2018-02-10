//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_AIRPORT_H
#define AIRPORTMANAGER_AIRPORT_H

#include "AircraftOnFly.h"
#include "AircraftOnParking.h"
#include "Dispatcher.h"

class Airport {
    string ICAOCode;
    string METAR;
    vector<Dispatcher> control;
    vector<AircraftOnParking> parking;
    vector<AircraftOnFly> departureAircrafts;
    vector<AircraftOnFly> arrivingAircrafts;
    vector<AircraftOnFly> transitAircrafts;
public:
    Airport();

    Airport(const string &ICAOCode, const string &METAR, const vector<Dispatcher> &control,
            const vector<AircraftOnParking> &parking, const vector<AircraftOnFly> &departureAircrafts,
            const vector<AircraftOnFly> &arrivingAircrafts, const vector<AircraftOnFly> &transitAircrafts);

    const string &getMETAR() const;

    const string &getICAOCode() const;

    void save();

    void startUI();

    void setParamsUI();

    void setICAOCode(const string &ICAOCode);

    void setMETAR(const string &METAR);

    void changeControl();

    void coutControlInfo() const;
};


#endif //AIRPORTMANAGER_AIRPORT_H
