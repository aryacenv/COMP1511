 else if (check_type == 3) {
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
            if (minefield[check_row][check_col] == HIDDEN_MINE) {
                printf("Game over\n");
                print_debug_minefield(minefield); 
                return 1;
            } else if (minefield[check_row][check_col] == HIDDEN_SAFE || 
                minefield[check_row][check_col] == VISIBLE_SAFE) {
                minefield[check_row][check_col] = VISIBLE_SAFE;
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
                    if (i != check_row) {
                        for (j = check_col; j < check_col + 1; j++) {
                            if (minefield[i][j] == HIDDEN_MINE) {
                                row1 = row1 + 0;
                            } else if (minefield[i][j] != HIDDEN_MINE) {
                                minefield[i][j] = VISIBLE_SAFE;
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
                                    if (minefield[i][j] == VISIBLE_SAFE) {
                                        minefield[i][j] = VISIBLE_SAFE;
                                    }
                                    if (minefield[k][l] == HIDDEN_MINE && minefield[i][j] != HIDDEN_MINE) {
                                        minefield[i][j] = HIDDEN_SAFE;
                                        minefield[check_row][check_col] = VISIBLE_SAFE;
                                    
                                } else if (minefield [k][l] != HIDDEN_MINE) {
                                    row1 = row1 + 0;
                                }
                            }
                        }                            
                    }
                    }
                    if (i == check_row) {
                        for (j = col_range1; j < col_range2 + 1; j++) {
                            if (minefield[i][j] == HIDDEN_MINE) {
                                row1 = row1 + 0;
                            }
                            if (minefield[i][j] != HIDDEN_MINE) {
                                minefield[i][j] = VISIBLE_SAFE;
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
                            for (k = row1; k < row2 + 1; k++) {  
                                for (l = col1; l < col2 + 1; l++) {
                                    if (minefield[k][l] == HIDDEN_MINE && minefield[i][j] != HIDDEN_MINE) {
                                        minefield[i][j] = HIDDEN_SAFE;
                                        minefield[check_row][check_col] = VISIBLE_SAFE;    
                                    } else if (minefield [k][l] != HIDDEN_MINE) {
                                        row1 = row1 + 0;
                                    }
                                }
                            }
                        }   
                    }

                }
            for (z = 0; z < SIZE; z++) {
                for (q = 0; q < SIZE; q++) {
                    if (minefield[z][q] == HIDDEN_SAFE) {
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
                //printf("%d\n", one_count);
                one_count = 0;
                
            }
                
                       
            }    
        }
    }
