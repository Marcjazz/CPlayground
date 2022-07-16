#include <iostream>

using namespace std;

void initMatrice(int matrice[2][2], int ligne_length, int col_length){
    int i, j;
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            cout<<"\n Entrer un nombre["<<i<<"]["<<j<<"] ";
            cin >>matrice[i][j];
        }
    }
}

void afficheMatrice(int matrice[2][2], int ligne_length, int col_length){
    int i, j;
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            cout<<"\n matrice["<<i<<"]["<<j<<"] = "<<matrice[i][j]<<endl;
        }
    }
}

void sommeMatrice(int matrice1[2][2], int matrice2[2][2],int matriceSomme[2][2], int ligne_length, int col_length){
    int i, j;
    //calcul de la somme
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            matriceSomme[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    //afiche la somme
    for(i = 0; i < ligne_length; i++){
        for(j = 0; j < col_length; j++){
            cout<<"\n matrice["<<i<<"]["<<j<<"] = "<<matriceSomme[i][j]<<endl;
        }
    }
}

int main()
{
    int matrice1[2][2], matrice2[2][2], matriceSomme[2][2];
    cout<<"\n ****Initialisation de la matrice 1***"<<endl;
    initMatrice(matrice1, 2,2);
    cout<<"\n ****Initialisation de la matrice 2***"<<endl;
    initMatrice(matrice2, 2,2);
    cout<<"\n ****Affichage de la matrice 1***"<<endl;
    afficheMatrice(matrice1, 2, 2);
    cout<<"\n\n ****Affichage de la matrice 2***"<<endl;
    afficheMatrice(matrice2, 2, 2);
    cout<<"\n\n ****Affichage de la matrice Somme***"<<endl;
    sommeMatrice(matrice1, matrice2,matriceSomme, 2,2);


    return 0;
}
