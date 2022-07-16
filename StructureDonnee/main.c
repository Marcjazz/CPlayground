#include <stdio.h>
#include <stdlib.h>
typedef enum booleen{Vrai, Faux}booleen;

typedef struct Arbre{
    int info;
    struct Arbre *f_g;
    struct Arbre *f_d;
}Arbre, Noeud;

void traiterNoeud(Arbre *a){
    printf("%d", a->info);
}
void parcoursPrefixe(Arbre *a){
    if(a != NULL){
        traiterNoeud(a);
        parcoursPrefixe(a->f_g);
        parcoursPrefixe(a->f_d);
    }
}
booleen rechercheInfos(Arbre *a, int valeur){
    if(a == NULL)
        return Faux;
    else if(a->info == valeur)
        return Vrai;
    else if(a->info > valeur)
        return rechercheInfos(a->f_g, valeur);
    else
        return rechercheInfos(a->f_d, valeur);
}
int taille(Arbre *a){
    if(a == NULL){
        return 0;
    }else{
        return (1 + taille(a->f_d) + taille(a->f_g));
    }
}
int max(int a, int b){
    return (a> b)? a: b;
}
int hauteur(Arbre *a){
    if( a == NULL){
        return 0;
    }else{
        return 1 + max(hauteur(a->f_d), hauteur(a->f_g));
    }
}
booleen ajouterInfos(Arbre **a, Noeud *noeud){
    if( (*a) == NULL || (*a)->info == noeud->info){
        return Faux;
    }else if((*a)->f_g == NULL && noeud->info < (*a)->info){
        (*a)->f_g = noeud;
        return Vrai;
    }else if((*a)->f_g != NULL){
        return ajouterInfos((&(*a)->f_g), noeud);
    }else if((*a)->f_d == NULL){
        (*a)->f_d = noeud;
        return Vrai;
    }else{
        return ajouterInfos((&(*a)->f_d), noeud);
    }
}
Arbre *racineMax(Arbre *a){
    if( a->f_d == NULL){
        return a;
    }else{
        return racineMax(a->f_d);
    }
}
booleen supprimeRacine(Arbre **a){
    if((*a) == NULL){
        return Faux;
    }else{
        if( (*a)->f_g == NULL ){
            Noeud *n = (*a);
            (*a) = (*a)->f_d;
            free(n);
        }else if((*a)->f_d == NULL){
            Noeud *n = (*a);
            (*a) = (*a)->f_g;
            free(n);
        }else{
            Noeud *n = racineMax(a->f_g);
            n->f_d = (*a)->f_d;
            n->f_g = (*a)->f_g;
            supprimeRacine((&(*a)->f_g));
        }
        return Vrai;
    }
}
booleen supprimeNoeud(Arbre **a, int valeur){
    if((*a) == NULL){
        return Faux;
    }else if((*a)->info == valeur){
        supprimeRacine(&(*a));
        return Vrai;
    }else if((*a)->info < valeur){
        return supprimeNoeud((&(*a)->f_g), valeur);
    }else{
        return supprimeNoeud((&(*a)->f_d), valeur);
    }
}
