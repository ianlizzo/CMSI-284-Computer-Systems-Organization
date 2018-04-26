#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int allocated_space_for_string(char* string) {
    int allocated_space = 0;
    int length = strlen(string);
    for (int i = 1; i <= length; i++) {
        allocated_space += i;
    }
    return allocated_space;
}

char* silly(char* s1, char* s2) {
    int allocated_space = allocated_space_for_string(s1) + allocated_space_for_string(s2);
    char* final_string = malloc(allocated_space + 1);
    final_string[0] = '\0';
    int length_one = strlen(s1);
    for (int i = 1; i <= length_one; i++) {
        strncat(final_string, s1, i);
    }
    int length_two = strlen(s2);
    for (int i = 1; i <= length_two; i++) {
        strncat(final_string, s2, i);
    }
    return final_string;
}

int main() {
    printf("%s\n", silly("apple", "banana"));
    return 0;
}
