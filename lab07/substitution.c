// COMP1511 Week 7 LAB: substitution.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 20 JULY 2021
//
// This program will read characters from its input and writes the character
// to its output encrypted with a substitution cypher.

#include <stdio.h>

int cipher(int character, char key[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid/empty command line argument found");
    } else {
        int character = getchar();
        while (character != EOF) {
            int new_character = cipher(character, argv[1]);
            putchar(new_character);
            character = getchar();
        }
    }
    return 0;
}

int cipher(int character, char key[]) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        int result = key[alphabetPosition];
        return result;
    }
    if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        int result = key[alphabetPosition];
        result = result - 'a' + 'A';
        return result;
    }
    return character;
}
