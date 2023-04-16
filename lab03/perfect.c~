// perfect.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program to determine whether the number entered by the user
// is a perfect number or not


#include <stdio.h>

int main(void) {
    int num_picked;
    int counter = 1;
    int sum = 0;
    int final_sum;
    printf("Enter number: ");
    scanf("%d", &num_picked);
    printf("The factors of %d are: \n", num_picked);
    while (counter <= num_picked) {
        if (num_picked % counter == 0) {
            sum = sum + counter;
            printf("%d\n", counter);
            counter = counter + 1;  
        } else {
            counter = counter + 1;
        }
    }
    final_sum = sum - num_picked;
    printf("Sum of factors = %d\n", sum);
    if (final_sum == num_picked) {
        printf("%d is a perfect number\n", num_picked);
    } else {
        printf("%d is not a perfect number\n", num_picked);
    }
    return 0;
}
