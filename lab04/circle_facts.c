// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 27 JUNE 2021
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    double area_1;
    area_1 = M_PI * radius * radius;
    return area_1;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    double circumference_1;
    circumference_1 = 2 * M_PI * radius;
    return circumference_1;
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    double diameter_1;
    diameter_1 = 2 * radius;
    return diameter_1;
}
