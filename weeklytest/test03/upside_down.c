// upside_down.c
// Arya Bodhi Gunawan (z5240037)
// Friday 18 June 2021
// A program that reads 3 numbers and indicate whether they are strictly
// increasing, strictly decreasing, or neither

#include <stdio.h>

int main(void) {
    double num_one;
    double num_two;
    double num_three;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &num_one, &num_two, &num_three);
    if (num_two > num_one) {
        if (num_three > num_two) {
            printf("up \n");
        } else if (num_three < num_two) {
            printf("neither \n"); 
        }
    } else if (num_one > num_two) {
        if (num_two > num_three) {
            printf("down \n");
        } else if (num_two < num_three) {
            printf("neither \n");
        }
    } else if (num_one == num_two || num_one == num_three || 
               num_two == num_three) {
        printf("neither \n");
    }
    
    return 0;
}
