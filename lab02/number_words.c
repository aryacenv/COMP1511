// number_words.c
// Arya Bodhi Gunawan, z5240037 (JUNE 8, 2021)
// A program that will display the number 1 to 5 as word
// in the message

#include <stdio.h>
#define MAX_INT 5
#define MIN_INT 1

int main(void) {
    int number_picked;
    printf("Please enter an integer:");
    scanf("%d", &number_picked);

    if (number_picked < MIN_INT) {
        printf(" You entered a number less than one. \n");
    }
    if (number_picked > MAX_INT) {
        printf(" You entered a number greater than five. \n");
    } else if (number_picked == 1) {
        printf("You entered one. \n");
    } else if (number_picked == 2) {
        printf("You entered two. \n");
    } else if (number_picked == 3) {
        printf("You entered three. \n");
    } else if (number_picked == 4) {
        printf("You entered four. \n");
    } else if (number_picked == 5) {
        printf("You entered five. \n");
    }
    return 0;
}



