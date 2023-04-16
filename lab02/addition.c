// addition.c
// Arya Bodhi Gunawan, z5240037 (JUNE 8, 2021)
// A program that will add together the number of students and
// tutors in the class

#include <stdio.h>

int main(void) {
    int students;
    int tutors;
    int sum;
    
    printf("Please enter the number of students and tutors:");
    scanf("%d %d", &students, &tutors);
    sum = students+tutors;
    printf("%d + %d = %d \n", students, tutors, sum);
    return 0;
}


