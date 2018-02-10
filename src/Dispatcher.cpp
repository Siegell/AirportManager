//
// Created by siegell on 2/9/18.
//

#include "Dispatcher.h"

Dispatcher::Dispatcher() = default;

Dispatcher::Dispatcher(const string &Name, const string &position, double frequency) : Worker(Name), position(position),
                                                                                       frequency(frequency) {}

ostream &operator<<(ostream &os, const Dispatcher &dispatcher) {
    os << static_cast<const Worker &>(dispatcher) << dispatcher.position << ";" << dispatcher.frequency << ";";
    return os;
}
