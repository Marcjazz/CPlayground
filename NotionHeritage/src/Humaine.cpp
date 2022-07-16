#include <iostream>
#include "Humaine.h"
#include <iostream>

using namespace std;

Humaine::Humaine()
{
    cout<<"Entrer votre nom: ";
    cin>>this->nom;
    cout<<"Entrer votre annee de naissance: ";
    cin>>this->annee_de_naissance;
}

int Humaine::calcul_age(){
    return 2021 - annee_de_naissance;
}

void Humaine::set_sexe(){
    cout<<"De quel etes vous ?(m/f) : ";
    cin>>this->sexe;
}
char Humaine::get_sexe(){
    return this->sexe;
}

string Humaine::get_nom(){
    return this->nom;
}

Humaine::~Humaine()
{
    //dtor
}
