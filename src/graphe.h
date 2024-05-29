#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "machine.h"

typedef machine sommet;

typedef struct arete
{
    sommet s1;
    sommet s2;
    unsigned int poids;
} arete;

typedef struct graphe
{
    sommet *listeMachine;
    size_t machine_capacite;
    size_t ordre;
    arete *aretes;
    size_t aretes_capacite;
    size_t nb_aretes;
} graphe;

static const size_t UNKNOWN_INDEX = -1;

void init_graphe(graphe *g);
void free_graphe(graphe *g);

size_t ordre(graphe const *g);
size_t nb_aretes(graphe const *g);

void ajouter_sommet(graphe *g, sommet m);
bool existe_arete(graphe const *g, arete a);
bool init_Arete(graphe *g, char * input);
bool ajouter_arete(graphe *g, arete a);
size_t index_arete(graphe const *g, arete a);

size_t sommets_adjacents(graphe const *g, sommet s, size_t sa[]);
size_t degre(graphe const *g, sommet s);
void afficheArrete(graphe *g);