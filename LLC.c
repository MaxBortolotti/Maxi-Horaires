//
// Created by Max on 12/09/2024.
//
#include "LLC.h"

// Création d'une nouvelle liste vide
LLC* creerListeVide() {
    LLC* nouvelleLLC = (LLC*)malloc(sizeof(LLC));
    nouvelleLLC->Liste = NULL;
    return nouvelleLLC;
}

LLC* ajouterQueueLLC(LLC* tempLLC, Maillon* tempMaillon){
    if(tempLLC != NULL){
        if(tempLLC->Liste != NULL){
            if(tempLLC->Liste->successeur != NULL){
                Maillon* tempIterMaillon = tempLLC->Liste;
                while(tempIterMaillon->successeur != NULL){
                    tempIterMaillon = tempIterMaillon->successeur;
                }
                tempIterMaillon->successeur = tempMaillon;
                return tempLLC;
            }
            tempLLC->Liste->successeur = tempMaillon;
            return tempLLC;
        }
        tempLLC->Liste = tempMaillon;
        return tempLLC;
    }
    return NULL;
}

void afficherLLC(LLC* maLLC){
    if(maLLC != NULL){
        if(maLLC->Liste != NULL){
            printf("Affichage des Infos de la LLC :\n");
            afficherInfosMaillon(maLLC->Liste,0);
            if(maLLC->Liste->successeur != NULL){
                Maillon* maillonIter = maLLC->Liste;
                while(maillonIter->successeur != NULL){
                    afficherInfosMaillon(maillonIter->successeur,0);
                    maillonIter = maillonIter->successeur;
                }
            }
            printf("Fin des Infos de la LLC.\n\n");
            return;
        }
        printf("La LLC est vide.");
        return;
    }
    printf("La LLC est vide.");
    return;
}

LLC* creerMaillonEtAjouterEnQueue(LLC* Liste, char* pays, float decalage, int heureEteBool){
    Maillon* maillonTemp = creerMaillon(pays,decalage,heureEteBool);
    ajouterQueueLLC(Liste, maillonTemp);
    return Liste;
}


int listeEstVide(LLC* liste){
    if(liste == NULL){
        return 1;
    }
    if(liste->Liste == NULL){
        return 1;
    }
    return 0;
}

float* chercherPaysDansLLC(LLC* liste, char* paysATrouver){
    if(listeEstVide(liste)){
        return NULL;
    }
    if(liste->Liste->Pays != paysATrouver){
        Maillon* maillonIter = liste->Liste;
        while(maillonIter != NULL){
            if(strcmp(maillonIter->Pays, paysATrouver) == 0){
                return &maillonIter->heureDeDecalage;
            }
            maillonIter = maillonIter->successeur;
        }
        return NULL;
    }
    return &liste->Liste->heureDeDecalage;
}

int paysAEteTrouve(float* floatAVerifier){
    if(floatAVerifier == NULL){
        return 0;
    }
    if(*floatAVerifier > 14 || *floatAVerifier < - 14){
        return 0;
    }
    return 1;
}

char* chercherDernierMaillonPays(LLC* liste){
    if(liste != NULL){
        if(liste->Liste != NULL){
            if(liste->Liste->successeur != NULL){
                Maillon* tempIterMaillon = liste->Liste;
                while(tempIterMaillon->successeur != NULL){
                    tempIterMaillon = tempIterMaillon->successeur;
                }
                return tempIterMaillon->Pays;
            }
            return liste->Liste->Pays;
        }
        return NULL;
    }
    return NULL;
}

int chercherSiPaysAHeureEte(LLC* liste, char* paysATrouver){
    if(strcmp(liste->Liste->Pays,paysATrouver) != 0){
        Maillon* maillonIter = liste->Liste;
        while(maillonIter != NULL){
            if(strcmp(maillonIter->Pays, paysATrouver) == 0){
                return maillonIter->heureEteBool;
            }
            maillonIter = maillonIter->successeur;
        }
    }
    return liste->Liste->heureEteBool;
}


void freeLLC(LLC* liste){
    if(listeEstVide(liste) != 1){
        while(liste->Liste != NULL){
            if(liste->Liste->successeur != NULL){
                Maillon* tempIterMaillon = liste->Liste;
                Maillon* tempIterMaillonPere = liste->Liste;
                tempIterMaillon = tempIterMaillon->successeur;
                while(tempIterMaillon->successeur != NULL){
                    tempIterMaillon = tempIterMaillon->successeur;
                    tempIterMaillonPere = tempIterMaillonPere->successeur;
                }
                freeMaillon(tempIterMaillon);
                tempIterMaillon = NULL;
                tempIterMaillonPere->successeur = NULL;
                int argh = 28;
            }
            else{
                freeMaillon(liste->Liste);
                liste->Liste = NULL;
                return;
            }
        }
        freeMaillon(liste->Liste);
        return;
    }
    liste = NULL;
    return;
}