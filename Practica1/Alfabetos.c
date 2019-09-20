 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

void Uno_Uno(int numero_de_simbolos, char *alfabeto){

    for(int i=0; i<numero_de_simbolos; i++){
        getchar();
        printf("simbolo %d: ",i+1);
        scanf("%c",&alfabeto[i]);
    }
}


void Rango(int numero_de_simbolos, char *alfabeto, char *rango){

    int a = rango[0], b = rango[2], j=0;
    
    if(numero_de_simbolos < (b-a)+1 ){
        printf("Error: Son mas simbolos de los que se especificaron.\nSe agregaran los primeros %d.",numero_de_simbolos);
        for(int i=a; i<=(a+numero_de_simbolos)-1 ; i++){
            alfabeto[j] = i;
            j++;
        }
    }
    else if(numero_de_simbolos == (b-a)+1){
        for(int i=a; i<=b; i++){
            alfabeto[j] = i;
            j++;
        }
    }
    else{
        printf("\nSe pueden insertar mas simbolos pero se asignara el rango previamente definido.");
        for(int i=a; i<=b; i++){
            alfabeto[j]=i;
            j++;
        }
    }

}


void Leer_Alfabeto(int numero_de_simbolos, char *alfabeto){

    for(int i=0; i<numero_de_simbolos; i++)
        printf("%c - ",alfabeto[i]);
}


int main(){

    int numero_de_simbolos=0, opc=0;
    char rango[3], *alfabeto1=NULL, *alfabeto2=NULL;

    printf("Practica 1: Manejo de alfabetos y operaciones en palabra.\n");

    printf("\nCuantos simbolos tendra tu alfabeto: ");
    scanf("%d", &numero_de_simbolos);

    if(numero_de_simbolos < 3){
        printf("\nNecesitas mas simbolos.\nSe asignara el numero predeterminado de simbolos.\nSe asiganara un total de 3.");
        numero_de_simbolos = 3;
    }

    alfabeto1 = (char *)malloc(sizeof(char)*numero_de_simbolos);

    printf("Agregar:\n1. De unno en uno.\n2. Rango.\n");
    
    printf("Elige opcion: ");
    scanf("%d",&opc);

    switch(opc){

        case 1:
                Uno_Uno(numero_de_simbolos,alfabeto1);
                break;

        case 2:
                printf("Elige el rango de tu alfabeto: ");
                scanf("%s",rango);
                Rango(numero_de_simbolos,alfabeto1,rango);
                break;

        default:
                printf("Error: No existe opcion.");
                break;
    }

    printf("\n\nAlfabeto I\n");
    Leer_Alfabeto(numero_de_simbolos,alfabeto1);
    
    printf("\n\nAhora definiremos un segundo Alfabeto II");

    printf("\nCuantos simbolos tendra tu alfabeto: ");
    scanf("%d", &numero_de_simbolos);

    if(numero_de_simbolos < 3){
        printf("\nNecesitas mas simbolos.\nSe asignara el numero predeterminado de simbolos.\nSe asiganara un total de 3.");
        numero_de_simbolos = 3;
    }

    alfabeto2 = (char *)malloc(sizeof(char)*numero_de_simbolos);

    printf("Agregar:\n1. De unno en uno.\n2. Rango.\n");
    
    printf("Elige opcion: ");
    scanf("%d",&opc);

    switch(opc){

        case 1:
                Uno_Uno(numero_de_simbolos,alfabeto2);
                break;

        case 2:
                printf("Elige el rango de tu alfabeto: ");
                scanf("%s",rango);
                Rango(numero_de_simbolos,alfabeto2,rango);
                break;

        default:
                printf("Error: No existe opcion.");
                break;
    }

    printf("\n\nAlfabeto II\n");
    Leer_Alfabeto(numero_de_simbolos,alfabeto2);
    

    return 0;
}