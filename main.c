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
    double number;
    char result[MAX_LENGTH];

    printf("Enter a number: ");
    scanf("%lf", &number);

    Format(number, result, sizeof(result));

    printf("Formatted number: %s\n", result);
    getchar();
}

void Palindrome() {
    char cadena[MAX_LENGTH];

    printf("Enter a character string: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    if (isPalindrome(cadena)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    getchar();
}

void mainMenu(){
    char option;
    char *menu = "<<<<<<<MAIN MENU>>>>>>\n\n"
                 "6. Format a number.\n"
                 "7. Check if a string is an palindrome.\n\n"
                 "X. Exit\n\n"
                 "Please, select an option: ";

    do{
        printf( menu);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '6' : FormatNumber();
                break;
            case '7' : Palindrome();
                break;
        }
    }while( toupper(option) != 'X');
}