#include <iostream>
#include "Humaine.h"
#include "Femme.h"
#include <string.h>

using namespace std;

int main()
{
    Humaine humaine_a;
    cout<<"Vos avez "<<humaine_a.calcul_age()<<endl;
    humaine_a.set_sexe();
    if(humaine_a.get_sexe() == 'f'){
        Femme femme_a;
        femme_a.Observer_ses_regles();
        cout<<"vous etes une femme et votre etat de sante est: "<<femme_a.get_etat_sante()<<endl;
    }else{
        cout<<"Desole un homme n'a pas de regles"<endl;
    }

    return 0;
}
