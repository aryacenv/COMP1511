// COMP1511 Week 7 LAB: caesar.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 18 JULY 2021
//
// This program reads characters from its input
// and writes the characters to its output encrypted with a Caesar cipher.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int encrypt(int character, int shift) {
    char c = character;
    if (islower(c)) {
        if (character + shift > 122) {
            return (character - 97 + shift) % 26 + 97;
        } else {
            return (character + shift);
        }
    }
    if (isupper(c)) {
        if (character + shift > 90) {
            return ( character - 65 + shift) % 26 + 65;
        } else {
            return (character + shift);
        }                     
    }
    return character;
}
int main(int argc, char** argv) {
    char line[300];
    if (argc > 2) { // CHECKS IF USER HAS GIVEN APPROPRIATE COMMAND LINE ARGUMENT
        printf("You have given a single command line argument that is more than one\n");
        exit(0);
    }
    int shift = atoi(argv[1]);
    if (shift < 0) {
        shift = -1 * shift;
        shift = 26 - shift % 26;
    }
    while(1) {
        scanf("%[^\n]",line);
        if (getchar() == EOF) {
            break;
        }
        int i = 0;
        char c;
        while(line[i]!='\0') {
            c = encrypt(line[i],shift);
            putchar(c);
            i++;
        }
        printf("\n");
        fflush(stdin);
    }
    return 0;
}
