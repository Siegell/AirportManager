//
// Created by siegell on 2/9/18.
//

#include <fstream>
#include <iostream>
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
    while (true) {
        system("clear");
        cout << "Введите 1 для просмотра информации об аэропортах" << endl
             << "Введите 2 для изменения информации об аэропортах" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {
                for (auto i : airports) {
                    cout << i.getICAOCode() << " " << i.getMETAR() << endl;
                }
            }
            case '2': {
                cout << "Введите ICAO код аэропорта, который хотите изменить" << endl;
                string changeAirportICAO;
                cin >> changeAirportICAO;
                for (auto i : airports) {
                    if (i.getICAOCode() == changeAirportICAO) {
                        i.startUI();
                    }
                }
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
