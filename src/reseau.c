#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reseau.h"

void init_reseau(reseau *n){
    n->lstMachine = 0;
    //n->graphe;
}
reseau *create_reseau(){


      FILE *fichier = fopen("fichierConfig.txt", "r"); //Ouvrir le fichier
      
    //test de l'ouverture du fichier
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier de configuration\n");
        exit(1);
    }

    //Lecture de la première ligne du fichier de configuration et collecte des données
    int nbrMachine, nbrLien;
    if (fscanf(fichier, "%d %d", &nbrMachine, &nbrLien) != 2) {
        printf("Erreur de lecture des données du fichier de configuration\n");
        exit(1);
    }


    /////////CREATION LISTE DE MACHINE ///////////////////
    machine* machine=malloc(sizeof(machine)*nbrMachine);
    if(machine == NULL) return NULL;

    /////////CREATION LISTE DE MACHINE ///////////////////

    
    char type='0';
    char line[32];
    int m = fscanf(fichier, "%c",&type);
    if(m==0) return NULL;
    for(int i=0;i<nbrMachine;i++){  
       char * f= fgets(line,32,fichier); 
       if(f == NULL) return NULL;
        switch (line[0])
        {
            case '1':
               //////////CREATION STATION//////////////
                machine[i].type = STATION;
                station *new_station = malloc(sizeof(station));
                machine[i].ptr = &new_station;
                //station *station_ptr = *(station**) machine[j].ptr;
                init_Station(new_station,line);
               //////////CREATION STATION///////////
            
                
                break;
            case '2':
                machine[i].type = SWITCH;
                Switch *new_switch = malloc(sizeof(Switch));
                machine[i].ptr = &new_switch;
               // Switch *switch_ptr = *(Switch**)machine[j].ptr;
                
                init_switch(new_switch,line);
                break;
            default:
                printf("Type de machine inconnu : %c\n", type);
        }
    }

    graphe *g=malloc(sizeof(graphe));
    if(g==NULL) return NULL;
        
    init_graphe(g);
        
    sommet * lstSommet= malloc(nbrMachine*sizeof(sommet));
    if(lstSommet==NULL) return NULL;
        
    arete * lstArete= malloc(nbrLien*sizeof(arete));
    if(lstArete==NULL) return NULL;
        
    for(int i=0;i<nbrMachine;i++) ajouter_sommet(g);

    int indexSommet1;
    int indexSommet2;
    int poids;


    for(int i=0;i<nbrLien;i++)
    {
        int f = fscanf(fichier,"%d;%d;%d",&indexSommet1,&indexSommet2,&poids);
       if (f == EOF ) return NULL;
       
       if (indexSommet1 < 0 || indexSommet1 >= nbrMachine ||
        indexSommet2 < 0 || indexSommet2 >= nbrMachine) {
        // Gérer l'erreur ici
        return NULL;
    }
        arete a= lstArete[i];
        sommet som1 = lstSommet[indexSommet1];
        sommet som2 = lstSommet[indexSommet2];

        a.s1=som1;
        a.s2=som2;
        a.poids=poids;
        ajouter_arete(g,a);
    }
    

    fclose(fichier);
    reseau *n =malloc(sizeof(reseau));
    if(n==NULL) return NULL;
    
    n->lstMachine=machine;
    n->graphe=*g;

    ////////////////FREE/////////////////////:::
   // Libérer la mémoire allouée pour les tableaux
    free(lstArete);
    free(lstSommet);

    // Libérer la mémoire allouée pour le graphe
    free_graphe(g);

    // Libérer la mémoire allouée pour le tableau de machines
    free(machine);
    ////////////////FREE/////////////////////:::

    return n;
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