#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mod(int a, int b) {
    int remainder = a % b;
    return (remainder < 0) ? remainder += b : remainder;
}

char* rotate(char* string, int start_index) {
    int length = strlen(string);
    char* final_string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        final_string[i] = string[mod(start_index + i, length)];
    }
    final_string[length] = '\0';
    return final_string;
}
