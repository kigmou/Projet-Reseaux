#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct ip {
    uint8_t adresse[4];
} ip;

ip* init_IpAddr(const char *adresse);
void cpy_AdrIp(ip *self, const ip *ip2);
bool equals_Adrip(const ip *self, const ip *ip2);
uint8_t* compare_adrIp(const ip *self, const ip *ip2);
uint8_t* get_adrIp(ip* self);
uint8_t dec_to_byte_IP(const char *dec);