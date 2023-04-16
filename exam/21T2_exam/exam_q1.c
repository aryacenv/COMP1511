// exam_q1.c
//
// This program was written by z5240037
// on 18-08-2021

#include <stdio.h>

// Return the number of pairs with multiples in the array.
int count_multiples(int size, int array[size][2]) {
    int count = 0;
    int i = 0;
    while (i < size) {
        if (array[i][1] % array[i][0] == 0) {
            count++;
            i++;
        } else {
            i++;
        }
    }
    return count;
}


// This is a simple main function which could be used
// to test your count_multiples function.
// It will not be marked.
// Only your count_multiples function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE][2] = {
        {2, 3}, {4, 4}, {8, 4}, {3, 30}, {30, 40}, {80, 40}, {30, 110}, {30, 120},
    };

    int result = count_multiples(TEST_ARRAY_SIZE, test_array);
    printf("%d\n", result);

    return 0;
}
