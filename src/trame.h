#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Mac_Adr.h"
#include "trame.h"
#include "graphe.h"
#include "tableCommutation.h"
#include "switch.h"
#include "station.h"


typedef struct trame
{
    long long int preambule;
    uint8_t SFD;
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

bool envoyer_trame(trame const *tr, graphe *g);
void visite_composante_connexe_trame(graphe const *g, const size_t sUltime, size_t s1, size_t s2, bool *visite, bool trouve, bool complet, size_t oldS1);
