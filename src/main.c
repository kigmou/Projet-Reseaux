#include <stdio.h>
#include "switch.h"
#include "station.h"


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
    return 0;
}
