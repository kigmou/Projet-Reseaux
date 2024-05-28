#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct mac {
    uint8_t adresse[6];
} mac;

mac* init_macAddr(const char *adresse);
void cpy_AdrMac(mac *self, const mac *mac2);
bool equals_AdrMac(const mac *self, const mac *mac2);
uint8_t* compare_adrMac(const mac *self, const mac *mac2);
uint8_t* get_adrMac(mac* self);
uint8_t hex_to_byte_MAC(const char *hex);
