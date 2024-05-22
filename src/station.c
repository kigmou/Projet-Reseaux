#include "station.h"

machineType get_type_station(station *station){
      if(station==NULL) exit(EXIT_FAILURE);

    
    return station->type;
}
mac get_mac_station(station *station){
    if(station==NULL) exit(EXIT_FAILURE);

    return station->addrMac;
}
ip get_ip_station(station *station){
    if(station==NULL) exit(EXIT_FAILURE);


    return station->addrIP;
}