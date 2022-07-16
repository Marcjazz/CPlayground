#include <stdio.h>
#include <stdlib.h>

typedef enum booleen{Vrai, Faux}booleen;
int somme(int n){
    if(n >= 1 && n == 1)
        return 1;
    else
        return n+somme(n-1);
}
booleen rechercheElem(int tab[],int n, int elem){
    while(n > 0 && tab[n-1] != elem){
        n--;
    }
    return n > 0 ;
}
int main()
{
    int tab[] = {2,5,9,0,3,8};
    printf("Hello world!\n%d - %d", somme(7), rechercheElem(tab, 6, 5));
    return 0;
}
