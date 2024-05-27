#pragma once

#include "Mac_Adr.h"
#include "machine.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Switch {
    enum MachineType type;
    mac *addrMac;
    unsigned int nbPorts;
    long int priorite;
    //tableCommutation tbCommutation;
}Switch;

Switch* init_switch(char *config);
void afficheSwitch(Switch* sw);
void freeSwitch(Switch* sw);
