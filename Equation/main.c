#include <stdio.h>
#include <stdlib.h>

int saisir_entier(){
    int *p,result;
    if((p = (int*)malloc(sizeof(int))) == NULL)
        printf("Ereur au niveau saisir_entier : alocation de l'espace memoire");
    else{
        printf("entrer l'entier : ");
        scanf("%d", p);
        result = *p;
        free(p);
    }
    return result;
}
void saisir_int(int **result){
    int *p;
    if((p = (int*)malloc(sizeof(int))) == NULL)
        printf("Erreur au niveau saisir_entier : alocation de l'espace memoire");
    else{
        printf("entrer l'entier : ");
        scanf("%d", *p);
        *result = p;
        free(p);
    }
}

int main()
{
    int *x;
    printf("resultat = %d\n",saisir_entier());
    saisir_int(&x);
    printf("Avec void on obtient, resultat = %d\n",*x);
    return 0;
}
