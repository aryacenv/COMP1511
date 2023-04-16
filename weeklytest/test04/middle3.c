// COMP1511 Week 4 TEST: middle3
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 29 JUNE 2021
//
// This program reads 3 integers and prints the middle integer

#include <stdio.h>

int main(void) {
    int int1;
    int int2;
    int int3;
    int mid_int;
    printf("Enter integer: ");
    scanf("%d", &int1);
    printf("Enter integer: ");
    scanf("%d", &int2);
    printf("Enter integer: ");
    scanf("%d", &int3);
    if (int1 <= int2) {
        if (int2 <= int3) {
            mid_int = int2;
            printf("Middle: %d\n", mid_int);
        } else if (int2 >= int3) {
            if (int3 >= int1) {
                mid_int = int3;
                printf("Middle: %d\n", mid_int);
            } else {
                mid_int = int1;
                printf("Middle: %d\n", mid_int);
            }
        }
    } else if (int2 <= int1) {
        if (int1 <= int3) {
            mid_int = int1;
            printf("Middle: %d\n", mid_int);
        } else if (int1 >= int3) {
            if (int3 >= int2) {
                mid_int = int3;
                printf("Middle: %d\n", mid_int);
            } else {
                mid_int = int2;
                printf("Middle: %d\n", mid_int);
            }
        }
    }
    return 0;
}
        
        
        
        
        
        
        
        
        
                
