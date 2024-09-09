#include <stdio.h>
#include "tools.h"
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void mainMenu();

int main(void) {
    mainMenu();
    return 0;
}

void FormatNumber() {
    double numero;
    char resultado[MAX_LENGTH];

    printf("Digite un numero: ");
    scanf("%lf", &numero);

    Formatear(numero, resultado, sizeof(resultado));

    printf("Numero formateado: %s\n", resultado);
    getchar();
}

void Palindromo() {
    char cadena[MAX_LENGTH];

    printf("Digite una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    if (isPalindrome(cadena)) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }

    getchar();
}

void mainMenu(){
    char option;
    char *menu = "<<<<<<<MENU PRINCIPAL>>>>>>\n\n"
                 "6. Formatear un valor numerico.\n"
                 "7. Comprobar si una cadena es un palindromo.\n\n"
                 "X. Salir\n\n"
                 "Digite su Opcion: ";

    do{
        printf( menu);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '6' : FormatNumber();
                break;
            case '7' : Palindromo();
                break;
        }
    }while( toupper(option) != 'X');
}