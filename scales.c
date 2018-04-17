#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

const char* keyNames[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
int majorSteps[6] = {2, 2, 1, 2, 2, 2};
int minorSteps[6] = {2, 1, 2, 2, 1, 2};
int numberOfNotes = sizeof(keyNames) / sizeof(keyNames[0]);
int numberOfSteps = sizeof(majorSteps) / sizeof(majorSteps[0]);

void printScale(int noteIndex, char* type, int steps[]) {
    printf("%s %s: %s", keyNames[noteIndex], type, keyNames[noteIndex]);
    int offset = 0;
    for (int i = 0; i < numberOfSteps; i++) {
        offset += steps[i];
        printf(" %-2s", keyNames[(noteIndex + offset) % numberOfNotes]);
    }
    printf("\n");
}

char* sToUpper(char str[]) {
      int i = 0;
      while(str[i]) {
          str[i] = toupper(str[i]);
          i++;
      }
      return str;
}

int setKeyIndex(char* key) {
    int index = -1;
    for(int i = 0; i < numberOfNotes; i++) {
        if (strcmp(keyNames[i], sToUpper(key)) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("This program requires exactly one command line argument\n");
        return 0;
    }

    int keyIndex = setKeyIndex(argv[1]);
    if (keyIndex == -1) {
        printf("Key note not found!\n");
        return 0;
    }

    printScale(keyIndex, "major", majorSteps);
    printScale(keyIndex, "minor", minorSteps);
    return 0;
}
