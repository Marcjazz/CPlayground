#ifndef FEMME_H
#define FEMME_H
#include "Humaine.h"
#include <string>

using namespace std;

class Femme : public Humaine
{
    public:
        Femme();
        string get_etat_sante();
        void Observer_ses_regles();
        virtual ~Femme();

    protected:

    private:
        string etat_sante;
};

#endif // FEMME_H
