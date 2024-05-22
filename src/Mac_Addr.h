#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct mac
{
    uint8_t addresse[6];
} mac;

//typedef struct mac mac;

void cpy_AddrMac(mac const *mac1, mac *mac2);

bool equals_AddrMac(mac const *mac1, mac const *mac2);

uint8_t* compare_addrMac(mac const *mac1, mac const *mac2);

uint8_t* get_addrMac(mac const* mac);
