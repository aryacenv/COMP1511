// COMP1511 Week 4 TEST: loop_sum
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 29 JUNE 2021
//
// This program reads an integer n from standard input, 
// and then scans in n integers from standard input, 
// adds them together, then prints the sum

#include <stdio.h>

int main(void) {
    int int_n;
    int sum = 0;
    int count = 1;
    int value;
    printf("How many numbers: ");
    scanf("%d", &int_n);
    while (count <= int_n) {
        scanf("%d", &value);
        sum = sum + value;
        count++;
    }
    printf("The sum is: %d\n", sum);
    return 0;
}
        
