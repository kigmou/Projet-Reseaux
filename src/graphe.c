#include "graphe.h"

void init_graphe(graphe *g)
{
    g->listeMachine = malloc(sizeof(machine) * 10);
    g->machine_capacite = 10;
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

void ajouter_sommet(graphe *g, sommet m)
{
    if (g->ordre == g->machine_capacite)
    {
        void *p = realloc(g->listeMachine, sizeof(machine) * g->machine_capacite * 2);
        if (p)
        {
            g->listeMachine = p;
            g->machine_capacite = g->machine_capacite * 2;
        }
    }
    if (g->machine_capacite > g->ordre)
    {
        g->listeMachine[g->ordre] = m;
        g->ordre++;
    }
    return;
}

static arete swap_arete(arete a)
{
    return (arete){a.s2, a.s1, a.poids};
}

bool existe_arete(graphe const *g, arete a)
{
    if (a.s1.numMachine > a.s2.numMachine)
        a = swap_arete(a);
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete aa = g->aretes[i];
        if (a.s1.numMachine == aa.s1.numMachine && a.s2.numMachine == aa.s2.numMachine)
            return true;
    }
    return false;
}
bool init_Arete(graphe *g, char * input)
{

    if (input == NULL) {
        return -1; 
    }

    char input_copy[100];
    strncpy(input_copy, input, sizeof(input_copy));
    input_copy[sizeof(input_copy) - 1] = '\0';

    char *token = strtok(input_copy, ";");
    if (token == NULL) return false;
    size_t IndexNumDepart = (size_t)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return false;
    size_t IndexNumArrive = (size_t)atoi(token);

    token = strtok(NULL, ";");
    if (token == NULL) return false;
    unsigned int poid = (unsigned int)atoi(token);

    arete *a = malloc(sizeof(arete));
    a->s1 = g->listeMachine[IndexNumDepart];
    a->s2 = g->listeMachine[IndexNumArrive];
    a->poids = poid;

    return ajouter_arete(g, *a);
}

bool ajouter_arete(graphe *g, arete a)
{
    printf("On est la________ ordre = %lu \n",ordre(g));
    printf("a.s1.numMachine = %lu\n",a.s1.numMachine);
    printf("a.s2.numMachine = %lu\n",a.s2.numMachine);
    if (a.s1.numMachine >= ordre(g) || a.s2.numMachine >= ordre(g) || a.s1.numMachine == a.s2.numMachine)
        return false;
    printf("On est la________V2");

    if (a.s1.numMachine > a.s2.numMachine)
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
    if (a.s1.numMachine > a.s2.numMachine)
        a = swap_arete(a);
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete aa = g->aretes[i];
        if (a.s1.numMachine == aa.s1.numMachine && a.s2.numMachine == aa.s2.numMachine)
            return i;
    }
    return UNKNOWN_INDEX;
}

size_t sommets_adjacents(graphe const *g, sommet s, size_t sa[])
{
    if (s.numMachine >= ordre(g))
        return 0;
    size_t nb = 0;
    for (size_t i = 0; i < nb_aretes(g); i++)
    {
        arete a = g->aretes[i];
        if (a.s1.numMachine == s.numMachine)
            sa[nb++] = a.s2.numMachine;
        else if (a.s2.numMachine == s.numMachine)
            sa[nb++] = a.s1.numMachine;
    }
    return nb;
}

size_t degre(graphe const *g, sommet s)
{
    //meme fonction que sommet adjacents sauf sans sa[]
    size_t compteur = 0;
    for(size_t i = 0; i< g->nb_aretes; i++)
    {
        if (g->aretes[i].s1.numMachine==s.numMachine)
        {
            compteur++;
        }
        else if (g->aretes[i].s2.numMachine==s.numMachine)
        {
            compteur++;
        }
    }
    return compteur;
}

void afficheArrete(graphe *g)
{
    for(size_t i=0; i<g->nb_aretes; i++)
    {
        printf("Arete : %lu %lu %u \n", g->aretes[i].s1.numMachine, g->aretes[i].s2.numMachine, g->aretes[i].poids);
    }
    printf("nombre d'aretes : %lu \n",g->nb_aretes);
}

