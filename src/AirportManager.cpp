//
// Created by siegell on 2/9/18.
//

#include <fstream>
#include "AirportManager.h"

AirportManager::AirportManager() = default;

AirportManager::AirportManager(const vector<Airport> &airports) : airports(airports) {}

void AirportManager::save() {

    system("mkdir res");


    ofstream airportData("res/AirportsData.txt");

    airportData << "ICAOCode;currentMETAR;" << endl;

    for (auto i : airports) {
        airportData << i.getICAOCode() << ";" << i.getMETAR() << ";" << endl;
    }

    airportData.close();

    for (auto i : airports) {
        i.save();
    }

}

void AirportManager::UI_start() {

}
