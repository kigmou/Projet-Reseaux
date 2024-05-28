#include "Ip_Adr.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ip* init_IpAddr(const char *adresse) {
    if (adresse == NULL) {
        return NULL; 
    }

    ip *new_ip = (ip*)malloc(sizeof(ip));
    if (new_ip == NULL) {
        return NULL;
    }

    char input_copy[16]; 
    strncpy(input_copy, adresse, sizeof(input_copy));
    input_copy[sizeof(input_copy) - 1] = '\0';

    char *token = strtok(input_copy, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        new_ip->adresse[i] = (uint8_t)atoi(token);
        token = strtok(NULL, ".");
    }

    if (token != NULL) {
        free(new_ip);
        return NULL; 
    }

    return new_ip;
}

void cpy_AdrIp(ip *self, const ip *ip2) {
    if (self != NULL && ip2 != NULL) {
        memcpy(self->adresse, ip2->adresse, 6 * sizeof(uint8_t));
    }
}

bool equals_AdrIp(const ip *self, const ip *ip2) {
    if (self == NULL || ip2 == NULL) {
        return false;
    }
    return memcmp(self->adresse, ip2->adresse, 6 * sizeof(uint8_t)) == 0;
}

uint8_t* compare_adrIp(const ip *self, const ip *ip2) {
    // Implémentation si nécessaire
    return NULL;
}

uint8_t* get_adrIp(ip* self) {
    return (self != NULL) ? self->adresse : NULL;
}

uint8_t dec_to_byte_IP(const char *dec) {
    uint8_t byte;
    sscanf(dec, "%d", &byte);
    return byte;
}
