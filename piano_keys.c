#include <stdio.h>
#include <math.h>

int main() {
    const char* KEY_NAMES[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int NUMBER_OF_KEYS = 88;
    double NUMBER_OF_STEPS = sizeof(KEY_NAMES) / sizeof(KEY_NAMES[0]);
    double INITIAL_FREQUENCY = 27.5;
    double FREQUENCY = 0.0;

    for (int i = 0; i < NUMBER_OF_KEYS; i++) {
        FREQUENCY = INITIAL_FREQUENCY * ((double)pow(2.0, i / NUMBER_OF_STEPS));
        printf("%s\t%0.4f\n", KEY_NAMES[i % ((int)NUMBER_OF_STEPS)], FREQUENCY);
    }
    return 0;
}
