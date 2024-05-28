#include "Mac_Adr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

mac* init_macAddr(const char *adresse) {
    mac *new_mac = (mac*)malloc(sizeof(mac));
    if (new_mac == NULL) {
        return NULL; 
    }

    for (int i = 0; i < 6; i++) {
        new_mac->adresse[i] = hex_to_byte_MAC(adresse + 3 * i);
    }

    return new_mac;
}

void cpy_AdrMac(mac *self, const mac *mac2) {
    if (self != NULL && mac2 != NULL) {
        memcpy(self->adresse, mac2->adresse, 6 * sizeof(uint8_t));
    }
}

bool equals_AdrMac(const mac *self, const mac *mac2) {
    if (self == NULL || mac2 == NULL) {
        return false;
    }
    return memcmp(self->adresse, mac2->adresse, 6 * sizeof(uint8_t)) == 0;
}

uint8_t* compare_adrMac(const mac *self, const mac *mac2) {
    // Implémentation si nécessaire
    return NULL;
}

uint8_t* get_adrMac(mac* self) {
    return (self != NULL) ? self->adresse : NULL;
}

uint8_t hex_to_byte_MAC(const char *hex) {
    uint8_t byte;
    sscanf(hex, "%2hhx", &byte);
    return byte;
}