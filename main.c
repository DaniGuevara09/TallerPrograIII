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

void formatNumber() {
    double number;
    char result[MAX_LENGTH];

    printf("Enter a number: ");
    scanf("%lf", &number);

    Format(number, result, sizeof(result));

    printf("Formatted number: %s\n", result);
    getchar();
}

void palindrome() {
    getchar();
    char cadena[MAX_LENGTH];

    printf("Enter a character string: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';

    if (isPalindrome(cadena)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

/**
 * @brief Removes the newline character '\n' from the end of a string.
 *
 * This function searches for the first occurrence of the newline character ('\n') in the given string
 * and replaces it with the null character ('\0'), effectively removing the trailing newline.
 *
 * @param str Pointer to the string to be modified.
 *
 * @return void
 *
 * @example
 * // Input: "Hello world\n"
 * // After calling removeFinal: "Hello world"
 */
void removeFinal(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

/**
 * @brief Finds the position of the last occurrence of a substring within a string.
 *
 * This function prompts the user to enter a main string and a substring. It then searches
 * for the last occurrence of the substring within the main string. If the substring is found,
 * it prints the position of the first character of the last occurrence. If the substring is not found,
 * the position returned is the initial position (0).
 *
 * @note Requires an external function `removeFinal` to remove unwanted trailing characters
 *       from both strings.
 *
 * @param None
 *
 * @return void
 *
 * @example
 * // Input: "This is an example of example"
 * // Substring: "example"
 * // Output: 22 (indicates the position of the last occurrence of "example")
 *
 * // Input: "Hello world"
 * // Substring: "goodbye"
 * // Output: 0 (indicates that the substring was not found)
 */
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

/**
 * @brief Validates if a string contains a balanced number of opening '(' and closing ')' parentheses.
 *
 * This function prompts the user to enter a string and then analyzes it to check if the
 * number of opening parentheses matches the number of closing parentheses.
 * If the string is balanced, the function prints 0; otherwise, it prints 1.
 *
 * @note Requires an external function `removeFinal` to remove unwanted trailing characters from the string.
 *
 * @param None
 *
 * @return void
 *
 * @example
 * // Input: "(a + b) * (c + d)"
 * // Output: 0 (indicates that the parentheses are balanced)
 *
 * // Input: "(a + b))"
 * // Output: 1 (indicates that the parentheses are not balanced)
 */
void validateParentheses() {
    getchar();

    char parentheses[MAX_LENGTH];
    int cont = 0;

    printf("Enter a string: ");
    fgets(parentheses, sizeof(parentheses), stdin);
    removeFinal(parentheses);

    for (int i = 0; i < strlen(parentheses); i++) {
        if (parentheses[i] == '(') {
            cont++;
        } else if (parentheses[i] == ')') {
            cont--;
        }
    }

    if (cont == 0) {
        printf("%d\n", 0);
    } else {
        printf("%d\n", 1);
    }
}

void mainMenu(){
    char option;
    char *menu = "\n<<<<<<<MAIN MENU>>>>>>\n\n"
                 "1. Find the last occurrence of a substring within another string.\n"
                 "6. Format a number.\n"
                 "7. Check if a string is an palindrome.\n"
                 "8. Validate parentheses.\n\n"
                 "X. Exit\n\n"
                 "Please, select an option: ";

    do{
        printf( menu);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1' : posSubstring();
                break;
            case '6' : formatNumber();
                break;
            case '7' : palindrome();
                break;
            case '8' : validateParentheses();
                break;
        }
    }while( toupper(option) != 'X');
}