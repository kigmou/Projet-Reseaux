#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reseau.h"

void init_reseau(reseau *n){
    n->lstMachine = 0;
    //n->graphe;
}
reseau *create_reseau() {
    FILE *fichier = fopen("fichierConfig.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de configuration\n");
        exit(1);
    }

    int nbrMachine, nbrLien;
    if (fscanf(fichier, "%d %d", &nbrMachine, &nbrLien) != 2) {
        printf("Erreur de lecture des données du fichier de configuration\n");
        fclose(fichier);
        exit(1);
    }
    machine *machines = malloc(sizeof(machine) * nbrMachine);
    if (machines == NULL) {
        fclose(fichier);
        return NULL;
    }
    fgetc(fichier);

    char line[32];
    for (int i = 0; i < nbrMachine; i++) {
        if (fgets(line, sizeof(char)*100, fichier) == NULL) {
            free(machines);
            fclose(fichier);
            return NULL;
        }
        switch (line[0]) {
            case '1': {
                machines[i].type = STATION;
                station *new_station = malloc(sizeof(station));
                if (new_station == NULL) {
                    free(machines);
                    fclose(fichier);
                    return NULL;
                }
                machines[i].numMachine = i;
                machines[i].ptr = new_station;
                init_Station(new_station, line);
                break;
            }
            case '2': {
                machines[i].type = SWITCH;
                Switch *new_switch = malloc(sizeof(Switch));
                if (new_switch == NULL) {
                    free(machines);
                    fclose(fichier);
                    return NULL;
                }
                machines[i].numMachine = i;
                machines[i].ptr = new_switch;
                init_switch(new_switch, line);
                break;
            }
            default: {
                printf("Type de machine inconnu : %c %c %c %c %c %c \n", line[0],line[1],line[2],line[3],line[4],line[5]);
                free(machines);
                fclose(fichier);
                return NULL;
                }
        }
    }

    graphe *g = malloc(sizeof(graphe));
    if (g == NULL) {
        free(machines);
        fclose(fichier);
        return NULL;
    }
    init_graphe(g);

    for (int i = 0; i < nbrMachine; i++) {
        ajouter_sommet(g, machines[i]);
    }

    for (int i = 0; i < nbrLien; i++) {
        if (fgets(line, sizeof(line), fichier) == NULL) {
            free(machines);
            free_graphe(g);
            fclose(fichier);
            return NULL;
        }
        init_Arete(g, line);
        int indexSommet1, indexSommet2, poids;
        printf(line);
        if (sscanf(line, "%d;%d;%d", &indexSommet1, &indexSommet2, &poids) != 3) {
            free(machines);
            free_graphe(g);
            fclose(fichier);
            return NULL;
        }
        if (indexSommet1 < 0 || indexSommet1 >= nbrMachine || indexSommet2 < 0 || indexSommet2 >= nbrMachine) {
            free(machines);
            free_graphe(g);
            fclose(fichier);
            return NULL;
        }

        arete a;
        a.s1 = machines[indexSommet1];
        a.s2 = machines[indexSommet2];
        a.poids = poids;
        ajouter_arete(g, a);
    }

    fclose(fichier);

    reseau *n = malloc(sizeof(reseau));
    if (n == NULL) {
        free(machines);
        free_graphe(g);
        return NULL;
    }

    n->lstMachine = machines;
    n->graphe = g;
    n->nbMachine = nbrMachine;


    return n;
}

void afficherReseau(reseau *n) {
    for (int i = 0; i < n->nbMachine; i++) {
        if (n->lstMachine[i].type == STATION) {
            station *stat = (station *)n->lstMachine[i].ptr;
            afficheStation(stat);
        } else {
            Switch *sw = (Switch *)n->lstMachine[i].ptr;
            afficheSwitch(sw);
        }
    }
    afficheArrete(n->graphe);
}
/*

 if (line[0] == '1') {
                machine[j].type = STATION;
                char *adresseMac = strtok(line, ";"); 
                adresseMac = strtok(NULL, ";");
                printf("Adresse MAC : %s\n", adresseMac);

                char *adresseIp = strtok(NULL, ";");
                printf("Adresse IP : %s\n", adresseIp);
                j++;
            } else if (line[0] == '2') {
                machine[j].type = SWITCH;
                char *adresseMac = strtok(line, ";"); 
                adresseMac = strtok(NULL, ";");
                printf("Adresse MAC : %s\n", adresseMac);
                char *nbrPorts = strtok(NULL, ";");
                int nbrPortsInt = atoi(nbrPorts); 
                printf("Nombre de ports Ethernet : %d\n", nbrPortsInt);
                char *prioriteChar = strtok(NULL, ";"); 
                int priorite = atoi(prioriteChar);
                printf("priorite : %d octets\n", priorite);
             }*/