// hollow_triangle.c
// Arya Bodhi Gunawan, z5240037 (JUNE 15, 2021)
// A program that reads an integer n
// then prints a pattern of asterisks forming a hollow triangle


#include <stdio.h>

int main(void) {
    int size;
    int row = 1;
    int column = 1;
    printf("Enter size: ");
    scanf("%d", &size);
    while (row <= size) {
        column = 1;
        while (column <= row) {
            if (column == 1 || column == row || row == size) {
                printf("*");
            } else {
                printf(" ");
            }
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
    return 0;
}
                  
        
        
