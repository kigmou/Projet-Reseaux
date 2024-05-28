#include "tableCommutation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int init_tblCommut(tableCommutation *tblC)
{
//    g->aretes = malloc(sizeof(arete) * 8);
    tblC->addrMac = malloc(sizeof(mac) * 5);
    tblC->numPort = malloc(sizeof(unsigned int) * 5);
    tblC->ttl = malloc(sizeof(unsigned int) * 5);
    tblC->nb_relation = 0;
    tblC->relations_capacite = 5;
    return 0;
}
void afficheTblCommut(tableCommutation* tblC)
{
    printf("    Addresse mac   | numPort | Ttl \n");
    for(int i=0; i< tblC->nb_relation; i++)
    {
        printf(" %02x:%02x:%02x:%02x:%02x:%02x |    %u    |  %u \n",tblC->addrMac[i]->adresse[0], tblC->addrMac[i]->adresse[1], tblC->addrMac[i]->adresse[2], tblC->addrMac[i]->adresse[3], tblC->addrMac[i]->adresse[4], tblC->addrMac[i]->adresse[5], tblC->numPort[i], tblC->ttl[i]);
    }
}
void freeTblCommut(tableCommutation* tblC)
{
    free(tblC->addrMac);
    free(tblC->numPort);
    free(tblC->ttl);
}
bool ajouter_relationConfig(tableCommutation *tblc, const char *input, mac *addr)
{
    if (tblc == NULL || input == NULL) {
        return -1; 
    }

    char input_copy[100];
    strncpy(input_copy, input, sizeof(input_copy));
    input_copy[sizeof(input_copy) - 1] = '\0';

    char *token = strtok(input_copy, ";");
    if (token == NULL) return false;
    //int TypeInutile = (int)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return false;
    unsigned int numeroPort = (unsigned int)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return false;
    unsigned int TimeToLive = (unsigned int)atoi(token);
    return ajouter_relation(tblc, addr, numeroPort, TimeToLive);
}
bool ajouter_relation(tableCommutation *tblc, mac *addr, unsigned int numP, unsigned int TTL)
{
    if (!existe_relation(tblc, addr, numP, TTL))
    {
        if (tblc->nb_relation == tblc->relations_capacite)
        {
            void *a = realloc(tblc->addrMac, sizeof(mac) * tblc->relations_capacite * 2);
            void *n = realloc(tblc->numPort, sizeof(unsigned int) * tblc->relations_capacite * 2);
            void *t = realloc(tblc->ttl, sizeof(unsigned int) * tblc->relations_capacite * 2);
            free(tblc->addrMac);
            free(tblc->numPort);
            free(tblc->ttl);
            if (a && n && t)
            {
                tblc->addrMac = a;
                tblc->numPort = n;
                tblc->ttl = t;
                tblc->relations_capacite = tblc->relations_capacite * 2;
            }
            else
            {
                free(a);
                free(n);
                free(t);
            }
        }
        if (tblc->nb_relation < tblc->relations_capacite)
        {
            tblc->addrMac[tblc->nb_relation] = addr;
            tblc->numPort[tblc->nb_relation] = numP;
            tblc->ttl[tblc->nb_relation] = TTL;
            tblc->nb_relation++;
            return true;
        }
    }
    return false;
} 
bool existe_relation(tableCommutation *tblc, mac *addr, unsigned int numP, unsigned int TTL)
{
    for (size_t i = 0; i < tblc->nb_relation; i++)
    {   
        if (tblc->numPort[i] == numP && tblc->addrMac[i] == addr && tblc->ttl[i] == TTL)
            return true;
    }
    return false;
}


