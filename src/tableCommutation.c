#include "tableCommutation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int init_tblCommut(tableCommutation *tblC)
{
//    g->aretes = malloc(sizeof(arete) * 8);
    tblC->addrMac = malloc(sizeof(mac) * 5);
    tblC->numPort = 0;
    tblC->numMachineLie = malloc(sizeof(unsigned int) * 5);
    tblC->ttl = malloc(sizeof(unsigned int) * 5);
    tblC->nb_relation = 0;
    tblC->relations_capacite = 5;
    return 0;
}
void afficheTblCommut(tableCommutation* tblC)
{
    printf("    Addresse mac   | numPort | Ttl | numPortRelié \n");
    for(size_t i=0; i< tblC->nb_relation; i++)
    {
        printf(" %02x:%02x:%02x:%02x:%02x:%02x |    %lu    | %u | %u \n",tblC->addrMac[i]->adresse[0], tblC->addrMac[i]->adresse[1], tblC->addrMac[i]->adresse[2], tblC->addrMac[i]->adresse[3], tblC->addrMac[i]->adresse[4], tblC->addrMac[i]->adresse[5], i, tblC->ttl[i], tblC->numMachineLie[i]);
    }
}
void freeTblCommut(tableCommutation* tblC)
{
    free(tblC->addrMac);
    free(tblC->ttl);
}
/*bool ajouter_relationConfig(tableCommutation *tblc, const char *input, mac *addr)
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
}*/
bool ajouter_relation(tableCommutation *tblc, mac *addr, size_t nmMach, unsigned int TTL)
{
    if (!existe_relation(tblc, addr, TTL))
    {
        if (tblc->nb_relation == tblc->relations_capacite)
        {
            void *a = realloc(tblc->addrMac, sizeof(mac) * tblc->relations_capacite * 2);
            void *n = realloc(tblc->numMachineLie, sizeof(unsigned int) * tblc->relations_capacite * 2);
            void *t = realloc(tblc->ttl, sizeof(unsigned int) * tblc->relations_capacite * 2);
            if (a && t && n)
            {
                free(tblc->addrMac);
                free(tblc->ttl);
                free(tblc->numMachineLie);
                tblc->addrMac = a;
                tblc->ttl = t;
                tblc->numMachineLie = n;
                tblc->relations_capacite = tblc->relations_capacite * 2;
            }
            else
            {
                free(a);
                free(t);
            }
        }
        if (tblc->nb_relation < tblc->relations_capacite)
        {
            tblc->addrMac[tblc->nb_relation] = addr;
            tblc->numMachineLie[tblc->nb_relation] = nmMach;
            tblc->numPort++;
            tblc->ttl[tblc->nb_relation] = TTL;
            tblc->nb_relation++;
            return true;
        }
    }
    return false;
} 
bool existe_relation(tableCommutation *tblc, mac *addr, unsigned int TTL)
{
    for (size_t i = 0; i < tblc->nb_relation; i++)
    {   
        if (tblc->addrMac[i] == addr && tblc->ttl[i] == TTL)
            return true;
    }
    return false;
}


