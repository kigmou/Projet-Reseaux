#include "switch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_switch(Switch *sw, const char *input) {
    tableCommutation *tblComm = (tableCommutation*)malloc(sizeof(tableCommutation));
    if (tblComm == NULL) {
        return -1; 
    }
    init_tblCommut(tblComm);

    if (sw == NULL || input == NULL) {
        return -1; 
    }

    char input_copy[100];
    strncpy(input_copy, input, sizeof(input_copy));
    input_copy[sizeof(input_copy) - 1] = '\0';

    char *token = strtok(input_copy, ";");
    if (token == NULL) return -1;
    sw->type = (enum MachineType)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return -1;
    sw->addrMac = init_macAddr(token);
    if (sw->addrMac == NULL) return -1; 

    token = strtok(NULL, ";");
    if (token == NULL) return -1;
    sw->nbPorts = atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return -1;
    sw->priorite = atol(token);

    sw->tblCommutation = tblComm;
    return 0; 
}

void afficheSwitch(Switch* sw) {
    if (sw != NULL) {
        printf("Switch :\n");
        printf("Type: %d\n", sw->type);
        printf("Nombre de Ports: %u\n", sw->nbPorts);
        printf("Priorité: %ld\n", sw->priorite);
        printf("Adresse mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
               sw->addrMac->adresse[0], sw->addrMac->adresse[1], sw->addrMac->adresse[2],
               sw->addrMac->adresse[3], sw->addrMac->adresse[4], sw->addrMac->adresse[5]);
        afficheTblCommut(sw->tblCommutation);
    } else {
        printf("Switch is NULL\n");
    }
}

void freeSwitch(Switch* sw) {
    if (sw != NULL) {
        if (sw->addrMac != NULL) {
            freeTblCommut(sw->tblCommutation);
            free(sw->addrMac);
            free(sw->tblCommutation);
        }
    }
}
