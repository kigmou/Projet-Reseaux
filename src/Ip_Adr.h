#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct ip
{
    uint8_t adresse[4];
}ip;

//typedef struct ip ip;

void cpy_AdrIp(ip const *ip1, ip *ip2);

bool equals_AdrIp(ip const *ip1, ip const *ip2);

uint8_t* compare_adrIp(ip const *ip1, ip const *ip2);

uint8_t* get_adrIp(ip const* ip1);