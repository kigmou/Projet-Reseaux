#pragma once

#include "Mac_Adr.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct tableCommutation {
    mac **addrMac;
    unsigned int numPort; ////////////A CHANGER PARTOUT
    unsigned int *ttl;
    size_t relations_capacite;
    size_t nb_relation;
    //tableCommutation tbCommutation;
} tableCommutation;

int init_tblCommut(tableCommutation *tblC);
void afficheTblCommut(tableCommutation* tblC);
void freeTblCommut(tableCommutation* tblC);
bool ajouter_relation(tableCommutation *tblc, mac *addr, unsigned int TTL);
bool existe_relation(tableCommutation *tblc, mac *addr, unsigned int TTL);