//
// Created by Max on 14/09/2024.
//

#ifndef DECALAGEHORAIREC_MENU_H
#define DECALAGEHORAIREC_MENU_H

#include "LLC.h"
#include "horlogeMax.h"

void cmdAjouter(LLC* liste);
void cmdCalculer(LLC* liste, char* paysLocal, char* paysAutre);
void cmdAfficher(LLC* liste);
void cmdHelp();
LLC* initialisationLLC();
void menu(LLC* liste);
char* demanderPays(LLC* liste, int paysEstLocalBool);
int commandeExiste(char* cmd);
void afficherEntete();
void cmdInfo();

#endif //DECALAGEHORAIREC_MENU_H
