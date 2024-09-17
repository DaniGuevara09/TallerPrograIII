#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

/**
 * @brief Formats a given number into a currency format with commas and a dollar sign.
 *
 * This function takes a double number, formats it into a string that represents
 * currency (e.g., $1,234.56), and stores it in the provided result buffer. It
 * handles the decimal precision, applies thousand separators (periods), and adds a
 * dollar sign at the beginning.
 *
 * If the buffer size is too short to store the formatted result, it stores an
 * error message in the result.
 *
 * @param number The floating-point number to be formatted.
 * @param result The buffer where the formatted string will be stored.
 * @param size The size of the result buffer.
 *
 * @return void This function does not return any value.
 *
 * @author Nicolas Rojas
 */

void format(double number, char *result, size_t max_len) {
    char temp[MAX_LENGTH];
    char *ptr_decimal;

    snprintf(temp, sizeof(temp), "%.2f", number);
    ptr_decimal = strchr(temp, '.');

    int len = ptr_decimal - temp;
    int count = 0;

    result[count++] = '$';

    for (int i = 0; i < len; i++) {
        result[count++] = temp[i];
        if ((len - i - 1) % 3 == 0 && i != len - 1) {
            result[count++] = '.';
        }
    }

    if (strcmp(ptr_decimal, ".00") != 0) {
        strcpy(result + count, ptr_decimal);
    } else {
        result[count] = '\0';
    }
}

/**
 * @brief Checks if a given string is a palindrome, ignoring non-alphabetical characters.
 *
 * This function determines whether the input string is a palindrome, meaning it reads
 * the same forwards and backwards, ignoring non-alphabetical characters and treating
 * uppercase and lowercase letters as equal.
 *
 * @param str A null-terminated string to be checked.
 *
 * @return int Returns 1 if the string is a palindrome, 0 otherwise.
 *
 * @author Nicolas Rojas
 */

int isPalindrome(const char *str) {
    int left = 0, right = strlen(str) -1;

    while (left < right) {
        while (left < right && !isalpha(str[left])) {
            left++;
        }
        while (left< right && !isalpha(str[right])) {
            right--;
        }

        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}
