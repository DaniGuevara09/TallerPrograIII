#include <stdio.h>
#include "tools.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void mainMenu();

int main(void) {
    mainMenu();
    return 0;
}

/**
 * @author Nicolas Rojas
 *
 * @brief Prompts the user to enter a number, formats it, and prints it.
 *
 * This function prompts the user to input a floating-point number (double),
 * formats the number using the Format function, and then prints the formatted number.
 *
 * @param none No input parameters.
 *
 * @return void This function does not return any value.
 *
 */
void formatNumber() {
    double number;
    char result[MAX_LENGTH];

    printf("Enter a number: ");
    scanf("%lf", &number);

    Format(number, result, sizeof(result));

    printf("Formatted number: %s\n", result);
    getchar();
}

/**
 * @author Nicolas Rojas
 *
 * @brief Checks if the entered string is a palindrome.
 *
 * This function prompts the user to input a string of characters,
 * removes the newline character, and then uses the isPalindrome function
 * to check if the string is a palindrome. It prints the result of the check.
 *
 * @param none No input parameters.
 *
 * @return void This function does not return any value.
 *
 */

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

/**
 * Responsible Marlon Delgado
 * Method that capitalizes the first letter of each word in a string, except for single-character words.
 * @return void
 *
 * This method reads a line of text from the standard input, processes the string to capitalize
 * the first letter of each word, and prints the resulting capitalized text.
 *
 * A word is defined as a sequence of alphabetic characters separated by non-alphabetic characters
 * (e.g., spaces, punctuation). Single-character words are not capitalized.
 */
void capitalizeString() {
    char str[1000];

    printf("Enter the text: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    int inWord = 0;

    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            if (!inWord) {
                if (i == 0 || !isalpha(str[i - 1]) || str[i - 1] == ' ') {
                    if (str[i + 1] != '\0' && !isalpha(str[i + 1]) && str[i + 1] != ' ') {
                        str[i] = tolower(str[i]);
                    } else {
                        str[i] = toupper(str[i]);
                    }
                }
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        i++;
    }
    printf("Capitalized text: %s", str);
}

/**
 * Responsible Marlon Delgado
 * Method that reads a string from the input, splits it into an array of character strings based on spaces,
 * prints each word, and handles memory allocation and deallocation.
 * @return void
 *
 * This method reads a line of text from the standard input, splits it into individual words
 * based on spaces, prints each word, and handles all memory management internally.
 * The function dynamically allocates memory for the array and the individual strings, and then
 * frees this memory after use.
 */
void splitString() {
    char input[1000]; ///< Buffer to hold the input string. Adjust the size as needed.

    // Read a line of text from the standard input
    printf("Enter the text: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Count the number of words in the input string
    int wordCount = 1; // Start with 1 as there's at least one word
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            wordCount++;
        }
    }

    // Allocate memory for the array of pointers to strings
    char** words = (char**)malloc(wordCount * sizeof(char*));
    if (words == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Copy words into the array
    int index = 0;
    char* temp = strdup(input);
    if (temp == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    char* token = strtok(temp, " ");
    while (token != NULL) {
        words[index] = strdup(token);
        if (words[index] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        index++;
        token = strtok(NULL, " ");
    }

    free(temp); // Free the temporary string buffer

    // Print the split strings
    for (int i = 0; i < wordCount; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
        free(words[i]); // Free each string
    }
    free(words); // Free the array of pointers
}

void mainMenu(){
    char option;
    char *menu = "\n<<<<<<<MAIN MENU>>>>>>\n\n"
                 "1. Find the last occurrence of a substring within another string.\n"
                 "2. Capitalize a text string.\n"
                 "3. Split a string into a character array.\n"
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
            case '2' : capitalizeString();
                break;
            case '3' : splitString();
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