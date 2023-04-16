// COMP1511 Week 7 TEST: secret_code.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 21 JULY 2021
//
// This program allows you to scan in messages encrypted 
// with Tom's Secret Code, and then print them out
//

#include <stdio.h>

int main(void) {
    int input_1 = getchar();
    int input_2 = getchar();
    while (input_1 != EOF && input_2 != EOF) {
        if (input_1 < input_2) {
            putchar(input_1);
        } else {
            putchar(input_2);
        }
        input_1 = getchar();
        input_2 = getchar();
    }
    printf("\n");
}          
    

