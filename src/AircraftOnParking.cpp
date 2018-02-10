//
// Created by siegell on 2/9/18.
//

#include "AircraftOnParking.h"

AircraftOnParking::AircraftOnParking() = default;

AircraftOnParking::AircraftOnParking(const string &bortNumber, const string &parkingNumber) : Aircraft(bortNumber),
                                                                                              parkingNumber(
                                                                                                      parkingNumber) {}

ostream &operator<<(ostream &os, const AircraftOnParking &parking) {
    os << static_cast<const Aircraft &>(parking) << parking.parkingNumber << ";";
    return os;
}

AircraftOnParking::~AircraftOnParking() {

}
