#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Ip_Adr.h"

ip* init_ipAddr(char *adresse)
{
    ip *AdrIp = malloc(sizeof(ip));
    if (AdrIp == NULL) {
        return NULL;
    }

    uint8_t* ip_uint = malloc(4 * sizeof(uint8_t));
    if (ip_uint == NULL) {
        free(AdrIp);
        AdrIp = NULL;
        return NULL;
    }

    char* token = strtok(adresse, ".");
    int i = 0;
    while (token != NULL) {
        AdrIp->adresse[i] = (uint8_t) atoi(token);
        i++;
        token = strtok(NULL, ".");
    }

    if (i != 4) {
        free(AdrIp);
        AdrIp = NULL;
        return NULL;
    }
    return AdrIp;
}

void cpy_AdrIp(ip *self, ip *ip2)
{
    ip2 = self;
    return;
}

bool equals_AdrIp(ip const *self, ip const *ip2)
{

    return (self==ip2);
}

int8_t compare_adrIp(ip const *self, ip const *ip2)
{
    if(get_adrIp(self)<get_adrIp(ip2)) return -1;
    else if(equals_AdrIp(self, ip2)) return 0;
    else return 1;    
}

uint8_t* get_adrIp(ip const* self)
{
    uint8_t tab[4];
    return tab;
}