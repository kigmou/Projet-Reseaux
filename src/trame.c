#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trame.h"


void init_trame(trame *tr, mac *sourceP, mac *destinationP, char* messageP, short unsigned int typeP)
{
    tr->destination = malloc(sizeof(mac));
    tr->source = malloc(sizeof(mac));
    memcpy(tr->destination, destinationP,sizeof(mac));
    memcpy(tr->source, sourceP,sizeof(mac));
    tr->type = typeP;
    strcpy(tr->donnees, messageP); 
    tr->FCS = 12345;
    tr->bourrage[48];
    /*tr->preambule;
    tr->SFD;*/
}

void free_trame(trame *tr)
{
    free(tr->destination);
    free(tr->source);
}


mac* source(trame const *tr)
{
    return NULL;
}

mac* destination(trame const *tr)
{
    return NULL;
}

bool envoyer_trame(trame const *tr)
{
    return false;
}