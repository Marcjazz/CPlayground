#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Pi 3.14


typedef enum Booleen{ vrai, faux }Booleen;

typedef struct Point{
    double x;
    double y;
}Point;
typedef struct Cercle{
    Point O;
    double r;
}Cercle;

double SurfaceCercle( double r){
     return r*r*Pi;
 }
Booleen CercleNeSeTouchePas(Cercle C, Cercle c){
    enum Booleen cercleNeTouche = faux;
    double distance;
    distance = sqrt(pow((C.O.x - c.O.x), 2) + pow((C.O.y - c.O.y), 2));
    if( distance >= C.r + c.r){
        cercleNeTouche = vrai;
    }
    return cercleNeTouche;
}
Cercle cercleDisjoint(Cercle tab[],int n, Cercle D){
    int i,j = 0; Cercle tabDisjoint[20];
    for(i = 0; i < n; i++){
        if( CercleNeSeTouchePas(tab[i], D)){
            tabDisjoint[j] = tab[i];
            j++;
        }
    }
    do{
        j--;
        return tabDisjoint[j];
    }while( j > 0);
}


int main()
{
    Cercle C,c;
    C.r = 3; c.r = 4;
    C.O.x = 5; c.O.x =-5; C.O.y = 2; c.O.y = -2;
    printf("\n%f\n%f\n%s",SurfaceCercle(C.r), SurfaceCercle(c.r), CercleNeSeTouchePas(C, c));
char chaine1[]="banane"; char chaine2[]="toto";
int resultat=strcpy(chaine1,chaine2);
printf("chaine1 = %s",chaine1);

    return 0;
}
