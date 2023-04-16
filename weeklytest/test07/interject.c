// COMP1511 Week 7 Test: Interject
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 21 JULY 2021
//
// This program adds interjections to strings.

#include <stdio.h>

#define MAX_SIZE 1002

void interject(char *str, char *interject, int index){
    int str_size = 0;
    int interject_size = 0;
    int new_size = 0;
    int i = 0;
    int j = 0;
    while (str[str_size]!='\0'){
        str_size++;
    }
    while (interject[interject_size]!='\0') {
        interject_size++;
    }
    char temp_str[str_size + 1];
    for (i = 0; i < str_size; i++) {
        temp_str[i] = str[i];
    }
    temp_str[i] = '\0';
    for (i = index; i < interject_size + index; i++) {
        str[i] = interject[j++];
    }
    new_size = str_size + interject_size;
    for (i = index + interject_size, j = index; i < new_size; i++) {
        str[i] = temp_str[j++];
    }
}


// This is a simple main function that you can use to test your interject
// function.
// It will not be marked - only your interject function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your interject function directly.
// Any changes that you make to this function will not affect the autotests.

int main(void) {
    char str1[MAX_SIZE] = "Comp Science";
    printf("%s -> ", str1);
    interject(str1, "uter", 4);
    printf("%s\n", str1);

    char str2[MAX_SIZE] = "Beginnings";
    printf("%s -> ", str2);
    interject(str2, "New ", 0);
    printf("%s\n", str2);

    char str3[MAX_SIZE] = "The End!";
    printf("%s -> ", str3);
    interject(str3, " Is Nigh", 7);
    printf("%s\n", str3);

    char str4[MAX_SIZE] = "UNSW Other Unis";
    printf("%s -> ", str4);
    interject(str4, "> ", 5);
    printf("%s\n", str4);

    return 0;
}
