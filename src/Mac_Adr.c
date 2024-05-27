#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mac_Adr.h"

mac* init_macAddr(char *adresse)
{
    mac *AdrMac = malloc(sizeof(mac));
    if (AdrMac == NULL) {
        return NULL;
    }
    printf(adresse);

    char* configCopy = strdup(adresse); 
    if (configCopy == NULL) {
        free(AdrMac);
        return NULL;
    }
    char* token = strtok(configCopy, ":");

    int i = 0;
    while (token != NULL) {
        AdrMac->adresse[i] = (uint8_t) atoi(token);
        i++;
        token = strtok(NULL, ":");
    }
    if (i != 6) {
        free(AdrMac);
        AdrMac = NULL;
        return NULL;
    }
    return AdrMac;
}

void cpy_AdrMac(mac *self, mac *mac2)
{
    mac2 = self;
    return;
}

bool equals_AdrMac(mac const *self, mac const *mac2)
{

    return (self==mac2);
}

uint8_t* compare_adrMac(mac const *self, mac const *mac2)
{
    if(get_adrMac(self)<get_adrMac(mac2)) return -1;
    else if(equals_AdrMac(self, mac2)) return 0;
    else return 1;    
}

uint8_t* get_adrMac(mac const* self)
{
    uint8_t tab[4];
    return tab;
}