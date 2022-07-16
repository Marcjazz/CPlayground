#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
    //initialisation de l'heure
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    //recuperer l'heure actuel et afficher
    short heure = local->tm_hour;
    short minute = local->tm_min;
    short seconde = local->tm_sec;
    printf("il est %d:%d:%d\n", heure, minute, seconde);

    //recuperer la date actuel et afficher
    short jour = local->tm_mday;
    short mois = local->tm_mon +1;
    short an = local->tm_year +1900;
    printf("nous sommes le %d/%d/%d\n", jour, mois, an);

    //Exercice8:
    int jr, moisDonnee, annee,i;
    char *moisEnum[] ={"Janvier", "Fevrier", "Mars", "Avril", "Mais", "Juin", "Juiellet",
     "Aout", "Septembre", "Octobre", "Novembre", "Decembre", "unknown"};
    //premier methode
    /*printf("\nEntrer successivement le jour, le mois et l'annee : ");
    scanf("%d %d %d", &jr, &moisDonnee, &annee);
    switch(moisDonnee){
        case 1: i = 0;break;
        case 2: i = 1;break;
        case 3: i = 2;break;
        case 4: i = 3;break;
        case 5: i = 4;break;
        case 6: i = 5;break;
        case 7: i = 6;break;
        case 8: i = 7;break;
        case 9: i = 8;break;
        case 10: i = 9;break;
        case 11: i = 10;break;
        case 12: i = 11;break;
    }
    printf("Date: %02d-%s-%02d", jr, moisEnum[i], annee);*/

    //Deuxieme methode
    char date[10];
    printf("\nEntrer une date au format jj/mm/nnnn: ");
    scanf("%s", &date);
    char monMoi[2];
    monMoi[0] = date[0];
    monMoi[1] = date[];
    printf("\n %d\n", strtol(monMoi, NULL, 10));
    switch(strtol(monMoi, NULL, 10)){
        case 1: i = 0;break;
        case 2: i = 1;break;
        case 3: i = 2;break;
        case 4: i = 3;break;
        case 5: i = 4;break;
        case 6: i = 5;break;
        case 7: i = 6;break;
        case 8: i = 7;break;
        case 9: i = 8;break;
        case 10: i = 9;break;
        case 11: i = 10;break;
        case 12: i = 11;break;
        default: i = 12;
    }
    printf("Date: %c%c-%s-%c%c%c%c", date[0], date[1], moisEnum[i], date[6],date[7],date[8],date[9]);
    return 0;
}
