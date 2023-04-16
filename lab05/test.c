#include <stdio.h>
int main(void) {
    int array[2][2] = {{3,6},{7,8}};
    int sum_col1 = 0;
    int num_lines = 2;
    int j;
    
    
    int i = 0;
    while (i < num_lines) {
        j = 0;
        sum_col1 = sum_col1 + array[i][j];
        i++;
    }
    printf("%d\n", sum_col1);
    return 0;
}
