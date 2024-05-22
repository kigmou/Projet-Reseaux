#pragma once

#include<stdio.h>
#include<stdint.h>

//typedef struct switch switch;

typedef struct switch{
    typeMachine type = 2;
    unsigned int nbPorts;
    long int priorite;
    tableCommutation tbCommutation;
} switch;

