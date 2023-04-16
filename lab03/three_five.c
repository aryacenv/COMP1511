// three_five.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program that reads a positive integer n 
// and print all the positive integers < n divisible by 3 or 5 
// in ascending order

#include <stdio.h>

int main(void) {
    int num_picked;
    int counter = 1;
    
    printf("Enter number: ");
    scanf("%d", &num_picked);
    while (counter < num_picked) {
        if ((counter % 3 == 0) || (counter % 5 == 0)) {      
            printf("%d\n", counter);
            counter = counter + 1;
        } else {
            counter = counter + 1;
        }
    }
    return 0;
}
    
    
