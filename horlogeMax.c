//
// Created by Max on 13/09/2024.
//

#include "horlogeMax.h"

tmM majHorloge(int afficherEnteteBool){
    time_t t = time(NULL);
    struct tm timeMax = *localtime(&t);
    if(afficherEnteteBool == 1){
        printf("L'horloge a ete mise a jour.\n");
    }
    return (tmM)timeMax;
}


void afficherInfosHorloge(tmM timeMax){
    printf("Date actuelle (annee mois jour) : %d %d %d\n", timeMax.tm_year + 1900, timeMax.tm_mon + 1, timeMax.tm_mday);
    printf("Heure actuelle : %dh %dmin %dsec\n", timeMax.tm_hour, timeMax.tm_min, timeMax.tm_sec);
    printf("Est-ce que l'heure d'ete est en vigeur : %d\n\n", timeMax.tm_isdst);
    return;
}

float compenserPourHeureEteFR(){
    tmM timeMax = majHorloge(0);
    float fuseauFrCompense = 1 + timeMax.tm_isdst;
    return fuseauFrCompense;
}

float compenserPourHeureEteAvecPaysLocal(LLC* liste, char* paysAChercher){
    float* floatTemp = chercherPaysDansLLC(liste, paysAChercher);
    if(paysAEteTrouve(floatTemp)){
        tmM timeMax = majHorloge(0);
        float fuseauCompense = *floatTemp + timeMax.tm_isdst;
        return fuseauCompense;
    }
    printf("ERREUR ! Les resultats suivants ne seront pas fiables.\n");
    return 99999.00001;
}


float comparerDeuxPays(LLC* liste, char* paysLocal, char* paysAutre){
    float* fuseauAutre = chercherPaysDansLLC(liste,paysAutre);
    if(paysAEteTrouve(fuseauAutre) == 0){
        printf("ERREUR ! Les resultats suivants ne seront pas fiables.\n");
        return 99999.00001;
    }
    else{
        if(chercherSiPaysAHeureEte(liste, paysAutre) == 1){
            float* floatTemp = chercherPaysDansLLC(liste, paysLocal);
            if(paysAEteTrouve(floatTemp)){
                float fuseauLocal = *floatTemp;
                float fuseauDelta = *fuseauAutre - fuseauLocal;
                return fuseauDelta;
            }
            else{
                printf("ERREUR ! Les resultats suivants ne seront pas fiables.\n");
                return 99999.00001;
            }
        }
        else{
            float fuseauLocal = compenserPourHeureEteAvecPaysLocal(liste, paysLocal);
            float fuseauDelta = *fuseauAutre - fuseauLocal;
            return fuseauDelta;
        }
    }
}


tmM calculerHeurePaysAutre(float fuseauD){
    tmM timeMax = majHorloge(0);
    tmM heurePaysAutre = timeMax;
    int fuseauDPartieEntiere = (int)fuseauD;
    heurePaysAutre.tm_hour = heurePaysAutre.tm_hour+fuseauDPartieEntiere;
    heurePaysAutre.tm_min = heurePaysAutre.tm_min + (60 * (fuseauD - fuseauDPartieEntiere));
    //verif minutes > 60
    if(heurePaysAutre.tm_min > 60){
        heurePaysAutre.tm_hour = heurePaysAutre.tm_hour + 1;
        heurePaysAutre.tm_min = heurePaysAutre.tm_min - 60;
    }
    //verif heures >= 24
    if(heurePaysAutre.tm_hour >= 24){
        heurePaysAutre.tm_mday = heurePaysAutre.tm_mday + 1;
        heurePaysAutre.tm_hour = heurePaysAutre.tm_hour - 24;
    }
    //verif heures < 0
    if(heurePaysAutre.tm_hour < 0){
        heurePaysAutre.tm_mday = heurePaysAutre.tm_mday - 1;
        heurePaysAutre.tm_hour = heurePaysAutre.tm_hour + 24;
    }
    return heurePaysAutre;
}

void afficherInfosHorlogeBrefPays(tmM timeMax, char* pays, int afficherDateBool){
    if(afficherDateBool == 1){
        printf("%s :\n",pays);
        printf("   Date actuelle (annee mois jour) : %d %d %d\n", timeMax.tm_year + 1900, timeMax.tm_mon + 1, timeMax.tm_mday);
        printf("   Heure actuelle : %dh %dmin %dsec\n\n", timeMax.tm_hour, timeMax.tm_min, timeMax.tm_sec);
        return;
    }
    printf("Heure actuelle a '%s' est : %dh %dmin %dsec\n", pays, timeMax.tm_hour, timeMax.tm_min, timeMax.tm_sec);
    return;
}

void afficherInfosHorlogeBrefPaysAuto(tmM timeMax, char* pays){
    tmM timeLocal = majHorloge(0);
    if(timeMax.tm_mday != timeLocal.tm_mday){
        printf("%s :\n",pays);
        printf("   Date actuelle (annee mois jour) : %d %d %d\n", timeMax.tm_year + 1900, timeMax.tm_mon + 1, timeMax.tm_mday);
        printf("   Heure actuelle : %dh %dmin %dsec\n\n", timeMax.tm_hour, timeMax.tm_min, timeMax.tm_sec);
        return;
    }
    printf("Heure actuelle a '%s' est : %dh %dmin %dsec\n", pays, timeMax.tm_hour, timeMax.tm_min, timeMax.tm_sec);
    return;
}

void afficherHeurePaysBoutEnBout(LLC* liste, char* paysLocal, char* paysAutre){
    afficherInfosHorlogeBrefPaysAuto(calculerHeurePaysAutre(comparerDeuxPays(liste, paysLocal, paysAutre)), paysAutre);
}