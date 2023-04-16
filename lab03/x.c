// x.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program that reads an integer n
// then prints an nxn pattern of asterisks and dashes in the shape
// of an "X"


#include <stdio.h>

int main(void) {
    int size;
    int row = 0;
    int column = 0;
    printf("Enter size: ");
    scanf("%d", &size);
    while (row < size) {
        column = 0;
        while (column < size) {            
            if (column == row || column == size - row - 1) {
                printf("*");
            } else {
                printf("-");
            }
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
    return 0;
}

    
    
