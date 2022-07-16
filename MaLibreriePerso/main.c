#include <stdio.h>
#include <stdlib.h>
#include "Lire.h"

int main()
{
    char nom[20]; long l;
    printf("Hello world!\nWhat are your names : ");
    lire("%d", nom);
    printf("Hello %s enter a number:", nom);
    return 0;
}
