#pragma once
#ifndef SWITCH_H
#define SWITCH_H

#include<stdio.h>
#include<stdint.h>

typedef enum {
    STATION = 1,
    SWITCH = 2
} typeMachine;


typedef struct {
    typeMachine type;
    unsigned int nbPorts;
    long int priorite;
    //tableCommutation tbCommutation;
} switch;

switch* createSwitch(typeMachine type, unsigned int nbPorts, long int priorite);
void afficheSwitch(switch* sw);
void freeSwitch(switch* sw);

#endif // SWITCH_H