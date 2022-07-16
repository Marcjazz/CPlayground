#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point A, B,C, D, S;
    Point tab_point[] = { A, B, C, D};

    for(int i = 0; i < 4; i++){
        tab_point[i].init_point();
        S = S +(tab_point[i]);
    }


    cout<<"AFFICHONS LES POINTS "<<endl;
    for(int i = 0; i < 4; i++){
        tab_point[i].affiche_point();
    }
    S.affiche_point();
    return 0;
}
