#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "station.h"

station* init_station(char *config)
{
    //1;54:d6:a6:82:c5:23;130.79.80.21
    station *stat = malloc(sizeof(station));
    if (stat == NULL) {
        free(stat);
        stat = NULL;
        return NULL;
    }

    char* token = strtok(config, ";");
    stat->type = (enum MachineType) atoi(token);
    token = strtok(NULL, ";");
    /*if (stat->type==NULL) {
        free(stat);
        stat = NULL;
        return NULL;
    }*/

    stat->addrMac = init_macAddr(token);
    token = strtok(NULL, ";");
    /*if (stat->addrMac==NULL) {
        free(stat);
        stat = NULL;
        stat->type==NULL
        return NULL;
    }*/

    stat->addrIp = init_ipAddr(token);
    token = strtok(NULL, ";");
    if (token!=NULL) {
        free(stat);
        stat = NULL;
        return NULL;
    }

    return stat;
}

machineType get_type_station(station *station){
      if(station==NULL) exit(EXIT_FAILURE);
    return station->type;
}
mac* get_mac_station(station *station){
    if(station==NULL) exit(EXIT_FAILURE);

    return station->addrMac;
}
ip* get_ip_station(station *station){
    if(station==NULL) exit(EXIT_FAILURE);


    return station->addrIp;
}