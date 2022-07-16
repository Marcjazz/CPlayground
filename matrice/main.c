#include <stdio.h>
#include <stdlib.h>

void initMatrice(int matrice[2][2], int ligne_length, int col_length){
    int i, j;
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            printf("\n Entrer un nombre[%d][%d] ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void afficheMatrice(int matrice[2][2], int ligne_length, int col_length){
    int i, j;
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            printf("\n matrice[%d][%d] = %d", i, j, matrice[i][j]);
        }
    }
}

int sommeMatrice(int matrice1[2][2], int matrice2[2][2],int matriceSomme[2][2], int ligne_length, int col_length){
    int i, j;

    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            matriceSomme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    return matriceSomme;
}

int main()
{
    int matrice1[2][2], matrice2[2][2], matriceSomme[2][2];
    printf("\n ****Initialisation de la matrice 1***");
    initMatrice(matrice1, 2,2);
    printf("\n ****Initialisation de la matrice 2***");
    initMatrice(matrice2, 2,2);
    printf("\n ****Affichage de la matrice 1***");
    afficheMatrice(matrice1, 2, 2);
    printf("\n\n ****Affichage de la matrice 2***");
    afficheMatrice(matrice2, 2, 2);
    printf("\n\n ****Affichage de la matrice Somme***");
    afficheMatrice(sommeMatrice(matrice1, matrice2,matriceSomme, 2,2), 2, 2);
}
