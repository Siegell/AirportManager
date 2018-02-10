//
// Created by siegell on 2/9/18.
//

#include "Worker.h"

Worker::Worker(const string &Name) : name(Name) {}

ostream &operator<<(ostream &os, const Worker &worker) {
    os << worker.name << ";";
    return os;
}

Worker::Worker() = default;
