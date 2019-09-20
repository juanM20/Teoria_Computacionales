#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char rango[3],p;
    int a = 0, b = 0;

    printf("Escribe rango: ");
    scanf("%s",rango);

    a = rango[0];
    b = rango[2];

    printf("\nRango: %c %c %c",rango[0],rango[1],rango[2]);
    printf("\nRango: %d %c %d  total: %d",a,rango[1],b, (b-a)+1);

    p = 97;
    printf("\nLetra: %c",p);
    
    return 0;
}