#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct mac
{
    uint8_t adresse[6];
} mac;

//typedef struct mac mac;
mac* init_macAddr(char *adresse);

void cpy_AdrMac(mac *self, mac *mac2);

bool equals_AdrMac(mac const *self, mac const *mac2);

uint8_t* compare_adrMac(mac const *self, mac const *mac2);

uint8_t* get_adrMac(mac const* self);
