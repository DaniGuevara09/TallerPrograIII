#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void Formatear(double numero, char *resultado, size_t size) {
    char buffer[100];
    int len, j = 0, k = 0;
    int decimalPos;

    snprintf(buffer, sizeof(buffer), "%.2lf", numero);

    len = strlen(buffer);
    decimalPos = strchr(buffer, '.') ? strchr(buffer, '.') - buffer : len;

    if (buffer[decimalPos + 1] == '0' && buffer[decimalPos + 2] == '0') {
        buffer[decimalPos] = '\0';
    }

    len = strlen(buffer);

    if (size < len + 3) {
        snprintf(resultado, size, "Buffer demasiado pequeño");
        return;
    }

    resultado[j++] = '$';

    for (int i = len - 1; i >= 0; i--) {
        if (buffer[i] == '.') {
            resultado[j++] = buffer[i];
            k = 0;
        } else {
            if (k > 0 && k % 3 == 0 && i > 0 && buffer[i-1] != '.') {
                resultado[j++] = '.';
            }
            resultado[j++] = buffer[i];
            k++;
        }
    }
    resultado[j] = '\0';

    int start = 1;
    int end = j - 1;
    while (start < end) {
        char temp = resultado[start];
        resultado[start] = resultado[end];
        resultado[end] = temp;
        start++;
        end--;
    }
}

int isPalindrome(const char *str) {
    int izq = 0, der = strlen(str) -1;

    while (izq < der) {
        while (izq < der && !isalpha(str[izq])) {
            izq++;
        }
        while (izq< der && !isalpha(str[der])) {
            der--;
        }

        if (tolower(str[izq]) != tolower(str[der])) {
            return 0;
        }

        izq++;
        der--;
    }

    return 1;
}