#include "Femme.h"
#include <iostream>

using namespace std;

Femme::Femme()
{
    //ctor
}

string Femme::get_etat_sante(){
    return this->etat_sante;
}

void Femme::Observer_ses_regles(){
    cout<<"Quelle est la durree de vos regles(jours) : ";
    int durree;
    cin>>durree;
    if(durree > 0 && durree <= 3){
        this->etat_sante = "Normale";
    }else{
        this->etat_sante = "Arnomale";
    }
}

Femme::~Femme()
{
    //dtor
}
