#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reseau.h"

void init_reseau(reseau *n){
    n->lstMachine = 0;
    n->graphe;
}
reseau *create_reseau(){
      FILE *fichier = fopen("fichierConfig.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de configuration\n");
        exit(1);
    }

    int nbrMachine, nbrLien;
    if (fscanf(fichier, "%d %d", &nbrMachine, &nbrLien) != 2) {
        printf("Erreur de lecture des données du fichier de configuration\n");
        exit(1);
    }

    machine* machine=malloc(sizeof(machine)*nbrMachine);
    
     char line[1024];
     int j=0;
    while (fgets(line, sizeof(line), fichier) != NULL) {
        if(j<nbrMachine+1)
        {
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


             }
        }
        else {
         
        }
        j++;
    }

    fclose(fichier);

   
}