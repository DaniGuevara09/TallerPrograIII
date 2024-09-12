#include <string.h>
#include <ctype.h>

void Format(double number, char *result, size_t size) {
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