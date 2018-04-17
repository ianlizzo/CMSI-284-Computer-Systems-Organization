#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int allocatedSpaceForString(char* string) {
    int allocatedSpace = 0;
    int length = strlen(string);
    for (int i = 1; i <= length; i++) {
        allocatedSpace += i;
    }
    return allocatedSpace;
}

char* silly(char *stringOne, char* stringTwo) {
    int allocatedSpace = allocatedSpaceForString(stringOne) + allocatedSpaceForString(stringTwo);
    char* finalString = malloc(allocatedSpace + 1);
    finalString[0] = '\0';
    int lengthOne = strlen(stringOne);
    for (int i = 1; i <= lengthOne; i++) {
        strncat(finalString, stringOne, i);
    }
    int lengthTwo = strlen(stringTwo);
    for (int i = 1; i <= lengthTwo; i++) {
        strncat(finalString, stringTwo, i);
    }
    return finalString;
}

int main() {
    printf("%s\n", silly("apple", "banana"));
    return 0;
}
