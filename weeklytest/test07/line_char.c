// COMP1511 Week 7 TEST: line_char.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 21 JULY 2021
//
// This program reads a line from its input then reads an integer n from
// its input. It should write the character in position n.

#include <stdio.h>

int main(void) {
    char input_1[256];
    int input_2;
    scanf("%[^\n]", input_1);
    scanf("%d", &input_2);
    printf("The character in position %d is '%c'\n", input_2, input_1[input_2]);
    
}
    
    
