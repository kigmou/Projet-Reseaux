#pragma once

#include "Ip_Adr.h"
#include "Mac_Adr.h"
#include "machine.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct station{
    enum MachineType type;
    mac *addrMac;
    ip *addrIp;
}station;

int init_Station(station *st, const char *input);
void afficheStation(station* st);
void freeStation(station* st);
machineType get_type_station(station *station);
mac* get_mac_station(station *station);
ip* get_ip_station(station *station);