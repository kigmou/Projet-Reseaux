#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trame.h"


void init_trame(trame *tr, mac *sourceP, mac *destinationP, char* messageP, short unsigned int typeP)
{
    tr->destination = malloc(sizeof(mac));
    //memcpy(tr->destination, destinationP,sizeof(mac));
    tr->destination = destinationP;
    tr->source = malloc(sizeof(mac));
    tr->source = sourceP;
    //memcpy(tr->source, sourceP,sizeof(mac));
    tr->type = typeP;
    strcpy(tr->donnees, messageP); 
    tr->FCS = 12345;
    //tr->bourrage[48]=0;
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
    for(size_t j=0; j<g->ordre; j++)
    {
        visite[j]=false;
    }
    bool trouve=false;
    bool complet=false;
    int indexDep = -1;
    int indexArr = -1;
    int indexDepUltime = 0;
    for (size_t i = 0; i < g->ordre; i++)
    {
        if (g->listeMachine[i].type == STATION)
        {
            station *temp = (station *)g->listeMachine[i].ptr;
            if (equals_AdrMac(temp->addrMac, tr->source))
            {
                indexDep = i;
            }
            else if(equals_AdrMac(temp->addrMac, tr->destination))
            {
                indexArr = i;
            }
        }
        else
        {
            Switch *temp = (Switch *)g->listeMachine[i].ptr;
            if (equals_AdrMac(temp->addrMac, tr->source))
            {
                indexDep = i;
            }
            else if (equals_AdrMac(temp->addrMac, tr->destination))
            {
                indexArr = i;
            }
        }
        if (indexArr != -1 && indexDep != -1)
        {
            break;
        }
    }
    indexDepUltime=indexDep;
    visite_composante_connexe_trame(g, indexDepUltime, indexDep, indexArr, visite, trouve, complet, indexDep);
    return false;
}

void visite_composante_connexe_trame(graphe const *g, const size_t sUltime, size_t s1, size_t s2, bool *visite, bool trouve, bool complet, size_t oldS1)
{   
    size_t sa[25];

    /*if(!visite[s1] && !trouve)
    {  
        for(int i=0; i<10; i++)
        {

        }
    }*/
    
    if(!visite[s1] && !trouve)
    {
        visite[s1] = true;
        if (s1 == s2)
        {
            trouve = true;
        }
        if (g->listeMachine[sUltime].type == STATION)
        {
            station *structUltime = (station *)g->listeMachine[sUltime].ptr;
            if (g->listeMachine[s1].type == SWITCH)
            {
                Switch *swTemp = (Switch *)g->listeMachine[s1].ptr;
                // ajouter dans la table de commutation
                ajouter_relation(swTemp->tblCommutation, structUltime->addrMac, oldS1, 100);
            }
        }
        else if(g->listeMachine[sUltime].type == SWITCH)
        {
            Switch *structUltime = (Switch *)g->listeMachine[sUltime].ptr;
            if (g->listeMachine[s1].type == SWITCH)
            {
                Switch *swTemp = (Switch *)g->listeMachine[s1].ptr;
                // ajouter dans la table de commutation
                ajouter_relation(swTemp->tblCommutation, structUltime->addrMac, oldS1, 100);
            }
        }
        sommets_adjacents(g, g->listeMachine[s1], sa);
        for(size_t i = 0; i<degre(g, g->listeMachine[s1]); i++)
        {
            visite_composante_connexe_trame(g, sUltime, sa[i] ,s2, visite, trouve, complet, s1);
        }
    }
    return;
}