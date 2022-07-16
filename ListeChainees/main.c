#include <stdio.h>
#include <stdlib.h>

typedef struct Liste {
    int info ;
    struct Liste *suiv ;
}Liste, Cellule ;
typedef enum booleen {Vrai,Faux} booleen;

/****************************************/
void insertTete(Liste **l, Cellule *c){
    if(c != NULL){
        c->suiv = (*l);
        (*l) = c;
    }
}

Liste *initialisation(){
    Liste * liste = malloc(sizeof(*liste));
    if(liste != NULL){
        printf("Entrer une valeur : ");
        scanf("%d", liste->info);
        liste->suiv = NULL;
    }
    return liste;
}

void insertFin(Liste **l, Cellule *c){
    if((*l) == NULL){
        insertTete(*l, c);
    }else if(((*l)->suiv == NULL)){
        (*l)->suiv = c;
    }else{
        insertFin((&(*l)->suiv), c);
    }
}

booleen insertK(Liste **l, Cellule *c, unsigned int k){
    if(c != NULL){
        if((*l) == NULL && k > 0){
            return Faux;
        }else if(k == 1){
            insertFin(l,c);
            return Vrai;
        }else{
            insertK((&(*l)->suiv), c, --k);
        }
    }
}

booleen supprimeTete(Liste ** l){
    Cellule *n;
    if((*l) == NULL){
        return Faux;
    }else{
        n = *l;
        *l = (*l)->suiv;
        free(n);
        return Vrai;
    }
}
booleen supprimeFin(Liste **l){
    if((*l) != NULL && (*l)->suiv == NULL){
        return supprimeTete(&(l));
    }else{
        return supprimeFin(&(*l)->suiv);
    }
}
booleen supprimeK(Liste ** l, unsigned int k){
    if((*l) == NULL && k > 0){
        return Faux;
    }else if(k == 1){
        supprimeFin(&(*l));
        return Vrai;
    }else{
        supprimeK((&(*l)->suiv), --k);
    }
}
void afficheListe(Liste *l){
    if(l != NULL){
        printf("%d %d\n", l->info, l->suiv);
        afficheListe(l->suiv);
    }
}
Liste *dernierPointeur(Liste *l){
     if( l != NULL && l->suiv == NULL && ((l->suiv)->suiv) == NULL){
        return (l->suiv);
    }else{
        return dernierPointeur(l->suiv);
    }
}
int main () {
    int i, n, x, y, airX, air;
    const N = 10000000;
    n = 0;
    srand(time(NULL));
    for(i= 0; i < N; i++){
        x = rand()%5;
        y = rand()%13;
        airX = (float)(x*x/4) + 2*x;
        if(y <= airX){
            n++;
        }
    }
    air = (float) (n*4*12/N);
    printf("L 'air = %d et %d sur %d", air, n, N);
    return 0;
}
