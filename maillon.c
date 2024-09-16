//
// Created by Max on 12/09/2024.
//

#include "maillon.h"

Maillon* creerMaillon(char *pays, float decalage, int heureEteBool){
    Maillon* nouveauMaillion = (Maillon*)malloc(sizeof(Maillon));
    strcpy(nouveauMaillion->Pays,pays);
    nouveauMaillion->heureDeDecalage = decalage;
    nouveauMaillion->successeur = NULL;
    nouveauMaillion->heureEteBool = heureEteBool;
    return nouveauMaillion;
}

void afficherInfosMaillon(Maillon* maillonnaise, int afficherEnteteBool){
    if(afficherEnteteBool == 1){
        printf("Informations du maillon :\n");
    }
    printf(" ~ Pays : %s\n   Decalage : %f \n   Heure d'ete : %d \n",maillonnaise->Pays,maillonnaise->heureDeDecalage,maillonnaise->heureEteBool);
}

Maillon* creerMaillonAvecInput() {
    char tempPays[50];
    printf("Entrez le nom du pays :");
    fflush(stdin);
    gets(tempPays);
    float tempDecalage;
    printf("Entrez le decalage :");
    scanf("%f", &tempDecalage);
    int heureEteBool;
    printf("Ce pays a t-il une heure d'ete (0 ou 1) :");
    scanf("%d", &heureEteBool);
    Maillon* monMaillon = creerMaillon(tempPays, tempDecalage, heureEteBool);
    return monMaillon;
}


void freeMaillon(Maillon* maillon){
    free(maillon);
    maillon = NULL;
    return;
}

Maillon* creerMaillonAvecInputEtSauvgarder(){
    char tempPays[50];
    printf("Entrez le nom du pays :");
    fflush(stdin);
    gets(tempPays);
    float tempDecalage;
    printf("Entrez le decalage :");
    scanf("%f", &tempDecalage);
    int heureEteBool;
    printf("Ce pays a t-il une heure d'ete (0 ou 1) :");
    scanf("%d", &heureEteBool);
    Maillon* monMaillon = creerMaillon(tempPays, tempDecalage, heureEteBool);
    // Sauvegarde fichier
    FILE* filePtr = fopen("data.txt","a+");
    fprintf(filePtr,"%s\n%f\n%d\n",monMaillon->Pays,monMaillon->heureDeDecalage,monMaillon->heureEteBool);
    fclose(filePtr);
    return monMaillon;
}