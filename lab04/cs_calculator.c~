// COMP1511 Week 4 Lab: cs_calculator
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 27 JUNE 2021
//
// This program will scan in instructions until EOF
// then prints the outcome

#include <stdio.h>
#include <math.h>

int main(void) {
    int num_instruction;
    int int_1;
    int int_2;
    int result;
    
    printf("Enter instruction: ");
    while (scanf("%d", &num_instruction) != EOF) {
        if (num_instruction == 1) {
            scanf("%d", &int_1);
            result = (int_1 * int_1);
            printf("%d\n", result);
            printf("Enter instruction: ");
        } else if (num_instruction == 2) {
            scanf("%d %d", &int_1, &int_2);
            result = pow(int_1, int_2);
            printf("%d\n", result);
            printf("Enter instruction: ");
        }
    }
    return 0;
}
        
        
    
        
