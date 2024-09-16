//
// Created by Max on 12/09/2024.
//

#ifndef DECALAGEHORAIREC_MAILLON_H
#define DECALAGEHORAIREC_MAILLON_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Définition d'une structure Cell représentant un Pays et son décalage horaire en heures par rapport à la France
typedef struct Maillon {
    char Pays[50];
    float heureDeDecalage;
    int heureEteBool;
    struct Maillon* successeur;
} Maillon;

Maillon* creerMaillon(char *pays, float decalage, int heureEteBool);
void afficherInfosMaillon(Maillon *maillonnaise, int afficherEnteteBool);
Maillon* creerMaillonAvecInput();
void freeMaillon(Maillon* maillon);
Maillon* creerMaillonAvecInputEtSauvgarder();

#endif //DECALAGEHORAIREC_MAILLON_H
