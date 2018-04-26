#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* KEY_NAMES[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int MAJOR_STEPS[6] = {2, 2, 1, 2, 2, 2};
int MINOR_STEPS[6] = {2, 1, 2, 2, 1, 2};
int NUMBER_OF_NOTES = sizeof(KEY_NAMES) / sizeof(KEY_NAMES[0]);
int NUMER_OF_STEPS = sizeof(MAJOR_STEPS) / sizeof(MAJOR_STEPS[0]);

void print_scale(int note_index, char* type, int steps[]) {
    printf("%s %s: %s", KEY_NAMES[note_index], type, KEY_NAMES[note_index]);
    int offset = 0;
    for (int i = 0; i < NUMER_OF_STEPS; i++) {
        offset += steps[i];
        printf(" %-2s", KEY_NAMES[(note_index + offset) % NUMBER_OF_NOTES]);
    }
    printf("\n");
}

char* s_to_upper(char str[]) {
      int length = strlen(str);
      for (int i = 0; i < length; i++) {
          str[i] = toupper(str[i]);
      }
      return str;
}

int set_key_index(char* key) {
    int index = -1;
    for(int i = 0; i < NUMBER_OF_NOTES; i++) {
        if (strcmp(KEY_NAMES[i], s_to_upper(key)) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("This program requires exactly one command line argument.\n");
        exit(EXIT_FAILURE);
    }

    int key_index = set_key_index(argv[1]);
    if (key_index == -1) {
        printf("Key note not found!\n");
        exit(EXIT_FAILURE);
    }

    print_scale(key_index, "major", MAJOR_STEPS);
    print_scale(key_index, "minor", MINOR_STEPS);
    return 0;
}
