#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef size_t sommet;

typedef struct arete
{
} arete;

typedef struct graphe
{
} graphe;

static const size_t UNKNOWN_INDEX = -1;

void init_graphe(graphe *g);
void free_graphe(graphe *g);

size_t ordre(graphe const *g);
size_t nb_aretes(graphe const *g);

void ajouter_sommet(graphe *g);
bool existe_arete(graphe const *g, arete a);
bool ajouter_arete(graphe *g, arete a);
size_t index_arete(graphe const *g, arete a);

size_t sommets_adjacents(graphe const *g, sommet s, sommet sa[]);
