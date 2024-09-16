//
// Created by Max on 14/09/2024.
//

#include "menu.h"
#include "stdio.h"
#include "horlogeMax.h"

// commandes : help/aide, ajouter, calculer, afficher
//menu : majHorloge, afficherHeureDate, demander pays, (ecouter commandes)->faire fonction a part

void cmdAjouter(LLC* liste){
    ajouterQueueLLC(liste, creerMaillonAvecInput());
    printf("Ajout effectue avec succes.\n");
    return;
}

void cmdCalculer(LLC* liste, char* paysLocal, char* paysAutre){
    afficherHeurePaysBoutEnBout(liste, paysLocal, paysAutre);
    return;
}

void cmdAfficher(LLC* liste){
    afficherLLC(liste);
    return;
}

void cmdHelp(){
    printf("Bienvenue dans le menu d'aide, Voici les commandes que vous pouvez utiliser dans ce logiciel :\n");
    printf("   'quit' : ferme le logiciel\n");
    printf("   'afficher' : affiche toutes les informations des pays recenses\n");
    printf("   'ajouter' : ajoute un pays a la liste\n");
    printf("   'calculer' : calcule l'heure actuelle dans le pays de votre choix\n");
    printf("   'info' : affiche les informations du logiciel\n");
    printf("   'help' : affiche ce menu d'aide\n\n");
}

void menu(LLC* liste){
    afficherEntete();
    afficherInfosHorloge(majHorloge(1));
    char* paysLocal = demanderPays(liste,1);
    printf("Si vous avez besoin d'aide entrez la commande 'help'\n");
    char cmd[50];
    int quitter = 0;
    while(quitter != 1){
        printf("Entrez votre commande :");
        fflush(stdin);
        gets(cmd);
        while(commandeExiste(cmd) != 1){
            printf("Cette commande n'est pas reconnue. ");
            printf("Entrez votre commande :");
            fflush(stdin);
            gets(cmd);
        }
        if(!strcmp(cmd,"help") || !strcmp(cmd,"h") || !strcmp(cmd,"aide")){
            cmdHelp();
        }
        if(!strcmp(cmd,"exit") || !strcmp(cmd,"quit") || !strcmp(cmd,"fermer")){
            quitter = 1;
        }
        if(!strcmp(cmd,"ajouter")){
            cmdAjouter(liste);
        }
        if(!strcmp(cmd,"calculer")){
            char* paysAutre = demanderPays(liste,0);
            cmdCalculer(liste, paysLocal,paysAutre);
            free(paysAutre);
        }
        if(!strcmp(cmd,"afficher")){
            cmdAfficher(liste);
        }
        if(!strcmp(cmd,"info") || !strcmp(cmd,"infos")){
            cmdInfo();
        }
    }
    freeLLC(liste);
    free(paysLocal);
}

int commandeExiste(char* cmd){
    char* listeCmd[50] = {"help","h","aide","ajouter","calculer","afficher","exit","quit","fermer","info","infos"};
    int listeCmdTailleLog = 11;
    for(int i=0; i<listeCmdTailleLog; i++){
        if(strcmp(cmd,listeCmd[i]) == 0){
            return 1;
        }
    }
    return 0;
}

char* demanderPays(LLC* liste, int paysEstLocalBool){
    char* tempPays = (char*)malloc(sizeof(char)*50);
    if(paysEstLocalBool){
        printf("Entrez le nom du pays ou vous vous situez actuellement :");
    }
    else{
        printf("Entrez le nom du pays pour lequel vous voulez calculer l'heure :");
    }
    fflush(stdin);
    //gets(tempPays);
    fgets(tempPays,50,stdin);
    tempPays[strcspn(tempPays, "\n")] = 0;
    if(paysAEteTrouve(chercherPaysDansLLC(liste, tempPays))){
        return tempPays;
    }
    else{
        printf("Votre Pays n'a pas ete trouve dans la liste. Veuillez l'ajouter:\n");
        cmdAjouter(liste);
        char* paysLocal = chercherDernierMaillonPays(liste);
        return paysLocal;
    }
}

LLC* initialisationLLC(){
    LLC* maLLC = creerListeVide();
    creerMaillonEtAjouterEnQueue(maLLC,"France",1,1);
    creerMaillonEtAjouterEnQueue(maLLC,"USA Eastern",-5,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Canada",-4,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Inde",5.5,0);
    creerMaillonEtAjouterEnQueue(maLLC,"Malaisie",8,0);
    creerMaillonEtAjouterEnQueue(maLLC,"UK",0,1);
    creerMaillonEtAjouterEnQueue(maLLC,"USA Pacific",-8,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Sri lanka",5.5,0);
    creerMaillonEtAjouterEnQueue(maLLC,"Pologne",1,1);
    creerMaillonEtAjouterEnQueue(maLLC,"République Tchèque",1,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Republique Tcheque",1,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Chine",8,0);
    creerMaillonEtAjouterEnQueue(maLLC,"Afrique du Sud",2,0);
    creerMaillonEtAjouterEnQueue(maLLC,"USA Mountain",-7,1);
    creerMaillonEtAjouterEnQueue(maLLC,"USA Central",-6,1);
    creerMaillonEtAjouterEnQueue(maLLC,"Hawai",-10,0);
    creerMaillonEtAjouterEnQueue(maLLC,"Test Island Pacific",-14,0);
    return maLLC;
}

void afficherEntete(){
    printf("                   _                             _               \n"
           "  /\\/\\   __ ___  _(_)       /\\  /\\___  _ __ __ _(_)_ __ ___  ___ \n"
           " /    \\ / _` \\ \\/ / |_____ / /_/ / _ \\| '__/ _` | | '__/ _ \\/ __|\n"
           "/ /\\/\\ \\ (_| |>  <| |_____/ __  / (_) | | | (_| | | | |  __/\\__ \\\n"
           "\\/    \\/\\__,_/_/\\_\\_|     \\/ /_/ \\___/|_|  \\__,_|_|_|  \\___||___/\n");
    printf("\nBienvenue dans votre logiciel de calcul d'horaires !\n");
    printf("Ce logiciel a ete cree par Max Bortolotti, tous droits reserves.\n\n");
}


void cmdInfo(){
    printf("Voici les informations de ce logiciel :\n");
    printf("   Tous les decalages de ce logiciel sont a partir de UTC (equivalent a GMT), par exemple \n   le decalage de la France en UTC est de 1.\n"
           "   ATTENTION : Si la date actuelle est entre le dernier dimanche d'octobre et le premier \n   dimanche de novembre, les decalages horaires affiches par ce logiciel seront faux pour \n   tous les pays hors UE qui utilisent l'heure d'ete.\n   Vous pouvez trouver une carte de ces pays depuis ce lien : [INDISPONIBLE]\n"
           "   PS : Les fuseaux horaires des USA portent les noms 'USA '+ 'Pacific', 'Mountain', \n   'Central' ou 'Eastern'(D'ouest en est).\n\n");
}



