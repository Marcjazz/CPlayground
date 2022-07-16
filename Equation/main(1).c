#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int X, *A[],p1,p2;
    char choix;
    printf("\nInisialiser le tableau:");
    int i = 0;
    do{
        printf("A[%d] = ",i);
        scanf("%d", *A[i]);
        printf("\n Continuer d'inisialiser ??");
        scanf("%s", choix);
        i++:
    }while(strcmp(choix,"oui") == 0);

    while(i > 0){

    }
    return 0;
}
