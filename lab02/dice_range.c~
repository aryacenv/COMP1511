// dice_range.c
// Arya Bodhi Gunawan, z5240037 (9 JUNE, 2021)
// A program that reads the number of sides on a set of dice and how
// many of them are being rolled.

#include <stdio.h>

int main(void) {
    int dice_sides;
    int num_dice;
    double avg_value;
    int range_min;
    int range_max;
    
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &dice_sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &num_dice);
    if (dice_sides < 1 || num_dice < 1) {
        printf("These dice will not produce a range. \n");
    } else {
        range_min = num_dice;
        range_max = dice_sides*num_dice;
        avg_value = (range_min + range_max) / (float)2;
        printf("Your dice range is %d to %d. \n", range_min, range_max);
        printf("The average value is %f \n", avg_value);
    }
    return 0;
}
    
    

