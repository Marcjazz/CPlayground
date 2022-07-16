#include <string>
#ifndef ETUDIANT_H
#define ETUDIANT_H
using namespace std;

class Etudiant
{
    public:
        Etudiant();
        float calcul_moyenne();
        string get_nom();
        friend void ordre(Etudiant, Etudiant);
        virtual ~Etudiant();


    private:
        float note[5];
        string nom;
};

#endif // ETUDIANT_H
