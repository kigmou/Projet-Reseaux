#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct ip
{
    uint8_t adresse[4];
}ip;

//typedef struct ip ip;
ip* init_ipAddr(char *adresse);

void cpy_AdrIp(ip *self, ip *ip2);

bool equals_AdrIp(ip const *self, ip const *ip2);

int8_t compare_adrIp(ip const *self, ip const *ip2);

uint8_t* get_adrIp(ip const* self);