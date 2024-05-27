#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "switch.h"

Switch* init_switch(char *config) {
    //2;01:45:23:a6:f7:ab;8;1024
    Switch *sw = (Switch*)malloc(sizeof(Switch));
    if (sw == NULL) {
        free(sw);
        sw = NULL;
        return NULL;
    }
    char* configCopy = strdup(config); 
    printf(configCopy);
    printf("\n");
    if (configCopy == NULL) {
        free(sw);
        return NULL;
    }
    char* token = strtok(configCopy, ";");
    if (token == NULL) {
        free(sw);
        sw = NULL;
        return NULL;
    }
    
    sw->type = (enum MachineType) atoi(token);
    token = strtok(NULL, ";");
    printf(token);
    printf("\n");

    if (token == NULL) {
        free(sw);
        sw = NULL;
        return NULL;
    }
    char* tokenCpy;
    strcpy(tokenCpy, token); 
    sw->addrMac = init_macAddr(tokenCpy);
    printf("token");
    token = strtok(NULL, ";");

    sw->nbPorts = (unsigned int) atoi(token);
    token = strtok(NULL, ";");
    printf(token);
    printf("\n");

    sw->priorite = (long int) atoi(token);
    token = strtok(NULL, ";");
    printf(token);
    printf("\n");

    if (token!=NULL) {
        free(sw);
        sw = NULL;
        return NULL;
    }
    return sw;
}

void afficheSwitch(Switch* sw) {
    if (sw != NULL) {
        printf("Switch :\n");
        printf("Type: %d\n", sw->type);
        printf("Nombre de Ports: %u\n", sw->nbPorts);
        printf("Priorité: %ld\n", sw->priorite);
        // Afficher les informations de tbCommutation si nécessaire
    } else {
        printf("Switch is NULL\n");
    }
}

void freeSwitch(Switch* sw) {
    if (sw != NULL) {
        // Libérer la mémoire de tbCommutation si nécessaire
        free(sw);
    }
}