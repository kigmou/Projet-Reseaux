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
    freeSwitch(&sw);
    char *input2 = "1;54:d6:a6:82:c5:23;130.79.80.21";
    station st;

    if (init_Station(&st, input2) == 0) {
        printf("Station initialisé ! \n");
    } else {
        printf("La station n'a pas pu être initialisé.\n");
    }

    afficheStation(&st);
    freeStation(&st);
    return 0;
}
