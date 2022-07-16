#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 50

//variable globale : elle contient la durree(en seconde) des intervalles de changement de feu
const int temps = 5*60;

// declaration des types Date et boolean
typedef enum boolean{Vrai, Faux}boolean;
typedef struct Date{
    unsigned short hour;
    unsigned short minute;
    unsigned short seconds;
}Date;

//fonction d'actualisation de la date
void actualizeDate(Date *actuelDate){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    actuelDate->hour = local->tm_hour;
    actuelDate->minute = local->tm_min;
    actuelDate->seconds = local->tm_sec;

    return *actuelDate;
}

Date ajoutDetemps(Date ladate, unsigned short tempsAjouter){
    //tempsAjouter est en seconde
    Date ladateDapres;
    ladateDapres.hour = ladateDapres.minute = ladateDapres.seconds = 0;
    tempsAjouter = (ladate.seconds + tempsAjouter);
    if(tempsAjouter >= 60){
       ladateDapres.seconds = tempsAjouter%60;
       tempsAjouter /= 60;
       tempsAjouter = (ladate.minute + tempsAjouter);
       if(tempsAjouter >= 60){
            ladateDapres.minute = tempsAjouter%60;
            tempsAjouter /= 60;
            tempsAjouter = (ladate.hour + tempsAjouter);
            if(tempsAjouter >= 24){
                ladateDapres.hour = tempsAjouter%24;
                tempsAjouter /= 24;
            }else
                ladateDapres.hour = tempsAjouter;
       }else
           ladateDapres.minute = tempsAjouter;
    }else
        ladateDapres.seconds = tempsAjouter;
    return ladateDapres;
}

int main()
{
    //Declaration des variables
    int i, m, s, sb = -1;
    char * feu = "Rouge";
    Date ladate, ajout;
    //cette varaible va nous oermetre d'afficher l'heure tous 1 minute
    int mb = mb = ladate.minute;

    //la condition du while precise combient de fois on doit faire la boucle
    for(i = 0; i = N; i++){
        int pos;
        if( strcmp(feu, "Rouge") == 0){
            printf("\n\t\t****%s***\n", feu);
            feu = "Vert";
        }else if( strcmp(feu, "Vert") == 0){
            printf("\n\t\t****%s***\n", feu);
            feu = "Jaune";
        }else{
            printf("\n\t\t****%s***\n", feu);
            feu = "Rouge";
        }
        actualizeDate(&ladate);
        ajout = ajoutDetemps(ladate, temps);
        printf("%02d:%02d:%02d\n\n", ladate.hour, ladate.minute, ladate.seconds);
        i = 0;
        //cas ou le temps addition est inferieur a 60s
        if (ajout.minute == 0 && ajout.hour == 0){
            while(ajout.seconds != ladate.seconds){
                s = ladate.seconds;
                actualizeDate(&ladate);
                //affiche les secondes
                if(s != sb){
                    printf("%d...", ladate.seconds);
                    sb = ladate.seconds;
                }
            }
        }
        //cas ou le temps addition est inferieur a 60min
        else if(ajout.minute != 0 && ajout.hour == 0){
            while(ajout.minute != ladate.minute || ajout.seconds != ladate.seconds){
                m = ladate.minute;
                actualizeDate(&ladate);
                //affiche l'heure apres une minute
                if(m != mb){
                    printf("%02d:%02d:%02d\n", ladate.hour, ladate.minute, ladate.seconds);
                    mb = ladate.minute;
                }
            }
        }
        //cas ou le temps addition est superieur a 60min
        else if(ajout.hour != 0){
            while( ajout.hour != ladate.hour || ajout.minute != ladate.minute || ajout.seconds != ladate.seconds){
                m = ladate.minute;
                actualizeDate(&ladate);
                //affiche l'heure apres une minute
                if(m != mb){
                    printf("%02d:%02d:%02d\n", ladate.hour, ladate.minute, ladate.seconds);
                    mb = ladate.minute;
                }
            }
        }
    }
    return 0;

}

