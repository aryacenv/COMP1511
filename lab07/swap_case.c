// Function to print out a string that has had it's cases swapped.
// swap_case.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 14 JULY 2021
 
#include <stdio.h>

int swap_case(int character);

int main(void) {
    int character = getchar();
    while (character != EOF) {
        int new_character = swap_case(character);
        putchar(new_character);
        character = getchar();
    }
    // TODO: Write this function, using the swap_case function.

    return 0;
}

int swap_case(int character) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        return 'A' + alphabetPosition;
    }
    else if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
