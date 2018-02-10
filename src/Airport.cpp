//
// Created by siegell on 2/9/18.
//

#include "Airport.h"
#include <fstream>
#include <iostream>
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

void Airport::startUI() {
    while (true) {
        system("clear");
        cout << "Введите 1 для просмотра диспетчеров" << endl
             << "Введите 2 для просмотра текущего METAR" << endl
             << "Введите 3 для просмотра самолётов на стоянке" << endl
             << "Введите 4 для просмотра улетающих самолётов" << endl
             << "Введите 5 для просмотра прилетающих самолётов" << endl
             << "Введите 6 для просмотра пролетающих самолётов" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {

            }
            case '2': {

            }
            case '0': {
                if (c == '0') return;
            }
            default: {
                cout << "Желаете продолжить? (Введите н, если нет)" << endl;
                cin >> c;
                if (c == 'н') return;
            }
        }
    }
}

