#include "Etudiant.h"
#include <string>
#include <iostream>
using namespace std;

Etudiant::Etudiant()
{
        cout<< "Entrer le nom de l etudiant" <<endl;
        cin >>this->nom;
        //cout <<"entrer les notes" <<endl;
        for(int i = 0 ; i <= 4 ; i++){
            cout <<"Entrer la note"<< i+1 <<endl;
            cin >> this->note[i];
        }
    }
    float Etudiant::calcul_moyenne(){
        float somme = 0;
        for(int i = 0 ; i <= 4 ; i++){
            somme += this->note[i];
        }
        return somme / 5;
}

string Etudiant::get_nom(){
    return this->nom;
}



Etudiant::~Etudiant()
{
    //dtor
}

