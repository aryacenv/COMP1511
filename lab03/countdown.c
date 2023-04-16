// countdown.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program that uses a loop to print a countdown from 10 to 0

#include <stdio.h>

int main(void) {
    int counter = 10;
    while (counter >= 0) {
        printf("%d\n", counter);
        counter = counter - 1;
    }
    return 0;
}
