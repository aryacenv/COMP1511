// print_pi.c 
// Arya Bodhi Gunawan, z5240037 (JUNE 27, 2021)
// Prints the first n digits of pi, where n is specified
// by the user

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int digit;
    int count = 0;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &digit);
    if (digit == 0) {
        printf("\n");
    } else {
        while (count < digit) {
            if (count == (digit - 1)) {
                printf("%d\n", pi[count]);
            } else { 
                printf("%d", pi[count]);
            }
            if (digit == 1) {
                count++;
            } else if (count == 0) {
                printf(".");
                count++;
            } else {
                count++;
            }
        }
    }
        

    return 0;
}
