#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
    public:
        Point();
        void affiche_point();
        void init_point();
        Point operator+(Point);
        virtual ~Point();

    protected:

    private:
        float abcisse;
        float ordonnee;
};

#endif // POINT_H
