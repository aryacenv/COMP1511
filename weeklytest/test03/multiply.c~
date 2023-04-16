// multiply.c
// Arya Bodhi Gunawan (z5240037)
// Friday 18 June 2021
// A program that reads 2 integers and prints their absolute multiple

#include <stdio.h>

int main(void) {
    int num_one;
    int num_two;
    int multiple;
    int absolute;
    
    scanf("%d %d", &num_one, &num_two);
    if (num_one == 0 || num_two == 0) {
        printf("zero\n");
    } else if (num_one > 0 && num_two > 0) {
        multiple = num_one * num_two;
        printf("%d\n", multiple);
    } else if (num_one < 0 && num_two < 0) {
        multiple = num_one * num_two;
        printf("%d\n", multiple);
    } else if (num_two < 0) {
        absolute = -1 * num_two;
        multiple = num_one * absolute;
        printf("%d\n", multiple);
    } else if (num_one < 0) {
        absolute = -1 * num_one;
        multiple = absolute * num_two;
        printf("%d\n", multiple);
    }
    return 0;
}
