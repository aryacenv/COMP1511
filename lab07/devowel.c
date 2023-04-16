// COMP1511 Week 7 LAB: devowel.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 14 JULY 2021
//
// This program will remove vowels from sentences.

#include <stdio.h>

int main(void) {
    int c;
    c = getchar();
    while (c != EOF) {
        if (c != 'a' && c != 'e' && c != 'i') {
            if (c != 'o' && c != 'u') {
                putchar(c);
            }
        }
        c = getchar();
    }
    return 0;
}
