#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reseau.h"

void init_reseau(reseau *n){
    n->lstMachine = 0;
    n->graphe;
}
reseau *create_reseau(){
    reseau n;
    init_reseau(&n);
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
    
    char type=NULL;
    fscanf(fichier, "%c",&type);
     int j=0;
     int temp=NULL;
    while (j<nbrMachine) {
        switch (type)
        {
            case '1':
               
                machine[j].type = STATION;
                station *new_station = malloc(sizeof(station));
                machine[j].ptr = &new_station;
                station *station_ptr = *(station**) machine[j].ptr;

                /////////////ADRESSEMAC//////////////
                char * adrMac = malloc(sizeof(mac));
                 fscanf(fichier,";%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx;", &adrMac[0], &adrMac[1], &adrMac[2], &adrMac[3], &adrMac[4], &adrMac[5], &adrMac[6]); // pass pointers to char values
                strcpy(station_ptr->addrMac, adrMac);
                free(adrMac); 
                /////////////ADRESSEMAC//////////////

                ///////////// ADRESSEIP//////////////
                char * adrIp= malloc(sizeof(ip));
                temp =fscanf(fichier, "%hhu.%hhu.%hhu.%hhu", &adrIp[0], &adrIp[1], &adrIp[2], &adrIp[3]);
                if(temp==NULL) return NULL;
                strcpy(station_ptr->addrIp,adrIp);
                free(adrIp);
                ///////////// ADRESSEIP//////////////
                
                break;
            case '2':
                machine[j].type = SWITCH;
                Switch *new_switch = malloc(sizeof(Switch));
                machine[j].ptr = &new_switch;
                Switch *switch_ptr = *(Switch**)machine[j].ptr;

                /////////////ADRESSEMAC//////////////
                char * mac1 = malloc(sizeof(mac));
                temp =fscanf(fichier,";%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx:%hhx%hhx;", &mac1[0], &mac1[1], &mac1[2], &mac1[3], &mac1[4], &mac1[5], &mac1[6]); // pass pointers to char values
                if(temp==NULL) return NULL;
                strcpy(switch_ptr->addrMac, mac1);
                free(mac1);
                /////////////ADRESSEMAC//////////////


                //////////////PORT///////////////
                unsigned int port =malloc(sizeof(unsigned int));
                temp = fscanf(fichier,"%u;",&port);
                if(temp==NULL) return NULL;
                strcpy(switch_ptr->priorite, port);
                free(port);
                //////////////PORT///////////////
                
                //////////////PRIORITE//////////
                long int prio=malloc(sizeof(long int));
                temp=fscanf(fichier,"%li",&prio);
                strcpy(switch_ptr->priorite,prio);
                free(prio);
                //////////////PRIORITE//////////


                break;
            default:
                printf("Type de machine inconnu : %c\n", type);
                exit(1);

        }

        
        j++;
    }

    fclose(fichier);

   
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