#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototype
bool isS(char *);

// Define the CFG rules
bool isS(char *str) {
    if (str[0] == '0') {
        int len = strlen(str);
        if (str[len - 1] == '1') {
            // If the first and last characters are '0' and '1', respectively
            // Recursively check if the substring without the first and last characters is also in the language
            char newStr[len - 1];
            strncpy(newStr, str + 1, len - 2);
            newStr[len - 2] = '\0';
            return isS(newStr);
        }
    } else if (str[0] == '\0') {
        return true; // Empty string is in the language
    }
    return false; // Not part of the language
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isS(str)) {
        printf("String belongs to the language\n");
    } else {
        printf("String does not belong to the language\n");
    }

    return 0;
}

