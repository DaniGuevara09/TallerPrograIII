#include <stdio.h>
#include "tools.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 400
void mainMenu();

int main(void) {
    mainMenu();
    return 0;
}




/**
 * @author Julian Arias
 *
 * @brief Replaces spaces in a user-provided string with a chosen separator.
 *
 * This function prompts the user to input a full string of text and a separator character.
 * It replaces every space in the string with the separator provided by the user,
 * avoiding a separator at the end of the resulting string. The resulting string is dynamically
 * allocated and should be freed by the caller.
 *
 * @param none No input parameters.
 *
 * @return char* Returns a dynamically allocated string where spaces have been replaced
 *         by the user-chosen separator. Returns NULL in case of memory allocation failure.
 */



char* joinStringsWithInput() {
    char inputString[MAX_LENGTH];
    char separator;
    printf("Ingresa una cadena de texto completa: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';

    printf("Ingresa un carácter separador: ");
    scanf("%c", &separator);
    getchar();


    int totalLength = strlen(inputString);


    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int j = 0;


    for (int i = 0; i < totalLength; i++) {
        if (inputString[i] == ' ') {
            result[j++] = separator;
        } else {
            result[j++] = inputString[i];
        }
    }


    if (result[j - 1] == separator) {
        j--;
    }

    result[j] = '\0';

    return result;
}

/**
 * @author Julian Arias
 * @brief Verifies if a string ends with a given substring.
 *
 * This function checks whether the main string ends with the provided substring.
 *
 * @param str The main string to be checked.
 * @param substr The substring to verify if it matches the end of the main string.
 *
 * @return int Returns 0 if the string ends with the substring, otherwise returns 1.
 */
int endsWith(const char *str, const char *substr) {
    int strLen = strlen(str);
    int substrLen = strlen(substr);

    // Si la subcadena es más larga que la cadena principal, no puede coincidir
    if (substrLen > strLen) {
        return 1; // No coincide
    }

    // Comparar desde el final de la cadena principal con la subcadena
    if (strcmp(str + strLen - substrLen, substr) == 0) {
        return 0; // Coincide
    } else {
        return 1; // No coincide
    }
}

void checkEndsWith() {
    char str[MAX_LENGTH];
    char substr[MAX_LENGTH];

    // Pedir la cadena principal
    printf("Ingresa la cadena principal: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Eliminar el salto de línea

    // Pedir la subcadena
    printf("Ingresa la subcadena: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Eliminar el salto de línea

    // Verificar si la cadena termina con la subcadena
    int result = endsWith(str, substr);
    printf("Resultado: %d\n", result);
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

    format(number, result, sizeof(result));

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
    char string[MAX_LENGTH];

    printf("Enter a character string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';

    if (isPalindrome(string)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    getchar();
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
 * @author Laura Daniela Guevara
 *
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
 * @author Laura Daniela Guevara
 *
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
    char input[1000];

    printf("Enter the text: ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    int wordCount = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            wordCount++;
        }
    }


    char** words = (char**)malloc(wordCount * sizeof(char*));
    if (words == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

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

    free(temp);

    for (int i = 0; i < wordCount; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
        free(words[i]); // Free each string
    }
    free(words);
}

void mainMenu(){
    char option;
    char *menu = "\n<<<<<<<MAIN MENU>>>>>>\n\n"
                 "1. Find the last occurrence of a substring within another string.\n"
                 "2. Capitalize a text string.\n"
                 "3. Split a string into a character array.\n"
                 "4. Join strings with a separator.\n"
                 "5. Check if a string ends with another substring.\n"
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
            case '4': {
                char* result = joinStringsWithInput();
                if (result != NULL) {
                    printf("Cadena resultante: %s\n", result);
                    free(result);
                }
                break;
            }
            case '5': checkEndsWith();
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