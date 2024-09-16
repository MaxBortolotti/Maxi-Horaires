#include <stdio.h>
#include <time.h>
#include "LLC.h"
#include "horlogeMax.h"
#include <string.h>
#include "menu.h"

//Tous les decalages de ce logiciel sont a partir de UTC (equivalent a GMT), par exemple le decalage de la
// France en UTC est de 1. N'ajoutez pas les decalages dus aus heures d'ete, ceux-ci sont directement calcules
// par le logiciel.
//ATTENTION : Si la date actuelle est entre le dernier dimanche d'octobre et le premier dimanche de novembre, les
// décalages horaires affichés par ce logiciel seront faux pour tous les pays hors UE qui utilisent l'heure d'été.
// Vous pouvez trouver une carte de ces pays depuis ce lien : https://borto.fr/nextcloud/s/bQn6x3jHzknDDQ3
// PS : Les fuseaux horaires des USA portent les noms 'USA '+ 'Pacific', 'Mountain', 'Central' ou 'Eastern'(D'ouest en est).

int main (){

    menu(initialisationLLC());

    /*

    FILE* filePtr = fopen("data.txt","r+");
    char line[70];
    while(fgets(line,70,filePtr)){
        line[strcspn(line, "\n")] = 0;
        printf("%s\n",line);
        float testF;
        fscanf(filePtr,"%f",&testF);
        printf("%f\n",testF);
        int testI;
        fscanf(filePtr,"%d",&testI);
        printf("%d\n",testI);
        char poubelle;
        fscanf(filePtr,"%c",&poubelle);
    }
    printf("Lecture finie.\n");
    char* pays = "wagablyat";
    float decalage = -7.33310;
    int heureEteBool = 0;
    fprintf(filePtr,"%s\n%f\n%d\n",pays,decalage,heureEteBool);

    fclose(filePtr);
    */

    // A IMPLEMENTER
    //Maillon* mMaill = creerMaillonAvecInputEtSauvgarder();
    //printf("paysmM : %s",mMaill->Pays);

    /*
    FILE* filePtr = fopen("data.txt","r+");
    if (filePtr == NULL){
        printf("Error opening file!");
        return 1;
    }
    //fprintf(filePtr,"%s\n%f\n%d\n","cquandquecaarrive la",-7.331,0);
    fprintf(filePtr,"CLC\n");
    fclose(filePtr);
    */
    /*
    LLC* liste = creerListeVide();
    creerMaillonEtAjouterEnQueue(liste,"France",1,1);
    char* test = demanderPays(liste,1);
    printf("test %s",test);

    afficherInfosHorloge(majHorloge(1));

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
    //afficherLLC(maLLC);

    afficherHeurePaysBoutEnBout(maLLC,"France","UK");
    afficherHeurePaysBoutEnBout(maLLC,"France","Inde");

    /*
    afficherHeurePaysBoutEnBout(maLLC, "France", "Inde");
    afficherHeurePaysBoutEnBout(maLLC, "France", "Malaisie");
    afficherHeurePaysBoutEnBout(maLLC, "France", "Canada");
    afficherHeurePaysBoutEnBout(maLLC, "France", "Hawai");
    afficherHeurePaysBoutEnBout(maLLC, "France", "Test Island Pacific");

    //cmdAjouter(maLLC);
    //afficherLLC(maLLC);

    char* listeCmd[50] = {"help","h","aide","ajouter","calculer","afficher","exit","quit","fermer"};
    printf("test : %s",listeCmd);


    char str1[50] = "wow";
    char* str2 = "wow";
    printf("egal test : %d\n",str1 == str2);
    printf("strcmp test : %d\n", strcmp(str1,str2));

    char chaine[30];
    gets(chaine);
    char chaine2[30];
    strcpy(chaine2, chaine);
    printf("Chaine de test : %s\n",chaine);
    printf("Chaine2 : %s\n",chaine2);

    float f1 = 1.25;
    float f2 = 1.90;
    float f3 = 1.9999999;
    printf("test 111 : %d %d %d\n",(int)f1, (int)f2, (int)f3);
    printf("%f", f2 - (int)f2);

    printf("Appuyez sur ENTREE pour fermer la console.\n");
    fflush(stdin);
    getchar();
    */

    return 0;
}