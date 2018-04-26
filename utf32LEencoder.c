#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int RUN_CODE = 0;

static bool legal(uint32_t codepoint) {
    return codepoint <= 0x0010FFFF
        && (codepoint < 0x0000FDD0 || codepoint > 0x0000FDEF)
        && (codepoint & 0x0000FFFE) != 0x0000FFFE;
}

void utf8_converter(uint32_t utf_32) {
    if (!legal(utf_32)) {
        RUN_CODE = -1;
        putchar(0xFFFD);
    }
    else if(utf_32 <= 0x7F) {
        putchar(utf_32 & 0xFF);
    } else if (utf_32 <= 0x7FF) {
        putchar(0xC0 | utf_32>>6);
        putchar(0x80 | (utf_32 & 0x3F));
    } else if (utf_32 <= 0xFFFF) {
        putchar(0xE0 | utf_32>>12);
        putchar(0x80 | (utf_32>>6 & 0x3F));
        putchar(0x80 | (utf_32 & 0x3F));
    } else {
        putchar(0xF0 | utf_32>>18);
        putchar(0x80 | utf_32>>12);
        putchar(0x80 | (utf_32>>6 & 0x3F));
        putchar(0x80 | (utf_32 & 0x3F));
    }
}

const int BLOCK_SIZE = 1024;

int main() {
    uint32_t buffer[BLOCK_SIZE];
    while (true) {
        int bytes_read = fread(buffer, 4, BLOCK_SIZE, stdin);
        if (bytes_read == 0) {
            break;
        }
        for (int i = 0; i < bytes_read; i++) {
            utf8_converter(buffer[i]);
        }
    }
    return RUN_CODE;
}
