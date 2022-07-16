#include <stdio.h>
#include <stdlib.h>

int somme(int n){
    if(n >= 1 && n == 1)
        return 1;
    else
        return n+somme(n-1);
}
int main(){
    somme(8);
}
