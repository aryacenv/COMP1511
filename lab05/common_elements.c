// COMP1511 Week 5 LAB: common_elements
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 12 JULY 2021
//
// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], 
    int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int i = 0;
    int j = 0;
    int amt_copied = 0;
    // 1 if the numbers are equal and 0 if it is not
    int same_or_not;
    while (i < length) {
        same_or_not = 0;
        j = 0;
        while (j < length && same_or_not == 0) {
            if (source1[i] == source2[j]) {
                same_or_not = 1;
            }
            j = j + 1;
        }
        if (same_or_not == 1) {
            destination[amt_copied] = source1[i];
            amt_copied = amt_copied + 1;
        }
        i = i + 1;
    }
    return amt_copied;
}
        

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
