#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Mac_Adr.h"
#include "machine.h"
#include "Ip_Adr.h"
#include "graphe.h"
#include <string.h>





typedef struct reseau{
machine * lstMachine;
graphe graphe;
} reseau;

void init_reseau(reseau *reseau);
reseau* create_reseau();


