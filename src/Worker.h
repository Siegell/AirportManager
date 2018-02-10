//
// Created by siegell on 2/9/18.
//

#ifndef AIRPORTMANAGER_WORKER_H
#define AIRPORTMANAGER_WORKER_H

#include <string>
#include <ostream>

using namespace std;

class Worker {
protected:
    string name;
public:
    Worker();

    explicit Worker(const string &Name);

    const string &getName() const;

    friend ostream &operator<<(ostream &os, const Worker &worker);
};


#endif //AIRPORTMANAGER_WORKER_H
