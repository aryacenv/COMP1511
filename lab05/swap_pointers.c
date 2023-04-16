// COMP1511 Week 5 LAB: swap_pointers
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 4 JULY 2021
//
// This program will swap the values in two integers, given as pointers

#include <stdio.h>

void swap_pointers(int *a, int *b);

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int first_storage;
    int second_storage;
    first_storage = *a;
    second_storage = *b;
    *a = second_storage;
    *b = first_storage;
}
