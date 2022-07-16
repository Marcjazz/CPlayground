#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
    this->abcisse = this->ordonnee = 0;

}

void Point::init_point(){
    cout<<"Entrer l'abcisse de votre point:"<<endl;
    cin>>this->abcisse;
    cout<<"Entrer l'ordonnee de votre point:"<<endl;
    cin>>this->ordonnee;
}

void Point::affiche_point(){
    cout<<"COODONNEES DU POINT\nP("<<abcisse<<";"<<ordonnee<<")\n"<<endl;
}

Point Point::operator+(Point A){
    Point B;
    B.abcisse = A.abcisse + abcisse;
    B.ordonnee = A.ordonnee + ordonnee;

    return B;
}

Point::~Point()
{
    //dtor
}
