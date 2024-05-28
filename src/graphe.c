#include "graphe.h"

void init_graphe(graphe *g)
{
    g->ordre = 0;
    g->aretes = malloc(sizeof(arete) * 8);
    g->aretes_capacite = 8;
    g->nb_aretes = 0;
}

void free_graphe(graphe *g)
{
    g->ordre = 0;
    free(g->aretes);
    g->aretes = NULL;
    g->aretes_capacite = 0;
    g->nb_aretes = 0;
}

size_t ordre(graphe const *g)
{
    return g->ordre;
}

size_t nb_aretes(graphe const *g)
{
    return g->nb_aretes;
}

void ajouter_sommet(graphe *g)
{
    g->ordre++;
}

static arete swap_arete(arete a)
{
    return (arete){a.s2, a.s1};
}

bool existe_arete(graphe const *g, arete a)
{
    if (a.s1 > a.s2)
        a = swap_arete(a);
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete aa = g->aretes[i];
        if (a.s1 == aa.s1 && a.s2 == aa.s2)
            return true;
    }
    return false;
}

bool ajouter_arete(graphe *g, arete a)
{
    if (a.s1 >= ordre(g) || a.s2 >= ordre(g) || a.s1 == a.s2)
        return false;
    if (a.s1 > a.s2)
        a = swap_arete(a);
    if (!existe_arete(g, a))
    {
        if (g->nb_aretes == g->aretes_capacite)
        {
            void *p = realloc(g->aretes, sizeof(arete) * g->aretes_capacite * 2);
            if (p)
            {
                g->aretes = p;
                g->aretes_capacite = g->aretes_capacite * 2;
            }
        }
        if (g->aretes_capacite > g->nb_aretes)
        {
            g->aretes[g->nb_aretes] = a;
            g->nb_aretes++;
            return true;
        }
    }
    return false;
}

size_t index_arete(graphe const *g, arete a)
{
    if (a.s1 > a.s2)
        a = swap_arete(a);
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete aa = g->aretes[i];
        if (a.s1 == aa.s1 && a.s2 == aa.s2)
            return i;
    }
    return UNKNOWN_INDEX;
}

size_t sommets_adjacents(graphe const *g, sommet s, sommet sa[])
{
    if (s >= ordre(g))
        return 0;
    size_t nb = 0;
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete a = g->aretes[i];
        if (a.s1 == s)
            sa[nb++] = a.s2;
        else if (a.s2 == s)
            sa[nb++] = a.s1;
    }
    return nb;
}
