#include "Ip_Adr.h"

void init_ipAddr(char *adresse)
{

    return;
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
    if(get_adrIp(self)<get_adrIp(self)) return -1;
    else if(equals_AdrIp(self, ip2)) return 0;
    else return 1;    
}

uint8_t* get_adrIp(ip const* self)
{
    uint8_t tab[3];
    return tab;
}