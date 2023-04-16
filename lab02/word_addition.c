// word_addition.c
// Arya Bodhi Gunawan, z5240037 (JUNE 11, 2021)
// A program that will add up the integers given by the user
// and convert it into words.

#include <stdio.h>
#include <string.h>
int main(void) {
    char *posArray[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int number_one;
    int number_two;
    
    
    int sum;
    
    char * firstnum;
    printf("Please enter two integers: \n");
    scanf("%d %d", &number_one, &number_two);
    sum = number_one + number_two;
    if (number_one >= 0) {
        firstnum = posArray[number_one];
    } else {
        char source[] = "negative ";
        firstnum = strcat(source, posArray[number_one]);
    }
    printf("%s", firstnum);
    return 0;
}
    
    //if (number_two >= 0) {
    
    
    
    
    
    
    
