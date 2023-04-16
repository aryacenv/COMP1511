// COMP1511 Week 4 TEST: hourglass.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 29 JUNE 2021
//
// This program will print an nxn pattern containing an hourglass

#include <stdio.h>

int main(void) {
    int size;
    printf("Please enter a size: ");
    scanf("%d", &size);    
    int middle = (size + 1) / 2;
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (i == 1 || i == size) {
                printf(" -");
            } else {
                int x;
                if (i > middle) 
                    x = size + 1 - i;
                else 
                    x = i;
                int number_to_display = x - 1;
                int cuts = number_to_display; 
                int start_range = 1 + cuts;
                int end_range = size - cuts;
                if (j >= start_range && j <= end_range) 
                    printf("%2d", number_to_display);
                else 
                    printf(" -");
            }
        }
        printf("\n");
    }   
    return 0;
}   
