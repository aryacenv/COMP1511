// COMP1511 Week 7 LAB: string_to_lower_args.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 14 JULY 2021
//
// This program will read command line arguments then prints
// them out. When it prints out, it will convert all upper case letters
// to lower case.

#include <stdio.h>
#include <string.h>

int swap_case(int character);

int main(int argc, char *argv[]) {
    char start[999999];
    strcpy(start, argv[1]);

    if (argc >= 2 ) {
        for (int i = 2; i < argc; i++) {
            strcat(start, " ");
            strcat(start, argv[i]);
        }
        //printf("%s\n", start);
        for (int i = 0; start[i] != '\0'; i++) {
            int character = (int) start[i];
            int new_character = swap_case(character);
            putchar(new_character);
        }   
        printf("\n");
    }
    return 0;
}

int swap_case(int character) {
    if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
