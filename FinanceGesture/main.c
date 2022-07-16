#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define N 200
// global variables
char MDP[10], wayTofolder[100] = "E:\\ProjetC\\MarcoMoneyGesture\\";
typedef enum booleen{Vrai, Faux}booleen;
typedef struct Date{
    unsigned short day;
    unsigned short month;
    unsigned short year;
    unsigned short hour;
    unsigned short minute;
    unsigned short seconds;
}Date;
typedef struct Entry{
    Date date;
    unsigned int amount;
}Entry;
typedef struct MonthlyIncome{
    unsigned int amountOut;
    unsigned int amountIn;
    unsigned int defAmount;
}MonthlyIncome;
// functions and procedures
void actualizeDate(Date *actuelDate){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    actuelDate->day = local->tm_mday;
    actuelDate->month = local->tm_mon +1;
    actuelDate->year = local->tm_year +1900;
    actuelDate->hour = local->tm_hour;
    actuelDate->minute = local->tm_min;
    actuelDate->seconds = local->tm_sec;
}

void initializeEntry(Date ladate, char *chaine){
    int conf, amount;
    FILE *fichier;
    printf("Montant entrant : ");
    scanf("%d",&amount);
    printf("1.Enregistrer \t2.modifier\n");
    scanf("%d", &conf);
    if((fichier = fopen(chaine,"r")) == NULL){
        fichier = fopen(chaine,"w");
        fprintf(fichier,"Date des Etrees\t Precisions Hoaire\t Montant (FCFA)\n");
        if(conf == 1){
            fprintf(fichier, "%02d/%02d/%d\t %02d:%02d:%02d\t\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, amount);
            fprintf(fichier,"---------------------------------------------------------------------------\n");
            fclose(fichier);
        }else if (conf == 2){
            printf("Montant entrant : ");
            scanf("%d",&amount);
            fprintf(fichier, "%02d/%02d/%d\t %02d:%02d:%02d\t\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, amount);
            fprintf(fichier,"---------------------------------------------------------------------------\n");
            fclose(fichier);
        }
    }else{
        fichier = fopen(chaine,"a");
        if(conf == 1){
            fprintf(fichier, "%02d/%02d/%d\t %02d:%02d:%02d\t\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, amount);
            fprintf(fichier,"---------------------------------------------------------------------------\n");
            fclose(fichier);
        }else{
            printf("Montant entrant : ");
            scanf("%d",&amount);
            fprintf(fichier, "%02d/%02d/%d\t %02d:%02d:%02d\t\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, amount);
            fprintf(fichier,"---------------------------------------------------------------------------\n");
            fclose(fichier);
        }
    }
    printf("Enregistrer avec succes... \n");
}

void MonthlyEntry(MonthlyIncome mensuel, Entry entree, Date ladate, char *chaine){
    FILE *fichierEnterMensuel;
    int conf;
    printf("voulez-vous finaliser les transaction du mois ? Vous pouvez toujours le faire ulterieurement\n1.Oui \t2.Consulter\n");
    scanf("%d", &conf);
    if(conf == 1){
        printf("Total entrees : %d\nTotal Sortie: %d\nTotal: %d\n", mensuel.amountIn, mensuel.amountOut, mensuel.defAmount);
        printf("Etes vous sure de vouloir enregistrer ces donnees maintenant? \n1.Oui \t2.Non\n");
        scanf("%d", &conf);
        if(conf == 1){
            if( (fichierEnterMensuel = fopen(chaine, "r")) == NULL){
                fichierEnterMensuel = fopen(chaine, "w");
                fprintf(fichierEnterMensuel, "Date des denieres entrees\tTotal Entree\t Total Sortie\t Total definitif\n");
                fprintf(fichierEnterMensuel, "%02d/%02d/%02d\t %02d:%02d:%02d\t $%d\t\t $%d\t\t $%d\n", ladate.day, ladate.month, ladate.year, ladate.hour,
                 ladate.minute, ladate.seconds, mensuel.amountIn, mensuel.amountOut, mensuel.defAmount);
                fprintf(fichierEnterMensuel,"\t\t---------------------------------------------------------------------------\n");
                fclose(fichierEnterMensuel);
                printf("\nSolde mensuel verifie et enregistrer dans le fichier 'EntrerMensuelle' accessible directement\n");
            }else{
                fichierEnterMensuel = fopen(chaine, "a");
                fprintf(fichierEnterMensuel, "%02d/%02d/%02d\t %02d:%02d:%02d\t $%d\t\t $%d\t\t $%d\n", ladate.day, ladate.month, ladate.year, ladate.hour,
                 ladate.minute, ladate.seconds, mensuel.amountIn, mensuel.amountOut, mensuel.defAmount);
                fprintf(fichierEnterMensuel,"\t\t---------------------------------------------------------------------------\n");
                fclose(fichierEnterMensuel);
                printf("\nSolde mensuel verifie et enregistrer dans le fichier 'EntrerMensuelle' accessible directement\n");
            }
        }
    }else if(conf == 2){
       printf("Total entrees : %d\nTotal Sortie: %d\nTotal: %d\n", mensuel.amountIn, mensuel.amountOut, mensuel.defAmount);
    }
}

void rappelMois(int somP[], char *chemin){
    FILE *fichier = fopen(chemin, "r");
    int i = 0, j  = 0; char c, som[10];
    if(fichier != NULL){
        while( (c = fgetc(fichier)) != EOF){
            if( c == '$'){
                while((c =fgetc(fichier)) != '\t'){
                    som[i] = c; i++;
                }
                if( j < 3){
                    somP[j] = strtol(som,NULL, 10);j++;

                }else{
                    j = 0; somP[j] = strtol(som,NULL, 10); j++;
                }while(--i > 0){
                    som[i] = NULL;
                }
            }
        }
    }else{
        printf("Un fichier n'a pu etre ouvert ou n'existe pas\n");
    }
}

void lectureFichier(MonthlyIncome *mensuel, char *chemin1, char *chemin2, char *chemin3){
    mensuel->amountIn = mensuel->amountOut = mensuel->defAmount = 0;
    int i = 0, somP[] = {0, 0, 0};
     char c, som[10];
    FILE *fichier = fopen(chemin1, "r"), *fichierSortir = fopen(chemin2, "r");
    rappelMois(somP, chemin3);
    printf("Debut de lecture des fichiers\n.....\n........\n..............");
    while( (c = fgetc(fichier)) != EOF){
        if( c == '$'){
            while((c =fgetc(fichier)) != '\n'){
                som[i] = c; i++;
            }
            mensuel->amountIn += strtol(som,NULL, 10);
            while(--i > 0){
                som[i] = NULL;
            }
        }
    }
    mensuel->amountIn = mensuel->amountIn - somP[0];
    while( (c = fgetc(fichierSortir)) != EOF){
        if( c == '$'){
            while((c =fgetc(fichierSortir)) != '\n'){
                som[i] = c; i++;
            }
            mensuel->amountOut += strtol(som,NULL, 10);
            while(--i > 0){
                som[i] = NULL;
            }
        }
    }
    mensuel->amountOut = mensuel->amountOut - somP[1];
    fclose(fichier); fclose(fichierSortir);
    mensuel->defAmount = mensuel->amountIn - mensuel->amountOut;
    printf("\nFichiers prets a etre utiiser\n");
}

void ModifyEntry(char *chemin, char *date, Date ladate){
    FILE *fichier = fopen(chemin, "r+");
    char c, str[11], longStr[1000];
    int amount, pos, i = 0;

    if( fichier != NULL){
        while((c = fgetc(fichier)) != EOF){
            if(c == '\n' ){
                pos = ftell(fichier);
                fgets(str, 11, fichier);
                if(strcmp(str, date) == 0){
                    printf("%d, %d", pos);
                    printf("Refenrence de l'enregistrement a modifier:\n %s", str);
                    while((c = fgetc(fichier)) != '\n')
                        printf("%c", c);
                    while((c = fgetc(fichier)) != EOF){
                        longStr[i] = c;i++;
                    }
                    printf("\nMontant de modification : ");
                    scanf("%d",&amount);
                    fseek(fichier, pos, SEEK_SET);
                    fprintf(fichier, "%02d/%02d/%d\t %02d:%02d:%02d\t\t $%d\n", ladate.day, ladate.month,ladate.year,
                        ladate.hour, ladate.minute, ladate.seconds, amount);
                    fprintf(fichier, "%s", longStr);
                    printf("\n\t\t***Modifier avec succes***\n");
                    fclose(fichier);break;
                }
            }
        }
        if(i == 0)
            printf("\n\t\t***Desole !***\nAucun enregistrement de ce genre n'a ete faites a cette date\n");
    }else
        printf("une Erreur est survenue lors de l'ouverture du fichier en question\n");
}

void underSpend(MonthlyIncome mensuel, Date ladate, char *chaine){
    FILE * fichierSortir;
    unsigned int amount, conf;
    char motif[N];
    printf("Montant sortant :");
    scanf("%d", &amount);
    printf("Motif :");
    scanf("%s", motif);
    printf("\nConfirmer votre retrait de %d ayant pour motif :%s\n1.Confirmer\t 2.Annuler\n", amount, motif);
    scanf("%d", &conf);
    if( conf == 1){
        if((fichierSortir = fopen(chaine, "r")) == NULL){
            fichierSortir = fopen(chaine, "w");
            fprintf(fichierSortir, "Date de retrait\t\t Motif du retrait \t\t Montant\n");
            fprintf(fichierSortir, "%02d/%02d/%d %02d:%02d:%02d\t%s\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, motif, amount);
            fprintf(fichierSortir,"---------------------------------------------------------------------------\n");
            fclose(fichierSortir);
        }else{
            fichierSortir = fopen(chaine, "a");
            fprintf(fichierSortir, "%02d/%02d/%d %02d:%02d:%02d\t%s\t $%d\n", ladate.day, ladate.month,ladate.year,
                   ladate.hour, ladate.minute, ladate.seconds, motif, amount);
            fprintf(fichierSortir,"---------------------------------------------------------------------------\n");
            fclose(fichierSortir);
        }
        printf("l'operation a ete un succes\n");
    }else{
        printf("requete annulee\n");
    }
}

void lirePourConsulter(FILE * fichier, char *str){
    char c;
    if((fichier = fopen(str, "r")) != NULL){
        while((c = fgetc(fichier)) != EOF){
            printf("%c", c);
        }
    }else{
        printf("Erreur d'ouverture ou fichier manquant\n");
    }
    fclose(fichier);
}

booleen checkPassword(FILE *fichier){
    char c; Date date;
    printf("Access restraint, solicite un Mot de Passe :");
    cryptPassword();
    if(strcmp(MDP, "Abner1.2Be") == 0)
       return Vrai;
    else{
        fichier = fopen("E:\\ProjetC\\MarcoMoneyGesture\\password.txt", "a");
        actualizeDate(&date);
        fprintf(fichier, " mot de passe: \"%s\"\t Date de temtation d'access: %02d:%02d:%02d a %02d:%02d:%02d\n", MDP, date.day, date.month, date.year,
                 date.hour, date.minute, date.seconds );
        fclose(fichier);
        return Faux;
   }
}

void cryptPassword(){
    char pwrd[10], ch; int i;
    for(i = 0 ; i < 10 ; i++){
        ch = getch();
        pwrd[i] = ch;
        ch = '*';
        printf("%c", ch);
    }
    pwrd[i] = '\0' ;
    strcpy(MDP, pwrd);
}

void createAcount(char *pwrd, char *compte){
    FILE *fichier;
    fichier = fopen("E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt", "a");
    fprintf(fichier, "@%s&#%s\n", compte, pwrd);
    fclose(fichier);
}

booleen ouvrirSonCompte(char *chemin, char *compte){
    char pwrd[15], acount[30], c; int i = 0;
    booleen existe = Faux;
    FILE *fichier;
    fichier = fopen(chemin, "r");

    printf("Nom de Compte : ");
    scanf("%s", compte);
    printf("Mot de passe : ");
    cryptPassword();
    while( (c = fgetc(fichier)) != EOF){
        if( c != '\n'){
            if(c == '@'){
                while( fgetc(fichier) != '&')
                    i++;
                fseek(fichier, -(i+1), SEEK_CUR);
                fgets(acount,(i+1), fichier); i = 0;
            }else if( c  == '#'){
                fgets(pwrd, 11,fichier);
                if(strcmp(pwrd, MDP) == 0 && strcmp(compte, acount) == 0 ){
                    existe = Vrai; break;
                }
            }
        }
    }
    fclose(fichier);
    return existe;
}

void changePassword(){
     char pwrd[10], acount[20], compte[20], c, str[1000];
      int i = 0; long posCur = 0;
    booleen existe = Faux;
    FILE *fichier;
    fichier = fopen("E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt", "r+");
    printf("Nom de Compte : ");
    scanf("%s", compte);
    printf("Mot de passe : ");
    cryptPassword();
    while( (c = fgetc(fichier)) != EOF){
        if( c != '\n'){
            if(c == '@'){
                while( fgetc(fichier) != '&')
                    i++;
                fseek(fichier, -(i+1), SEEK_CUR);
                fgets(acount,(i+1), fichier); i = 0;
            }else if( c  == '#'){
                posCur = ftell(fichier);
                fgets(pwrd, 11,fichier);
                if(strcmp(pwrd, MDP) == 0 && strcmp(compte, acount) == 0 ){
                    while( (c = fgetc(fichier)) != EOF){
                        str[i] = c; i++;
                    }
                    printf("\nEntrer le mot de passe (10) :");
                    cryptPassword();
                    fseek(fichier, posCur, SEEK_SET);
                    fprintf(fichier, "%s", MDP);
                    fprintf(fichier, "%s", str);
                    fclose(fichier);
                    printf("\nMot de passe changer avec succes\n");break;
                }
            }
        }
    }
    if(i == 0)
        printf("\nCompte ou mot de passe incorrect\n");
}

void pureCleanUp(char *compte, char *chemin1, char *chemin2, char *chemin3){
    int choix;
    printf("\n\t\t***Warning Alert !***\n\t------------------------------------------------\n");
    printf("Every action here is irreversible, Do you want to validate the suppression of all data kept still now ?\n");
    cryptPassword();
    if(!ouvrirSonCompte(compte, MDP)){
        printf("\n1.suppression du fichier des entrees\t 2.suppressioin du fichier des sorties\t 5.Annuler\n3.suppresion du fichier des Bilans\t 4.Tous les fichiers de votre compte\n");
        scanf("%d", &choix);
        switch(choix){
            case 1:
                remove(chemin1);printf("data clear out successfuly\n");
                break;
            case 2:
                remove(chemin2);printf("data clear out successfuly\n");
                break;
            case 3:
                remove(chemin3);printf("data clear out successfuly\n");
                break;
            case 4:
                remove(chemin1);printf("data clear out successfuly\n");
                remove(chemin2);printf("data clear out successfuly\n");
                remove(chemin3);printf("data clear out successfuly\n");
                break;
            case 5:printf("requete annulee\n");
            default: printf("Option invalide\n");
        }
        if(strcmp(compte, "Admin") == 0){
            printf("voulez-vous  aussi supprimer tous les utilisateurs ?\n1.Oui\t 2.Non\n");
            scanf("%d", choix);
            if(choix == 1)
                remove("E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt");printf("data clear out successfuly\n");
        }
    }
}

void myMain(FILE * fichier, char *cheminE,char *cheminS,char *cheminM, char *cheminPwrd, char *cheminNewPwrd, char *compte){
    long choix;
    Entry entry;
    Date ladate;
    MonthlyIncome mensuel;
    char password[10];
    printf("\n\t\t\tBienvenue !\n\t------------------------------------------------\n");
    do{
        printf("Que voulez-vous faire?\n1.Ajouter une Entree\t 3.Bilan du mois\t 5.Modifier un enregistrement\t 7.Apocalipse\n2.Retirer de l'agent\t 4.Consulter\t 6.Consuter le fichier d'access\t 8.Changer de mot passe\n");
        scanf("%d", &choix);
        switch(choix){
            case 1:
                actualizeDate(&ladate);
                initializeEntry(ladate, cheminE);
                break;
            case 2:
                actualizeDate(&ladate);
                underSpend(mensuel, ladate, cheminS);
                break;
            case 3:
                lectureFichier(&mensuel, cheminE, cheminS, cheminM);
                actualizeDate(&ladate);
                MonthlyEntry(mensuel, entry, ladate, cheminM);
                break;
            case 4:
                printf("1.Consulter les entrees\t 2.Consulter les sorties\t 3.Historique du Bilan mensuelle\n");
                scanf("%d", &choix);
                if(choix == 1)
                    lirePourConsulter(fichier, cheminE);
                else if(choix == 2)
                    lirePourConsulter(fichier, cheminS);
                else if (choix == 3)
                    lirePourConsulter(fichier, cheminM);
                else printf("Option invalide !!");
                break;
            case 5:
                printf("Entrer la date de acienne enregistrement a modifier (dd/mm/aaaa) : ");
                char chaine[10];
                scanf("%s", chaine);
                actualizeDate(&ladate);
                ModifyEntry(cheminE,chaine, ladate);
                break;
            case 6:
                lirePourConsulter(fichier, cheminPwrd);
                printf("\nVoulez-vous supprimer le registre ? : 1.Oui\t 2.Non\t 3.fichier compte");
                scanf("%d", &choix);
                switch(choix){
                    case 1:
                        remove(cheminPwrd);
                        printf("\n registre vider avec success\n\n");
                        break;
                    case 2: break;
                    case 3:
                        printf("Consulter le fichier compte entrant votre mot de passe(Admin) :");
                        if( strcmp(compte, "Admin") == 0){
                            cryptPassword();
                            if(strcmp(MDP, "Abner1.2Be") == 0)
                                lirePourConsulter(fichier, cheminNewPwrd);
                            else printf(" :\tACCES REFUSSER\n");
                        }else printf(" :\t***Desolé, Ce compte n'a pas tous permision requis pour cette operation***\n");
                }
                break;
            case 7:
                pureCleanUp(compte,cheminE, cheminS, cheminM);
                break;
            case 8:
                if( strcmp(compte, "Admin") == 0)
                    printf("Inpossible de changer le mot de passe de l'administrateur\n");
                else changePassword();
                break;
            default:
                 printf("\nOption Invalide !!!");
        }
        printf("voulez-vous faire une autre operation ?\n1.Oui\t 2.Non\n");
        scanf("%d", &choix);
        if(choix != 1 && choix != 2){
            printf("\nOption Invalide !!!\nEssayer autre chose: ");
            scanf("%d", &choix);
        }
    }while(choix == 1);
}

void createFolder(char *acount){
    char rootAccess[100] = "mkdir";
    strcat(strcat(rootAccess, " E:\\ProjetC\\MarcoMoneyGesture\\"), acount);
    system(rootAccess);
}

void strConcat(char *chemin, char *chemin1, char *chemin2, char *chemin3){
    char chaine[100];
    strcpy(chaine, chemin);
    strcat(chaine, "Entree.txt");
    strcpy(chemin1, chaine);
    strcpy(chaine, chemin);
    strcat(chaine, "Sorties.txt");
    strcpy(chemin2, chaine);
    strcpy(chaine, chemin);
    strcat(chaine, "EntrerMensuelle.txt");
    strcpy(chemin3, chaine);
    strcpy(chaine, chemin);
}
int main()
{
    long choix,compteur = 0, cmd;
    FILE * fichier;
    char *chemin = "E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt";
    char chemin1[N], chemin2[N], chemin3[N], acount[15];
    booleen booleanAns;

    printf("\n\t\t***Welcome / Bienvenue***\n\t------------------------------------------------\n");
    BEGINING:printf("1.continuer en tanque administrateur\t 2.Ouvrir un nouveaux compte\t 3.Son compte\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            if(checkPassword(fichier) == Faux){
                while(compteur < 4){
                    printf("\nNombre d'essai restant : %d\n", (4-compteur));
                    if(checkPassword(fichier) == Vrai)
                        break;
                    compteur++;
                }
                if(compteur >= 4){
                    printf("\nNombre d'essai epuiser,En cas de mot de passe perdu; Contacter le developeur de l'application pour plus information\n");
                    exit(0);
                }else goto ICI;
            }else ICI:myMain(fichier, "E:\\ProjetC\\MarcoMoneyGesture\\Entree.txt", "E:\\ProjetC\\MarcoMoneyGesture\\Sorties.txt","E:\\ProjetC\\MarcoMoneyGesture\\EntrerMensuelle.txt","E:\\ProjetC\\MarcoMoneyGesture\\password.txt", "E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt", "Admin");
        case 2:
            printf("Nom de Compte(20) : ");
            scanf("%s", acount);
            printf("Le mot de passe doit contenir exactement 10 caracteres sinon il pourait generer des problemes d'acces.\nMot de passe : ");
            cryptPassword();
            createAcount(MDP, acount);
            createFolder(acount);
            goto HERE;
        case 3:
            UP:booleanAns = ouvrirSonCompte(chemin, acount);
            if(booleanAns == Faux){
                printf("\n\t\t***Compte inconnue !! ***\n");
                goto UP;
            }
            HERE:strcat(strcat(wayTofolder, acount), "\\");
            strConcat(wayTofolder,chemin1, chemin2, chemin3);
            myMain(fichier, chemin1, chemin2, chemin3, "E:\\ProjetC\\MarcoMoneyGesture\\password.txt", "E:\\ProjetC\\MarcoMoneyGesture\\NewPassword.txt", acount);
        default: printf("\t\t***Option invalide***");
    }
    printf("\n\t\t***Merci pour votre confiance***\n\t------------------------------------------------\n");
    printf("\t\t*** 1. Menu principal ***\t\t*** 2. terminer ***\n");
    scanf("%d",&cmd);
    if(cmd == 1)
        goto BEGINING;
    else if(cmd != 2)
        printf("\t\t***Option invalide***");
    return 0;
}
