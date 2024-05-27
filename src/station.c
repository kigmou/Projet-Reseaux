#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "station.h"

int init_Station(station *st, const char *input) {
    if (st == NULL || input == NULL) {
        return -1; 
    }

    char input_copy[100];
    strncpy(input_copy, input, sizeof(input_copy));
    input_copy[sizeof(input_copy) - 1] = '\0';

    char *token = strtok(input_copy, ";");
    printf("\n");
    if (token == NULL) return -1;
    st->type = (enum MachineType)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return -1;
    st->addrMac = init_macAddr(token);
    if (st->addrMac == NULL) return -1;

    token = strtok(NULL, ";");
    if (token == NULL) return -1;
    st->addrIp = init_IpAddr(token);
    if (st->addrMac == NULL) return -1; 

    return 0; 
}

void afficheStation(station* st) {
    if (st != NULL) {
        printf("Station :\n");
        printf("Type: %d\n", st->type);
        printf("Adresse mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
               st->addrMac->adresse[0], st->addrMac->adresse[1], st->addrMac->adresse[2],
               st->addrMac->adresse[3], st->addrMac->adresse[4], st->addrMac->adresse[5]);
        printf("Adresse Ip: %u.%u.%u.%u\n",
               st->addrIp->adresse[0], st->addrIp->adresse[1], st->addrIp->adresse[2],
               st->addrIp->adresse[3]);
    } else {
        printf("Station is NULL\n");
    }
}

void freeStation(station* st) {
    if (st != NULL) {
        if (st->addrMac != NULL) {
            free(st->addrMac);
            free(st->addrIp);
        }
        // Si des champs supplémentaires nécessitent une libération, ajoutez ici.
    }
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