#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct ip
{
    uint32_t addresse;
}ip;

//typedef struct ip ip;

void cpy_AddrIp(ip const *ip1, ip *ip2);

bool equals_AddrIp(ip const *ip1, ip const *ip2);

uint32_t compare_addrIp(ip const *ip1, ip const *ip2);

uint32_t get_addrIp(ip const* ip1);