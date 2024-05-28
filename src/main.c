#include <stdio.h>
#include "switch.h"
#include "station.h"
#include "reseau.h"


int main() {
    char *input = "2;01:45:23:a6:f7:ab;8;1024";
    Switch sw;

    if (init_switch(&sw, input) == 0) {
        printf("Switch initialisé ! \n");
    } else {
        printf("Le switch n'a pas pu être initialisé.\n");
    }
    

    afficheSwitch(&sw);
    
    char *input2 = "1;54:d6:a6:82:c5:23;130.79.80.21";
    station st;

    if (init_Station(&st, input2) == 0) {
        printf("Station initialisé ! \n");
    } else {
        printf("La station n'a pas pu être initialisé.\n");
    }

    char *input3 = "1;c8:69:72:5e:43:af;130.79.80.27";
    station st2;

    if (init_Station(&st2, input3) == 0) {
        printf("Station initialisé ! \n");
    } else {
        printf("La station n'a pas pu être initialisé.\n");
    }

    char *input4 = "1;77:ac:d6:82:12:23;130.79.80.42";
    station st3;

    if (init_Station(&st3, input4) == 0) {
        printf("Station initialisé ! \n \n");
    } else {
        printf("La station n'a pas pu être initialisé.\n");
    }

    afficheStation(&st);
    afficheStation(&st2);
    afficheStation(&st3);
    freeStation(&st);
    freeStation(&st2);
    freeStation(&st3);
    freeSwitch(&sw);

    printf("\n \n DEBUT DE LA PHASE 3 \n \n");
    //Partie 3
    reseau *res=(reseau*)malloc(sizeof(reseau));
    init_reseau(res);
    res=create_reseau();
    afficherReseau(res);

    trame *temp =malloc(sizeof(trame));
    station *structEnvoie = (station *)res->graphe->listeMachine[1].ptr;
    station *structRecoit = (station *)res->graphe->listeMachine[2].ptr;
    mac *sourceP =get_mac_station(structEnvoie);
    mac *destinationP=get_mac_station(structRecoit);
    char messageP[1500]="mon gros caca la";
    short unsigned int typeP=2;
    init_trame(temp, sourceP, destinationP, messageP, typeP);
    envoyer_trame(temp, res->graphe);
    afficherReseau(res);
    trame *temp2 =malloc(sizeof(trame));
    station *structEnvoie2 = (station *)res->graphe->listeMachine[3].ptr;
    station *structRecoit2 = (station *)res->graphe->listeMachine[1].ptr;
    mac *sourceP2 =get_mac_station(structEnvoie2);
    mac *destinationP2=get_mac_station(structRecoit2);
    char messageP2[1500]="mon gros caca la2";
    short unsigned int typeP2=2;
    init_trame(temp2, sourceP2, destinationP2, messageP2, typeP2);
    envoyer_trame(temp2, res->graphe);
    afficherReseau(res);
    return 0;
}
