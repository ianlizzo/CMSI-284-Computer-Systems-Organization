#include <stdio.h>
#include <math.h>

int main() {
    const char *keyNames[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    int numberOfKeys = 88;
    double numberOfSteps = sizeof(keyNames) / sizeof(keyNames[0]);
    double initialFrequency = 27.5;
    double frequency = 0.0;

    for (int i = 0; i < numberOfKeys; i++) {
        frequency = initialFrequency * ((double)pow(2.0, i / numberOfSteps));
        printf("%s\t%0.4f\n", keyNames[i % ((int)numberOfSteps)], frequency);
    }
    return 0;
}
