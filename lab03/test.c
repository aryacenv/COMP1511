#include <stdio.h>

int main()
{
    int size, row, column;

    scanf("%d", &size);

    row = 0;
    while (row < size)
    {
        column = 0;
        while (column < size)
        {
            if (column == row || column == size - row - 1)
            {
                printf("x");
            }
            else
            {
                printf(" ");
            }
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;
}
