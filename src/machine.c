#include "machine.h"
#include "station.h"

station* create_station(mac addrMac, ip addrIP) {
    station* s = malloc(sizeof(station));
    if (s == NULL) {
        return NULL;
    }

    s->type = STATION;
    s->addrMac = addrMac;
    s->addrIP = addrIP;

    return s;
}