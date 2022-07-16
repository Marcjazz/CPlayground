#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point{
    double x;
    double y;
}Point;
typedef struct Vecteur{
    Point O;
    Point M;
}Vecteur;
// fonction qui retourne l'abscisse du vecteur v
double getAbscisse(Vecteur v){
    return (v.M.x - v.O.x);
}
double getOrdonnee(Vecteur v){
    return (v.M.y - v.O.y);
} // fonction qui retourne l'ordonnée du vecteur v

void EquationDroiteVDirecteur( Point A, Vecteur V){
    double a, b, c;
    a = getOrdonnee(V);
    b = -getAbscisse(V);
    c = getAbscisse(V)* A.x - getOrdonnee(V)*A.y;

    printf("\nL'equation est (D): %.2fx +%.2fy +%.2f = 0", a, b, c);

}
void EquationDroiteVNormal( Point A, Vecteur V){
    double a, b, c;
    a = getAbscisse(V);
    b = getOrdonnee(V);
    c = -( getAbscisse(V)*A.x + getOrdonnee(V)*A.y);

    printf("\nL'equation est (D): %.2fx +%.2fy +%.2f = 0", a, b, c);
}

int main()
{
    Point A; Vecteur v;
    A.x = 5; A.y = 0;
    v.M.x = 5; v.O.x =-5; v.M.y = 2; v.O.y = -2;
    EquationDroiteVDirecteur(A, v);
    EquationDroiteVNormal(A, v);
    return 0;
}
