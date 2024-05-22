#pragma once


#include "Ip_Adr.h"
#include "Mac_Adr.h"
#include "machine.h"
#include <stdlib.h>
#include <stdbool.h>




typedef struct station{
    enum MachineType type;
    mac addrMac;
    ip addrIP;
}station;

machineType get_type_station(station *station);
mac get_mac_station(station *station);
ip get_ip_station(station *station);
