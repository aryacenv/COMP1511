// order3.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program that reads 3 integers and prints them from smallest to largest

#include <stdio.h>

int main(void) {
    int num_one;
    int num_two;
    int num_three;
    printf("Enter integer: ");
    scanf("%d", &num_one);
    printf("Enter integer: ");
    scanf("%d", &num_two);
    printf("Enter integer: ");
    scanf("%d", &num_three);
    if (num_one <= num_two && num_one <= num_three) {
        if (num_two <= num_three) {
            printf("The integers in order are: %d %d %d \n", 
            num_one, num_two, num_three);
        } else {
            printf("The integers in order are: %d %d %d \n", 
            num_one, num_three, num_two);
        }
    } else if (num_two <= num_one && num_two <= num_three) {
        if (num_one <= num_three) {
            printf("The integers in order are: %d %d %d \n", 
                num_two, num_one, num_three);
        } else {
            printf("The integers in order are: %d %d %d \n", 
                num_two, num_three, num_one);
        }
    } else if (num_three <= num_one && num_three <= num_two) {
        if (num_two <= num_one) {
            printf("The integers in order are: %d %d %d \n", 
                num_three, num_two, num_one);
        } else {
            printf("The integers in order are: %d %d %d \n", 
                num_three, num_one, num_two);
        }
    }
    return 0;
}

    
                                
        
    
    
    
