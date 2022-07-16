#include<stdio.h>

char* nombre_elementaire(int nombre){

    switch(nombre){
        case 0: return "zero";
        case 1: return "un";
        case 2: return "deux";
        case 3: return "trois";
        case 4: return "quatre";
        case 5: return "cinq";
        case 6: return "six";
        case 7: return "sept";
        case 8: return "huit";
        case 9: return "neuf";
        case 10: return "dix";
        case 11: return "onze";
        case 12: return "douze";
        case 13: return "triese";
        case 14: return "quatorse";
        case 15: return "quize";
        case 16: return "seize";
        case 17: return "dix-sept";
        case 18: return "dix-huit";
        case 19: return "dix-neuf";
    }
}

char* dix_centaine(int nbre){

    int result = nbre /10;
    switch(result){

        case 0: return nombre_elementaire(nbre);
        case 1: return nombre_elementaire(nbre);
        case 2:return "vingt";
        case 3: return "trente";
        case 4: return "quarante";
        case 5: return "cinq";
        case 6: return "soixante";
        case 7: return "soixante-dix";
        case 8: return "quatre-vingt";
        case 9: return "quatre-vingt-dix";
    }
}

void implement_dix(int nbre){
    int quotient = (nbre/10)*10;
    printf(" %s ", dix_centaine(nbre));
    do{
        nbre = nbre - quotient;
        if(nbre != 0)
            printf(" %s", dix_centaine(nbre));
    }while(nbre > 0);
}

void implement_cent(int nbre){
    int quotient = nbre/100, myVar = nbre - quotient*100;

    if(nbre >= 100){
        printf("%s cent", dix_centaine(quotient));
        if(myVar < 10){
            if(myVar != 0)
                printf(" %s ", nombre_elementaire(myVar));
        }else{
            implement_dix(myVar);
        }
    }else if(nbre >= 10){
        implement_dix(myVar);
    }else{
        dix_centaine(myVar);
    }
}

void implement_mille(int nbre){
    int quotient =  nbre/1000, myVar = nbre - quotient*1000;

    if(quotient < 20)
        printf(" %s ", dix_centaine(quotient));
    else if(quotient < 100)
        implement_dix(quotient);
    else implement_cent(quotient);

    if(nbre >= 1000){
        printf(" mille ");
    }
    implement_cent(myVar);
}

void implement_million(int nbre){
    int quotient =  nbre/1000000, myVar = nbre - quotient*1000000;
    implement_mille(quotient);
    if(nbre >= 1000000){
        printf(" million ");
    }
    implement_mille(myVar);
}




void main () {
    int nbre, quotient = 0, myVar;
    printf("Entrer un nombre: ");
    scanf("%d", &nbre);

    if(nbre >= 0 && nbre < 20){
      printf("%d : %s", nbre, nombre_elementaire(nbre));
    }
    else if(nbre >= 20 && nbre < 100){
        printf("%d :", nbre);
        implement_dix(nbre);
    }else if(nbre >= 100 && nbre < 1000){
        printf("%d: ", nbre);
        implement_cent(nbre);
    }else if(nbre >= 1000 && nbre < 1000000){
        printf("%d: ", nbre);
        implement_mille(nbre);
    }else if( nbre >= 1000000 && nbre < 1000000000){
        printf("%d: ", nbre);
        implement_million(nbre);
    }
    printf(" FCFA");
}
