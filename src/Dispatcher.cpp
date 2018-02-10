//
// Created by siegell on 2/9/18.
//

#include <iostream>
#include "Dispatcher.h"

Dispatcher::Dispatcher() = default;

Dispatcher::Dispatcher(const string &Name, const string &position, double frequency) : Worker(Name), position(position),
                                                                                       frequency(frequency) {}

ostream &operator<<(ostream &os, const Dispatcher &dispatcher) {
    os << static_cast<const Worker &>(dispatcher) << dispatcher.position << ";" << dispatcher.frequency << ";";
    return os;
}

void Dispatcher::changeInfoUI() {
    while (true) {
        system("clear");
        cout << "Введите 1 для изменения имени диспетчера" << endl
             << "Введите 2 для изменения позиции диспетчера" << endl
             << "Введите 3 для изменения частоты диспетчера" << endl
             << "Для выхода назад нажмите 0" << endl;
        char c;
        cin >> c;
        switch (c) {
            case '1':{
                cout << "" << endl;
                string newName;
                cin >> newName;
                setName(newName);
            }
            case '2':{
                cout << "" << endl;
                string newPos;
                cin >> newPos;
                setPosition(newPos);
            }
            case '3':{
                cout << "" << endl;
                double newFreq;
                cin >> newFreq;
                setFrequency(newFreq);
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

void Dispatcher::setPosition(const string &position) {
    Dispatcher::position = position;
}

void Dispatcher::setFrequency(double frequency) {
    Dispatcher::frequency = frequency;
}
