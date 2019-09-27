#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char boolean;
#define TRUE 1
#define FALSE 0

int Valor_Absoluto(int n){
    if(n < 0) 
        return -1*n;
    else
        return n;
}

void Uno_Uno(int numero_de_simbolos, char *alfabeto){

    for(int i=0; i<numero_de_simbolos; i++){
        getchar();
        printf("simbolo %d: ",i+1);
        scanf("%c",&alfabeto[i]);
    }
}


void Rango(char *alfabeto, char *rango){

    int j=0, a=rango[0], b=rango[2];

    for(int i=a; i<=b; i++){
        alfabeto[j] = i;
        j++; 
    }
}


void Leer_Alfabeto(int numero_de_simbolos, char *alfabeto){

    for(int i=0; i<numero_de_simbolos; i++)
        printf("%c - ",alfabeto[i]);
}

boolean Buscar_Simbolo(char simbolo, char *alfabeto){
    
    boolean r = FALSE;

    for(int i=0; i<strlen(alfabeto); i++){
        if(simbolo == alfabeto[i]){
            r = TRUE;
            break;
        }   
    }

    return r;
}

boolean Validar_Cadena(char *cadena, char *alfabeto){
    
    boolean r = TRUE;

    for(int i=0; i<strlen(cadena); i++){
        if(!Buscar_Simbolo(cadena[i],alfabeto)){
            r = FALSE;
            break;
        }
    }

    return r;
}

void Concatenar(char *cadena1, char *cadena2, char *concat, int n){

    if(n > 0){
        
        strcpy(concat,cadena1);
        strcat(concat,cadena2);
        for(int i=0; i<n-1; i++){
            strcat(concat,cadena1);
            strcat(concat,cadena2);
        }
    }else if(n < 0){

        strcpy(concat,cadena2);
        strcat(concat,cadena1);
        for(int i=0; i<Valor_Absoluto(n)-1; i++){
            strcat(concat,cadena2);
            strcat(concat,cadena1);
        }

    }else{
        printf("El resultado es la cadena vacia.");
    }

}

int Concurrencia(char *cadena, char concurr){

    int cant=0;

    for(int i=0; i<strlen(cadena); i++){
        if(cadena[i] == concurr)
            cant++;
    }

    return cant;
}



int main(){

    int numero_de_simbolos=0, opc=0;
    char rango[3], *alfabeto1=NULL, *alfabeto2=NULL;

    char cadena1[100], cadena2[100];

    printf("Practica 1: Manejo de alfabetos y operaciones en palabra.\n");

    printf("Agregar:\n1. De unno en uno.\n2. Rango.\n");
    
    printf("Elige opcion: ");
    scanf("%d",&opc);

    switch(opc){

        case 1:
                printf("\nCuantos simbolos tendra tu alfabeto: ");
                scanf("%d", &numero_de_simbolos);

                if(numero_de_simbolos < 3){
                    printf("\nNecesitas mas simbolos.\nSe asignara el numero predeterminado de simbolos.\nSe asiganara un total de 3.");
                    numero_de_simbolos = 3;
                }

                alfabeto1 = (char *)malloc(sizeof(char)*numero_de_simbolos);

                Uno_Uno(numero_de_simbolos,alfabeto1);

                printf("\n\nAlfabeto I\n");
                Leer_Alfabeto(numero_de_simbolos,alfabeto1);
    
                break;

        case 2:
                printf("Elige el rango de tu alfabeto: ");
                scanf("%s",rango);

                numero_de_simbolos = rango[2]-rango[0];
                alfabeto1 = (char *)malloc(sizeof(char)*numero_de_simbolos+1);

                Rango(alfabeto1,rango);

                printf("\n\nAlfabeto I\n");
                Leer_Alfabeto(numero_de_simbolos+1,alfabeto1);
    
                break;

        default:
                printf("Error: No existe opcion.");
                break;
    }

    
    printf("\n\nPractica 2: Verificar si la cadena que se escriba es Válida");
    getchar();
    
    do{
        printf("\nIngresa la primera cadena: ");
        scanf("%s",cadena1);
    }while(!Validar_Cadena(cadena1,alfabeto1));


    do{
        printf("\nIngresa la segunda cadena: ");
        scanf("%s",cadena2);
    }while(!Validar_Cadena(cadena2,alfabeto1));
    

    printf("\n\nPractica 3: Concatenacion y concurrencias");

    int n=0;
    char *concat = NULL, concurr;
    printf("\nIngresa el numero N: ");
    scanf("%d",&n);

    concat = (char *)malloc( ( sizeof(char) ) * ( ( strlen(cadena1)+strlen(cadena2) ) * Valor_Absoluto(n) ) );

    Concatenar(cadena1,cadena2,concat,n);

    printf("\n%s",concat);

    getchar();
    printf("\nEscribe el simbolo que quieres ver su concurrencia: ");
    scanf("%c",&concurr);

    printf("\n|w1 sub %c| =  %d",concurr, Concurrencia(cadena1, concurr) );


    return 0;
}