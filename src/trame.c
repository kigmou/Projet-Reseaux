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
    tr->preambule = 0b10101010101010101010101010101010101010101010101010101010;
    tr->SFD=0b10101011;
}

void free_trame(trame *tr)
{
    free(tr->destination);
    free(tr->source);
}


mac* source(trame const *tr)
{
    return tr->source;
}

mac* destination(trame const *tr)
{
    return tr->destination;
}

bool envoyer_trame(trame const *tr, graphe *g)
{
    bool visite[g->ordre];
    for(int j=0; j<g->ordre; j++)
    {
        visite[j]=false;
    }
    bool trouve=false;
    size_t indexDep = -1;
    size_t indexArr = -1;
    for(int i=0; i<g->ordre; i++)
    {
        if(equals(g->listeMachine[i],tr->source))
        {
            indexDep=i;
        }
        if(equals(g->listeMachine[i],tr->destination))
        {
            indexArr = i;
        }
        if(indexArr!=indexDep!=-1)
        {
            break;
        }
    }
    visite_composante_connexe(g, indexDepUltime, indexDep, indexArr, visite, trouve);
    return false;
}

void visite_composante_connexe(graphe const *g, const size_t sUltime, size_t s1, size_t s2, bool *visite, bool trouve)
{
    sommet sa[25];
    if(!visite[s1] || !trouve)
    {
        visite[s1]=true;
        if(s1==s2)
        {
            trouve=true;
        }
        else if(g->listeMachine[s1])
            sommets_adjacents(g, s, sa);
            for(int i = 0; i<degre(g,s); i++)
            {
                visite_composante_connexe(g, sa[i], visite);
            }
    }
    return;
}