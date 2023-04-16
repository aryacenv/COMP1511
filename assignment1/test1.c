// Assignment 1 21T2 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 1 JULY 2021
//
// Version 1.0.0 (2021-06-19): Assignment released.

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE              8

// The possible command codes.
#define DETECT_ROW      1
#define DETECT_SQUARE   2
#define REVEAL_CROSS    3
#define GAME_MODE       4
#define FLAG_MINE       5
#define DEFUSE          6

// Add any extra #defines here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);

// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    int mines;
    int count = 1;
    int x;
    int y;
    

    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    // START OF STAGE 1
    printf("How many mines? ");
    scanf("%d", &mines);

    printf("Enter pairs:\n");
    while (count <= mines) {
        scanf("%d %d", &x, &y);
        
        if (x < 0 && y > 0) {
            x = 1 * x; //DO NOTHING (TRIVIAL COMMAND)
        } else if (y < 0 && x > 0) {
            y = 1 * y; //DO NOTHING (TRIVIAL COMMAND)
        } else if (x < 0 && y < 0) {
            y = 1 * y; //DO NOTHING (TRIVIAL COMMAND)
        } else if (x < SIZE && y < SIZE) {
            minefield[x][y] = 2;
        } else if (x >= SIZE || y > SIZE) {
            y = 1 * y; //DO NOTHING (TRIVIAL COMMAND)
        }     
        count++;
        }

    printf("Game Started\n");
    print_debug_minefield(minefield);
    
    int check_type;
    int check_row;
    int check_col;
    int num_of_sqr;
    int col_start;
    int col_end;
    int mine_count = 0;
    int i,j;
    while (scanf("%d", &check_type) != EOF) {
        if (check_type == 1) {
            scanf("%d %d %d", &check_row, &check_col, &num_of_sqr);
            if (check_row < 0 || check_col < 0) {
            printf("Coordinates not on map\n");
            print_debug_minefield(minefield);     
        }
    col_start = check_col;
    col_end = col_start + num_of_sqr - 1;
    if (col_end > 7) {
        printf("Coordinates not on map\n");
        print_debug_minefield(minefield);
    } else if (check_row >= 0 || check_col >= 0) {
        for (i = check_row; i < check_row + 1; i++) {
            for (j = col_start; j < col_end + 1; j++) {
                if (minefield[i][j] == 2) {
                    mine_count++;
                } else {
                    mine_count = mine_count + 0;                    
                }           
            }
        printf("There are %d mine(s) in row %d, from column %d to %d\n", mine_count, check_row, col_start, col_end);
        mine_count = 0;
        print_debug_minefield(minefield);
        // END OF STAGE 1
        }
    }
    // START OF STAGE 2    
        } else if (check_type == 2) {
            scanf("%d %d %d", &check_row, &check_col, &num_of_sqr);
            stage_2(check_row, check_col, num_of_sqr); 
    } else if (check_type == 3) {
        scanf("%d %d", &check_row, &check_col);
        int col_range1 = check_col - 1;
        int col_range2 = check_col + 1;
        int row_range1 = check_row - 1;
        int row_range2 = check_row + 1;
        int row1, row2, col1, col2, k, l, z, q;
        int one_count = 0;       
        if (check_row < 0 || check_col < 0) {
            printf("Coordinates not on map\n");
            print_debug_minefield(minefield);
        } else if (check_row > 7 || check_col > 7) {
            printf("Coordinates not on map\n");
            print_debug_minefield(minefield);  
        } else if (check_row >= 0 || check_col >= 0) { 
            if (minefield[check_row][check_col] == 2) {
                printf("Game over\n");
                print_debug_minefield(minefield); 
                return 1;
            } else if (minefield[check_row][check_col] == 1 || 
                minefield[check_row][check_col] == 0) {
                minefield[check_row][check_col] = 0;
                if (col_range1 < 0 && row_range1 < 0) {
                    col_range1 = 0;
                    row_range1 = 0;
                }
                if (col_range1 > 7) {
                    col_range1 = 7;
                }
                if (col_range1 < 0) {
                    col_range1 = 0;
                }
                if (row_range1 < 0 && col_range2 > 7) {
                    row_range1 = 0;
                    col_range2 = 7;
                }
                if (row_range1 < 0) {
                    row_range1 = 0;
                }
                if (col_range2 > 7 && row_range2 > 7) {
                    col_range2 = 7;
                    row_range2 = 7;
                }
                if (col_range2 > 7) {
                    col_range2 = 7;
                }
                if (row_range2 > 7) {
                    row_range2 = 7;
                }
                for (i = row_range1; i < row_range2 + 1; i++) {
                    if (i == check_row) {
                        for (j = col_range1; j < col_range2 + 1; j++) {
                            if (minefield[i][j] == 2) {
                                row1 = row1 + 0;
                            } else if (minefield[i][j] != 2) {
                                minefield[i][j] = 0;
                            }
                            row1 = i - 1;
                            row2 = i + 1;
                            col1 = j - 1;
                            col2 = j + 1;
                            if (row1 && col1 < 0) {
                                row1 = 0;
                                col1 = 0;
                            }
                            if (row1 < 0 && col2 > 7) {
                                col2 = 7;
                                row1 = 0;
                            }
                            if (row1 < 0) {
                                row1 = 0;
                            }
                            if (col1 < 0) {
                                col1 = 0;
                            } 
                            if (row2 > 7 && col2 > 7) {
                                row2 = 7;
                                col2 = 7;
                            }
                            if (row2 > 7) {
                                row2 = 7;
                            }
                            if (col2 > 7) {
                                col2 = 7;
                            }
                            if (row1 > 7) {
                                row1 = 7;
                            }
                            int k_limit = row2 + 1;
                            if (k_limit > 7) {
                                k_limit = 7;
                            } else {
                                k_limit = row2 + 1;
                            }

                            for (k = row1; k < k_limit; k++) {
                                for (l = col1; l < col2 + 1; l++) {
                                    if (minefield[k][l] == 2 && minefield[i][j] != 2) {
                                        minefield[i][j] = 1;
                                        minefield[check_row][check_col] = 0;    
                                    } else if (minefield [k][l] != 2) {
                                        row1 = row1 + 0;
                                        }
                                    }
                                }
                            }   
                        } else if (i != check_row) {
                            for (j = col_range1 + 1; j < col_range2 + 0; j++) {
                                if (minefield[i][j] == 2) {
                                    row1 = row1 + 0;
                                } else if (minefield[i][j] != 2) {
                                    minefield[i][j] = 0;
                                }
                                row1 = i - 1;
                                row2 = i + 1;
                                col1 = j - 1;
                                col2 = j + 1;
                                if (row1 && col1 < 0) {
                                    row1 = 0;
                                    col1 = 0;
                                }
                                if (row1 < 0) {
                                    row1 = 0;
                                }
                                if (col1 < 0) {
                                    col1 = 0;
                                }
                                if (row2 > 7 && col2 > 7) {
                                    row2 = 7;
                                    col2 = 7;
                                }
                                if (row2 > 7) {
                                    row2 = 7;
                                }
                                if (col2 > 7) {
                                    col2 = 7;
                                } 
                                if (row1 > 7) {
                                    row1 = 7;
                                }
                                for (k = row1; k < row2 + 1; k++) {
                                    for (l = col1; l < col2 + 1; l++) {
                                        if (minefield[k][l] == 2 && minefield[i][j] != 2) {
                                            minefield[i][j] = 1;
                                            minefield[check_row][check_col] = 0;    
                                    } else if (minefield [k][l] != 2) {
                                        row1 = row1 + 0;
                                        }
                                    }
                                }                            
                        }
                    }
                }
            for (z = 0; z < SIZE; z++) {
                for (q = 0; q < SIZE; q++) {
                    if (minefield[z][q] == 1) {
                        one_count++;
                    } else {
                        one_count = one_count + 0;
                    }
                }
            } if (one_count == 0) {
                print_debug_minefield(minefield);
                printf("Game Won!\n");
                
                return 1;
            } else {
                print_debug_minefield(minefield);
                one_count = 0;
                
            }
                
                       
            }    
        }
    }
}
            

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.


    return 0;
}
// Stage 2 PART 1 FUNCTION
void stage_2(int a, int b, int c) {
    int minefield[SIZE][SIZE];
    void initialise_field(int minefield[SIZE][SIZE]);
    void print_debug_minefield(int minefield[SIZE][SIZE]);
    initialise_field(minefield);
    int check_type;
    int check_row;
    int check_col;
    int num_of_sqr;
    int col_start;
    int col_end;
    int mine_count = 0;
    int i,j;
    a = check_row;
    b = check_col;
    c = num_of_sqr;
    int col_range1 = check_col - ((num_of_sqr/2)-(1/2));
    int col_range2 = check_col + ((num_of_sqr/2)-(1/2));
    int row_range1 = check_row - ((num_of_sqr/2)-(1/2));
    int row_range2 = check_row + ((num_of_sqr/2)-(1/2));
    if (check_row < 0 || check_col < 0) {
        printf("Coordinates not on map\n");
        print_debug_minefield(minefield);
    } else if (check_row > 7 || check_col > 7) {
        printf("Coordinates not on map\n");
        print_debug_minefield(minefield);
    } else if (col_range1 && row_range1 < 0) {
        col_range1 = 0;
        row_range1 = 0;
        for (i = row_range1; i < row_range2 + 1; i++) {
            for (j = col_range1; j < col_range2 + 1; j++) {
                if (minefield[i][j] == 2) {
                    mine_count++;
                } else {
                    mine_count = mine_count + 0;
                }
            }
        }                 
    } else if (col_range1 < 0) {
        col_range1 = 0;
        for (i = row_range1; i < row_range2 + 1; i++) {
            for (j = col_range1; j < col_range2 + 1; j++) {
                if (minefield[i][j] == 2) {
                    mine_count++;
                } else {
                    mine_count = mine_count + 0;
                }
            }
        }            
    } else if (row_range1 < 0) {
        row_range1 = 0;
        for (i = row_range1; i < row_range2 + 1; i++) {
            for (j = col_range1; j < col_range2 + 1; j++) {
                if (minefield[i][j] == 2) {
                    mine_count++;
                } else {
                    mine_count = mine_count + 0;
                }
            }
        }     
    } else if (check_row >= 0 || check_col >= 0) {
        for (i = row_range1; i < row_range2 + 1; i++) {
            for (j = col_range1; j < col_range2 + 1; j++) {
                if (minefield[i][j] == 2) {
                    mine_count++;
                } else {
                    mine_count = mine_count + 0;
                }
            }
        }
    }
    if (check_row < 0 || check_row > 7 || check_col < 0 || check_col > 7) {
        check_row = check_row * 1; //TRIVIAL COMMAND
    } else {
        printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n", mine_count, check_row, check_col,   num_of_sqr);
        print_debug_minefield(minefield);
        mine_count = 0;   
    }
}
    
    

// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}


// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
