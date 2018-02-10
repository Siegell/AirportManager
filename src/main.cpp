#include <iostream>
#include "AirportManager.h"

int main() {
    Pilot Cap("Cap", "Capitain");
    Pilot FO("FO", "FirstOfficer");
    Dispatcher Disp("Disp", "Tower", 123.45);
    AircraftOnParking CornCraft("EW-A11KW", "12b");
    vector<string> UMII_UMMS = {"UMII", "UMMS"};
    vector<Pilot> DreamTeam = {Cap, FO};
    AircraftOnFly Old("EW-A11PZ", "UMII", "UMMS", UMII_UMMS, "1Old", DreamTeam);
    vector<AircraftOnParking> VitebskPark = {CornCraft};

    Airport Vitebsk("UMII", "CAVOK", {Disp}, VitebskPark, {Old}, {}, {Old});
    Airport Minsk2("UMMS", "CAVOK", {}, {}, {}, {Old}, {Old});
    AirportManager airportManager({Vitebsk, Minsk2});

    //перенести в UI_start
    while (true) {
        system("clear");
        cout << "Добро пожаловать в Airport Manager" << endl
             << "Для создания новой базы введите 1" << endl
             << "Для загрузки предыдущей базы введите 2" << endl
             << "Для работы с текущей базой нажмите 3" << endl
             << "Для сохранения текущей базы нажмите 4" << endl
             << "Для выхода нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1': {
                airportManager = AirportManager();
                break;
            }
            case '3': {
                airportManager.UI_start();
                break;
            }
            case '4': {
                airportManager.save();
                break;
            }
            case '0': {
                return 0;
            }
        }
    }
}