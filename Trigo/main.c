#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    char name[10];
    float abs_x;
    float ord_y;
}Point, Vecteur;

Point placer_point(Point A){

    printf("Nom du point: ");
    scanf("%s", A.name);

    printf("Entrer les cordonees %s du point:\n X = ", A.name);
    scanf("%f", &A.abs_x);

    printf("\nY = ");
    scanf("%f", &A.ord_y);

    return A;
}

 Point milieu_segment(Point A, Point B){

     Point midle;

     midle.abs_x = (A.abs_x + B.abs_x)/2;
     midle.ord_y = (A.ord_y + B.ord_y)/2;

     return midle;
 }


Vecteur segment(Point A, Point B){

    Vecteur AB;

    AB.abs_x = B.abs_x - A.abs_x;
    AB.ord_y= B.ord_y - A.ord_y;

    return AB;
}

int main()
{
    Point A, B,C, G, I, J;

    //initialisation des poinit formant le triangle
    A = placer_point(A);
    B = placer_point(B);
    C = placer_point(C);

    //soit I, J, K les milieux des segment AB, BC, AC

    I = milieu_segment(A, B);
    J = milieu_segment(B, C);
    //K = milieu_segment(A, C);

    //segments du triangle
    Vecteur AB, BC;
    AB = segment(A, B);
    BC = segment(B, C);
    //AC = segment(A, C);


    //calcul du point de rencontre des medianes

    G.ord_y = (J.abs_x - I.abs_x -(AB.ord_y/AB.abs_x)*I.ord_y
               + (BC.ord_y/BC.abs_x)*J.ord_y)/((BC.ord_y/BC.abs_x)
                - (AB.ord_y/AB.abs_x));
    G.abs_x = I.abs_x -(AB.ord_y/AB.abs_x)*(G.ord_y - I.ord_y);

    printf("\t\t***** RESULTAT *****\n\n");

    //affiche les points et leurs coordonnees
    printf("%s(%.2f; %.2f)\n", A.name, A.abs_x, A.ord_y);
    printf("%s(%.2f; %.2f)\n", B.name, B.abs_x, B.ord_y);
    printf("%s(%.2f; %.2f)\n\n", C.name, C.abs_x, C.ord_y);

    //affiche les milieu de deux segments du triangle
    printf("Milieu de %s%s: I(%.2f; %.2f)\n", A.name, B.name, I.abs_x, I.ord_y);
    printf("Milieu de %s%s: J(%.2f; %.2f)\n\n", B.name, C.name, J.abs_x, J.ord_y);

    //calcul du rayon du cerlce par rapport a A
    float x = pow((G.abs_x - A.abs_x), 2);
    float y = pow((G.ord_y - A.ord_y), 2);
    float rayon = sqrt(x + y);
    printf("Distance O%s = %f\n", A.name,  rayon);

    //calcul du rayon du cerlce par rapport a B
    x = pow((G.abs_x - B.abs_x), 2);
    y = pow((G.ord_y - B.ord_y), 2);
    rayon = sqrt(x + y);
    printf("Distance O%s = %f\n", B.name,  rayon);

    //calcul du rayon du cerlce par C
    x = pow((G.abs_x - C.abs_x), 2);
    y = pow((G.ord_y - C.ord_y), 2);
    rayon = sqrt(x + y);
    printf("Distance O%s = %f\n\n", C.name,  rayon);

    //point intersertion ou centre du cercle circoncrit
    printf("\t\t*******Centre du cercle circonscrit: O(%2f; %2f)*********\n",
            G.abs_x, G.ord_y);

    return 0;
}
