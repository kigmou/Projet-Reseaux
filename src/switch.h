#pragma once

#include<stdio.h>
#include<stdint.h>
#include "machine.h"

//typedef struct switch switch;

typedef struct switch {
    MachineType type = SWITCH;
    unsigned int nbPorts;
    long int priorite;
    //tableCommutation tbCommutation;
    
} switch;

switch* createSwitch(typeMachine type, unsigned int nbPorts, long int priorite)

