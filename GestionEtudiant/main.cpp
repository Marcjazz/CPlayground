#include <string>
#include <iostream>
#include "Etudiant.h"


using namespace std;

void ordre(Etudiant a, Etudiant b){
    if(a.calcul_moyenne() >= b.calcul_moyenne()){
        cout<<"le premier est "<<a.get_nom()<<endl;
        cout<<"le deuxieme est" <<b.get_nom()<<endl;
    }else{
        cout<<"le premier est" <<b.get_nom()<<endl;
        cout<<"le deuxieme est "<<a.get_nom()<<endl;
    }
}

int main()
{
    Etudiant etudiant_a;
    Etudiant etudiant_b;

    cout<<" **** RESULTAT ****"<<endl;
    ordre(etudiant_a, etudiant_b);


    return 0;
}
