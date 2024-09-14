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

void removeFinal(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

void posSubstring() {
    getchar();
    char fullString [MAX_LENGTH];
    char substring [30];

    printf("Enter a string: ");
    fgets(fullString, sizeof(fullString), stdin);

    printf("Enter a substring: ");
    fgets(substring, sizeof(substring), stdin);

    removeFinal(fullString);
    removeFinal(substring);

    int pos = 0;
    int cant = 0;
    int i = 0;

    for (int j = 0; j < strlen(fullString); j++) {
        if (substring[i] == fullString[j]) {
            i++;
            cant++;

            if (i == strlen(substring)) {
                i = 0;
                cant = 0;
                pos = (j - strlen(substring)) + 1;
            }
        }
    }

    printf("%d\n", pos);
}

void mainMenu(){
    char option;
    char *menu = "\n<<<<<<<MAIN MENU>>>>>>\n\n"
                 "1. Find the last occurrence of a substring within another string.\n"
                 "6. Format a number.\n"
                 "7. Check if a string is an palindrome.\n\n"
                 "X. Exit\n\n"
                 "Please, select an option: ";

    do{
        printf( menu);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1' : posSubstring();
                break;
            case '6' : FormatNumber();
                break;
            case '7' : Palindrome();
                break;
        }
    }while( toupper(option) != 'X');
}