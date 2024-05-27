#include "switch.h"
#include "Mac_Adr.h"
#include <stdlib.h>

switch* createSwitch(typeMachine type, unsigned int nbPorts, long int priorite) {
    switch *sw = (switch*)malloc(sizeof(switch));
    if (sw != NULL) {
        sw->type = type;
        sw->nbPorts = nbPorts;
        sw->priorite = priorite;
    }

    return sw;
}

void afficheSwitch(graphe* g) {
    if (sw != NULL) {
        printf("Switch :\n")
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