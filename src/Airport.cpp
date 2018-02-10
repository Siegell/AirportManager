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
             << "Введите 7 для изменения параметров" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {
                coutControlInfo();
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '2': {
                cout << METAR << endl;
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '3': {
                cout << "Бортовой номер самолёта; Номер стоянки;" << endl;
                for (auto i : parking) {
                    cout << i << endl;
                }
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '4': {
                cout
                        << "Бортовой номер самолёта; Аэропорт вылета; Аэропорт прилёта; Номер рейса; Экипаж; ICAO коды аэропортов обеспечивающих контроль;"
                        << endl;
                for (auto i : departureAircrafts) {
                    cout << i << endl;
                }
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '5': {
                cout
                        << "Бортовой номер самолёта; Аэропорт вылета; Аэропорт прилёта; Номер рейса; Экипаж; ICAO коды аэропортов обеспечивающих контроль;"
                        << endl;
                for (auto i : arrivingAircrafts) {
                    cout << i << endl;
                }
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '6': {
                cout
                        << "Бортовой номер самолёта; Аэропорт вылета; Аэропорт прилёта; Номер рейса; Экипаж; ICAO коды аэропортов обеспечивающих контроль;"
                        << endl;
                for (auto i : transitAircrafts) {
                    cout << i << endl;
                }
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '7': {
                setParamsUI();
                break;
            }
            case '0': {
                if (c == '0') return; // непонятное срабатывание кейса при c != '0'
            }
            default: {
                cout << "Желаете продолжить? (Введите н, если нет)" << endl;
                cin >> c;
                if (c == 'н') return;
            }
        }
    }
}

void Airport::coutControlInfo() const {
    cout << "Имя диспетчера; Позиция контроля; Часота диспетчера;\n";
    for (auto i : control) {
        cout << i << endl;
    }
}

void Airport::setParamsUI() {
    while (true) {
        system("clear");
        cout << "Введите 1 для изменения кода ICAO" << endl
             << "Введите 2 для изменения информации METAR" << endl
             << "Введите 3 для изменения контроля" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {
                cout << "Введите новый код ICAO" << endl;
                string newICAOCode;
                cin >> newICAOCode;

                setICAOCode(newICAOCode);
                break;
            }
            case '2': {
                cout << "Введите новую информацию о погоде METAR" << endl;
                string newMETARCode;
                cin >> newMETARCode;

                setMETAR(newMETARCode);
                break;
            }
            case '3': {
                changeControl();
                break;
            }
            case '0': {
                if (c == '0') return; // непонятное срабатывание кейса при c != '0'
            }
            default: {
                cout << "Желаете продолжить? (Введите н, если нет)" << endl;
                cin >> c;
                if (c == 'н') return;
            }
        }
    }
}

void Airport::setICAOCode(const string &ICAOCode) {
    Airport::ICAOCode = ICAOCode;
}

void Airport::setMETAR(const string &METAR) {
    Airport::METAR = METAR;
}

void Airport::changeControl() {
    while (true) {
        system("clear");
        cout << "Введите 1 для просмотра информации о контроле" << endl
             << "Введите 2 для добавления диспетчера" << endl
             << "Введите 3 для изменения информации о диспетчере" << endl
             << "Введите 4 для удаления диспетчера" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {

                coutControlInfo();
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '2': {
                string name, position;
                double frequency;
                cout << "Введите имя диспетчера" << endl;
                cin >> name;
                cout << "Введите позицию диспетчера" << endl;
                cin >> position;
                cout << "Введите частоту диспетчера" << endl;
                cin >> frequency;
                Dispatcher newDisp(name, position, frequency);
                control.push_back(newDisp);
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '3': {
                cout << "Введите имя диспетчера" << endl;
                string chDispName;
                cin >> chDispName;
                for (auto i : control){
                    if (i.getName() == chDispName){
                        i.changeInfoUI();
                    }
                }
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '4': {
                cout << "Введите имя диспетчера" << endl;
                string delDispName;
                cin >> delDispName;
                bool NeBool = true;
                for (auto i = control.begin(); i <= control.end(); ++i) {
                    if (i->getName() == delDispName) {
                        cout << "Вы действительно хотите удалить этого диспетчера: (Введите УДАЛИТЬ для подтверждения)"
                             << endl
                             << *i << endl;
                        string checkStr;
                        cin >> checkStr;
                        if (checkStr == "УДАЛИТЬ") {
                            control.erase(i);
                            NeBool = false;
                        }
                    }
                }
                if (NeBool) {
                    cout << "Диспетчер не удалён" << endl;
                } else {
                    cout << "Диспетчер удалён" << endl;
                };
                cout << "Желаете продолжить? (Введите 0, если нет)" << endl;
                cin >> c;
                if (c == '0') return;
                break;
            }
            case '0': {
                return;
            }
            default: {
                cout << "Желаете продолжить? (Введите н, если нет)" << endl;
                cin >> c;
                if (c == 'н') return;
            }
        }
    }
}

