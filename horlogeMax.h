//
// Created by Max on 13/09/2024.
//

#ifndef DECALAGEHORAIREC_HORLOGEMAX_H
#define DECALAGEHORAIREC_HORLOGEMAX_H

#include "LLC.h"
#include <time.h>
#include <stdio.h>

typedef struct tm tmM;

tmM majHorloge(int afficherEnteteBool);
void afficherInfosHorloge(tmM timeMax);
float compenserPourHeureEteFR();
float compenserPourHeureEteAvecPaysLocal(LLC* Liste, char* paysAChercher);
float comparerDeuxPays(LLC* liste, char* paysLocal, char* paysAutre);
tmM calculerHeurePaysAutre(float fuseauD);
void afficherInfosHorlogeBrefPays(tmM timeMax, char* pays, int afficherDateBool);
void afficherHeurePaysBoutEnBout(LLC* liste, char* paysLocal, char* paysAutre);
void afficherInfosHorlogeBrefPaysAuto(tmM timeMax, char* pays);

#endif //DECALAGEHORAIREC_HORLOGEMAX_H
