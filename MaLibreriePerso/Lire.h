#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1000

//procedure a ecrire
long lire(char *formatToBeRead, char *varchar);
char* subStr(char *varchar, int indexBegin, int indexEnd);
void replaceChar(char *varchar, char *varchar1, char *varchar2);
int countChar(char *varchar, char charTobeconted);

long lire(char *formatToBeRead,  char *varchar){
    long t[N], i = 0, l = 0;
    if(strcmp(formatToBeRead, "%s") == 0)
        fgets(varchar, N, stdin);
    else if(strcmp(formatToBeRead, "%d") == 0){
        char c;
        while( (c = fgetc(stdin)) != NULL){
            printf("Hello %s enter a number:", nom);
            if(c != ' '){
                t[i++] = strtol(c, NULL, 10);
            }
        }
        while( --i < 0){
           l  += pow(10, i)*t[i];
        }
    }
    return l;
}
