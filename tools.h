#include <string.h>
#include <ctype.h>

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

void format(double number, char *result, size_t size) {
    char buffer[100];
    int len, j = 0, k = 0;
    int decimalPos;

    snprintf(buffer, sizeof(buffer), "%.2lf", number);

    len = strlen(buffer);
    decimalPos = strchr(buffer, '.') ? strchr(buffer, '.') - buffer : len;

    if (buffer[decimalPos + 1] == '0' && buffer[decimalPos + 2] == '0') {
        buffer[decimalPos] = '\0';
    }

    len = strlen(buffer);

    if (size < len + 3) {
        snprintf(result, size, "Buffer too short");
        return;
    }

    result[j++] = '$';

    for (int i = len - 1; i >= 0; i--) {
        if (buffer[i] == '.') {
            result[j++] = buffer[i];
            k = 0;
        } else {
            if (k > 0 && k % 3 == 0 && i > 0 && buffer[i-1] != '.') {
                result[j++] = '.';
            }
            result[j++] = buffer[i];
            k++;
        }
    }
    result[j] = '\0';

    int start = 1;
    int end = j - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
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
