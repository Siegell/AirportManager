//
// Created by siegell on 2/9/18.
//

#include "AircraftOnFly.h"
#include <iterator>

AircraftOnFly::AircraftOnFly() = default;

AircraftOnFly::AircraftOnFly(const string &bortNumber, const string &departureAirportCode,
                             const string &arrivalAirportCode, const vector<string> &route, const string &routeNumber,
                             const vector<Pilot> &pilots) : Aircraft(bortNumber),
                                                            departureAirportCode(departureAirportCode),
                                                            arrivalAirportCode(arrivalAirportCode), route(route),
                                                            routeNumber(routeNumber), pilots(pilots) {}

ostream &operator<<(ostream &os, const AircraftOnFly &fly) {
    os << static_cast<const Aircraft &>(fly) << fly.departureAirportCode << ";" << fly.arrivalAirportCode << ";"
       << fly.routeNumber << ";";
    copy(fly.pilots.begin(), fly.pilots.end(), ostream_iterator<Pilot>(os, ","));
    os << ";";
    copy(fly.route.begin(), fly.route.end(), ostream_iterator<string>(os, ","));
    os << ";";
    return os;
}

