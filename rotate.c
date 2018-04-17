#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mod(int a, int b) {
    int remainder = a % b;
    return (remainder < 0) ? remainder += b : remainder;
}

char* rotate(char* string, int startIndex) {
    int length = strlen(string);
    char* finalString = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        finalString[i] = string[mod(startIndex + i, length)];
    }
    finalString[length] = '\0';
    return finalString;
}
