#ifndef HUMAINE_H
#define HUMAINE_H
#include <string>

using namespace std;

class Humaine
{
    public:
        Humaine();
        string get_nom();
        void set_sexe();
        char get_sexe();
        int calcul_age();

        virtual ~Humaine();

    protected:
        string nom;
        char sexe;
        int annee_de_naissance;
    private:
};

#endif // HUMAINE_H
