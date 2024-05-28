#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Mac_Adr.h"
#include "machine.h"
#include "Ip_Adr.h"
#include "graphe.h"
#include "station.h"
#include "switch.h"
#include "trame.h"
#include <string.h>





typedef struct reseau{
machine * lstMachine;
graphe *graphe;
int nbMachine;
} reseau;

void init_reseau(reseau *reseau);
reseau* create_reseau();
void afficherReseau(reseau *n);

