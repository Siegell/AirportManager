//
// Created by siegell on 2/9/18.
//

#include "Airport.h"
#include <fstream>
#include <iterator>

Airport::Airport() = default;

Airport::Airport(const string &ICAOCode, const string &METAR, const vector<Dispatcher> &control,
                 const vector<AircraftOnParking> &parking, const vector<AircraftOnFly> &departureAircrafts,
                 const vector<AircraftOnFly> &arrivingAircrafts, const vector<AircraftOnFly> &transitAircrafts)
        : ICAOCode(ICAOCode), METAR(METAR), control(control), parking(parking),
          departureAircrafts(departureAircrafts), arrivingAircrafts(arrivingAircrafts),
          transitAircrafts(transitAircrafts) {}

const string &Airport::getMETAR() const {
    return METAR;
}

void Airport::setMETAR(const string &METAR) {
    Airport::METAR = METAR;
}

const string &Airport::getICAOCode() const {
    return ICAOCode;
}

void Airport::save() {
    string saveDir = "res/" + ICAOCode + "/";
    string command = "mkdir " + saveDir;

    system(command.c_str());


    string controlOutFile = saveDir + "Control.txt";
    ofstream controlOFS(controlOutFile);
    copy(control.begin(), control.end(), ostream_iterator<Dispatcher>(controlOFS, "\n"));
    controlOFS.close();

    string parkingOutFile = saveDir + "Parking.txt";
    ofstream parkingOFS(parkingOutFile);
    copy(parking.begin(), parking.end(), ostream_iterator<AircraftOnParking>(parkingOFS, "\n"));
    parkingOFS.close();

    string DepartureOutFile = saveDir + "Departure.txt";
    ofstream DepartureOFS(DepartureOutFile);
    copy(departureAircrafts.begin(), departureAircrafts.end(), ostream_iterator<AircraftOnFly>(DepartureOFS, "\n"));
    DepartureOFS.close();

    string ArriveOutFile = saveDir + "Arrive.txt";
    ofstream ArriveOFS(ArriveOutFile);
    copy(arrivingAircrafts.begin(), arrivingAircrafts.end(), ostream_iterator<AircraftOnFly>(ArriveOFS, "\n"));
    ArriveOFS.close();

    string transitOutFile = saveDir + "Transit.txt";
    ofstream transitOFS(transitOutFile);
    copy(transitAircrafts.begin(), transitAircrafts.end(), ostream_iterator<AircraftOnFly>(transitOFS, "\n"));
    transitOFS.close();
}

