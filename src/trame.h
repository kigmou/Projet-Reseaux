#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Mac_Adr.h"
#include "trame.h"


typedef struct trame
{
    uint8_t preambule;
    char SFD;
    mac *destination;
    mac *source;
    short unsigned int type;
    char donnees[1500]; 
    char bourrage[46];
    unsigned int FCS;
} trame;

void init_trame(trame *tr, mac *sourceP, mac *destinationP, char* messageP, short unsigned int typeP);
void free_trame(trame *tr);

mac* source(trame const *tr);
mac* destination(trame const *tr);

bool envoyer_trame(trame const *tr);
