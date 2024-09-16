//
// Created by Max on 12/09/2024.
//

#ifndef DECALAGEHORAIREC_LLC_H
#define DECALAGEHORAIREC_LLC_H

#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LLC{
    Maillon* Liste;
}LLC;

LLC* creerListeVide();
LLC* ajouterQueueLLC(LLC* tempLLC, Maillon* tempMaillon); //renvoie aussi un pointeur de LLC au cas ou.
LLC* creerMaillonEtAjouterEnQueue(LLC* LLC, char *pays, float decalage, int heureEteBool);
void afficherLLC(LLC* maLLC);
int listeEstVide(LLC* liste);
float* chercherPaysDansLLC(LLC* liste, char* paysATrouver);
int paysAEteTrouve(float* floatAVerifier);
char* chercherDernierMaillonPays(LLC* liste);
int chercherSiPaysAHeureEte(LLC* liste, char* paysATrouver);
void freeLLC(LLC* liste);

#endif //DECALAGEHORAIREC_LLC_H
