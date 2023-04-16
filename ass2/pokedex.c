// Assignment 2 21T2 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Arya Bodhi Gunawan (z5240037)
// on 25 JULY 2021
//
// Version 1.0.0: Release
// Version 1.0.1: Fixed references to create_new_dexnode in comments and error messages

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "ext_save.h"

// Note you are not allowed to use the strstr function in this assignment
// There are some techniques we would like you to learn to code
// that this function makes easier.

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"


// ----------------------------------------------
// Add your own #defines here.
#define MAX_LENGTH 1000
#define FOUND 1
#define NOT_FOUND 0
// ----------------------------------------------


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct dexnode *head;
    struct dexnode *selected;
};


// You don't have to use the provided struct dexnode, you are free to
// make your own struct instead.
//
// If you use the provided struct dexnode, you will need to add fields
// to it to store other information.
typedef struct dexnode Dexnode;
struct dexnode {
    struct dexnode *next;
    Pokemon pokemon;
    int found_or_not;
};

// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------


// ----------------------------------------------
// Add prototypes for your own functions here.
static void add(Pokedex pokedex, Dexnode *new);
static void print_pokemon_id(Pokemon pokemon);
static void print_pokemon_type(Pokemon pokemon);
static int str_len(char *str);
static void copy_pokemon(Pokedex pokedex, Pokemon pokemon);
static void find_pokemon(Pokedex pokedex);
static void sort_pokemon(Pokedex pokedex);
static int array_contains(pokemon_type type, pokemon_type arr_type[MAX_LENGTH], int type_count);
static int name_search(char *name, char *text);

// ----------------------------------------------

// Creates a new dexnode struct and returns a pointer to it.
static Dexnode *create_new_dexnode(Pokemon pokemon);

// You need to implement the following functions in their stages.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h

// Creates a new Pokedex, and returns a pointer to it.
// Note: you will need to modify this function.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    pokedex->head = NULL;
    pokedex->selected = NULL;
    return pokedex;
}

// Create a new dexnode struct and returns a pointer to it.
//
// This function should allocate memory for a dexnode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static Dexnode *create_new_dexnode(Pokemon pokemon) {
    Dexnode *new = malloc(sizeof (Dexnode));
    new->pokemon = pokemon;
    new->found_or_not = FOUND;
    new->next = NULL;
    return new;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    Dexnode *new = create_new_dexnode(pokemon);
    add(pokedex, new);
}
    
// Print out all of the Pokemon in the Pokedex.
void print_pokedex(Pokedex pokedex) {
    Dexnode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr == pokedex->selected) {
            printf("--> #");
        } else {
            printf("    #");
        }
        print_pokemon_id(curr->pokemon);
        printf(": ");
        if (curr->found_or_not == NOT_FOUND) {
            int len = str_len(pokemon_name(curr->pokemon));
            for (int i = 0; i < len; i++) {
                printf("*");
            }
        } else if (curr->found_or_not == FOUND) {
            printf("%s", pokemon_name(curr->pokemon));
        }
        printf("\n");
        curr = curr->next;
    }
}

// Print out the details of the currently selected Pokemon.
void detail_current_pokemon(Pokedex pokedex) {
    Pokemon pokemon = get_current_pokemon(pokedex);
    if (pokedex->head != NULL &&
        pokedex->selected->found_or_not == NOT_FOUND) {
        printf("ID: ");
        print_pokemon_id(pokemon);
        printf("\nName: ");
        int i;
        int len = str_len(pokemon_name(pokemon));
        for (i = 0; i < len; i++) {
            printf("*");
        }
        printf("\nHeight: --");
        printf("\nWeight: --");
        printf("\nType: --\n");
    } else if (pokedex->head != NULL &&
               pokedex->selected->found_or_not == FOUND) {
        printf("ID: ");
        print_pokemon_id(pokemon);
        printf("\nName: %s", pokemon_name(pokemon));
        printf("\nHeight: %.6f m", pokemon_height(pokemon));
        printf("\nWeight: %.6f kg", pokemon_weight(pokemon));
        printf("\nType: "); 
        print_pokemon_type(pokemon);
    } 
}
// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        return NULL;
    } else {
        return pokedex->selected->pokemon;
    }
}

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    Dexnode *curr = pokedex->selected;
    if (pokedex->head != NULL) {
        pokedex->selected = curr->next;
        if (pokedex->selected == NULL) {
            pokedex->selected = curr;
        }
    }
}

// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    Dexnode *curr = pokedex->head;
    Dexnode *prev = NULL;
    
    if (pokedex->head != NULL) {
        while (curr != NULL && curr != pokedex->selected) {
            prev = curr;
            curr = curr->next;
        } 
        pokedex->selected = prev; 
        if (pokedex->selected == NULL) {
            pokedex->selected = pokedex->head;
        }
    }
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void jump_pokemon(Pokedex pokedex, int id) {
    Dexnode *curr = pokedex->head;
    while (curr != NULL) {
        if (pokemon_id(curr->pokemon) == id) {
            pokedex->selected = curr;
            break;
        }
        curr = curr->next;
    }
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Sets the currently selected pokemon's "found" status
void set_current_pokemon_found(Pokedex pokedex, int found) {
    if (pokedex->head != NULL) {
        pokedex->selected->found_or_not = found;
    }
}

// Add a pokemon before the current pokemon.
void insert_pokemon_before_current(Pokedex pokedex, Pokemon pokemon) {
    Dexnode *current = pokedex->head;
    Dexnode *prev = NULL;
    Dexnode *new = create_new_dexnode(pokemon);
    new->found_or_not = NOT_FOUND;
    if (pokedex->head != NULL) {
        // Looking for the previous node of selected pokemon.
        while (current != NULL && current != pokedex->selected) {
            prev = current;
            current = current->next;
        }
        if (prev != NULL) {
            prev->next = new;
            new->next = current;
            pokedex->selected = new;
        } else {
            pokedex->head = new;
            new->next = current;
            pokedex->selected = new;
        }       
    } else {
        pokedex->head = new;
        new->next = NULL;
        pokedex->selected = pokedex->head;
    }
}

// Return the total number of Pokemon in the Pokedex.
int count_pokemon_of_type(Pokedex pokedex, char *type) {
    int count = 0;
    Dexnode *current = pokedex->head;
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;
        pokemon_type type_given = type_str_to_code(type);
        if (pokemon_first_type(pokemon) == type_given || 
            pokemon_second_type(pokemon) == type_given) {
            count++;
        }
        current = current->next;
    }
    return count;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    Dexnode *current = pokedex->head;
    Dexnode *tmp = NULL;
    Dexnode *sel = pokedex->selected;
    if (current != NULL && sel == current) {
        pokedex->head = current->next;
        pokedex->selected = current->next;
        free(pokemon_name(current->pokemon));
        free(current->pokemon);
        free(current);
    } else if (current != NULL && sel->next != NULL) {
        while (current != NULL && current != sel) {
            tmp = current;
            current = current->next;
        }
        tmp->next = current->next;
        pokedex->selected = current->next;
        free(pokemon_name(current->pokemon));
        free(current->pokemon);
        free(current);
    } else if (current != NULL && sel->next == NULL) {
        while (current != NULL && current != sel) {
            tmp = current;
            current = current->next;
        }
        tmp->next = NULL;
        pokedex->selected = tmp;
        free(pokemon_name(current->pokemon));
        free(current->pokemon);
        free(current);
    }
    if (pokedex == NULL) {
        pokedex->selected = NULL;
    }
}
}


// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    while (pokedex->head != NULL) {
        Dexnode *tmp = pokedex->head;
        pokedex->head = pokedex->head->next;
        free(pokemon_name(tmp->pokemon));
        free(tmp->pokemon);
        free(tmp);
    }
    free(pokedex);
}

// Prints out all types of found Pokemon stored in the Pokedex
void show_types(Pokedex pokedex) {
    int type_count = 0;
    pokemon_type arr_type[MAX_LENGTH];

    Dexnode *current = pokedex->head;
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;

        pokemon_type first_type = pokemon_first_type(pokemon);
        if (first_type != NONE_TYPE && 
            array_contains(first_type, arr_type, type_count) == 0) {
            printf("%s\n", type_code_to_str(pokemon_first_type(pokemon)));
            arr_type[type_count] = first_type;
            type_count++;
        }

        pokemon_type second_type = pokemon_second_type(pokemon);
        if (second_type != NONE_TYPE && 
            array_contains(second_type, arr_type, type_count) == 0) {
            printf("%s\n", type_code_to_str(pokemon_second_type(pokemon)));
            arr_type[type_count] = second_type;
            type_count++;
        }

        current = current->next;
    }
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int count = 0;
    Dexnode *current = pokedex->head;
    while (current != NULL) {
        if (current->found_or_not == 1) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    int count = 0;
    Dexnode *current = pokedex->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// NOTE: Make sure you submit ass2_pokedex before completing these.
//////////////////////////////////////////////////////////////////////
//                     Stage 4 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

/*
 * Saves a pokedex to a text file
 * Use the functions in ext_save.h to save the contents to a file
 */
void save_pokedex(Pokedex pokedex, char *filename) {  
}

/*
 * Loads a pokedex from a text file
 * Use the functions in ext_save.h to load the text from a file
 */
Pokedex load_pokedex(char *filename) {
    return NULL;
}

//////////////////////////////////////////////////////////////////////
//                     Stage 5 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.

Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    Pokedex n_pokedex = new_pokedex();
    Dexnode *current = pokedex->head; 
    // If the specified type is NONE_TYPE, exit the
    // program.
    if (type == NONE_TYPE) {
        fprintf(stderr, "Invalid type\n");
        exit(1);
    }    
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;
        if (current->found_or_not == FOUND &&
            (pokemon_first_type(pokemon) == type ||
            pokemon_second_type(pokemon) == type)) {
            copy_pokemon(n_pokedex, pokemon);
        }
        current = current->next;
    }
    find_pokemon(n_pokedex);
    return n_pokedex;
}


// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex n_pokedex = new_pokedex();
    Dexnode *current = pokedex->head;
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;
        if (current->found_or_not == FOUND) {
            copy_pokemon(n_pokedex, pokemon);
        }
        current = current->next;
    }
    find_pokemon(n_pokedex);
    sort_pokemon(n_pokedex);
    return n_pokedex;
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Dexnode n_pokedex = new_pokedex();
    Dexnode *current = pokedex->head;
    if (text == NULL) {
        fprintf(stderr, "Invalid Search Command\n");
    }
    while (current != NULL) {
        Pokemon pokemon = current->pokemon;
        char *name = pokemon_name(current->pokemon);
        if (current->found_or_not == FOUND && name_search(name, text)) {
            copy_pokemon(n_pokedex, pokemon);
        }
        current = current->next;
    }
    find_pokemon(n_pokedex);
    return n_pokedex;
}


// Free's the current sub-list and returns the original pokedex state, 
// prior to the search
Pokedex end_search(Pokedex sub_pokedex) {
    fprintf(stderr, "exiting because you have not implemented the end_search function\n");
    exit(1);
}

// Add definitions for your own functions here.


// Adds a Pokemon to the Pokedex.
static void add(Pokedex pokedex, Dexnode *new) {
    if (pokedex->head == NULL) {
        pokedex->head = new;
        pokedex->selected = new;
    } else { 
        Dexnode *list = pokedex->head;
        while (list->next != NULL) {
            list = list->next;
        }
        list->next = new;
    }
}

// Prints the ID of a Pokemon.
static void print_pokemon_id(Pokemon pokemon) {
    if (pokemon_id(pokemon) < 100) {
        printf("%03d", pokemon_id(pokemon));
    } 
    else if (pokemon_id(pokemon) >= 100) {
        printf("%d", pokemon_id(pokemon));
    }
}

// Prints the types of a Pokemon.
static void print_pokemon_type(Pokemon pokemon) {
    printf("%s", type_code_to_str(pokemon_first_type(pokemon)));
    // Second type
    if (pokemon_second_type(pokemon) == NONE_TYPE) {
        printf("\n");
    } else {
        printf(" %s\n", type_code_to_str(pokemon_second_type(pokemon)));
    }    
}

// A manual strlen function: counts the length of a string.
static int str_len(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

static void copy_pokemon(Pokedex pokedex, Pokemon pokemon) {
    Pokemon n_pokemon = clone_pokemon(pokemon);
    add_pokemon(pokedex, n_pokemon);
}

static void find_pokemon(Pokedex pokedex) {
    Dexnode *current = pokedex->head;
    if (pokedex != NULL) {
        while (current != NULL) {
            current->found_or_not = FOUND;
            current = current->next;
        }
    }
}

static void sort_pokemon(Pokedex pokedex) { 
    Dexnode *current = pokedex->head;
    Dexnode *then = NULL;  
    Pokemon tmp;  
      
    if (pokedex->head == NULL) {  
        return;  
    } 
   
    while (current != NULL) {  
        // Node 'then' will point to node next to current 
        then = current->next;  
        while (then != NULL) {  
            // If current node's ID is greater than then's ID, 
            // swap the data between them.  
            if (pokemon_id(current->pokemon) > pokemon_id(then->pokemon)) {  
                tmp = current->pokemon;  
                current->pokemon = then->pokemon;  
                then->pokemon = tmp;  
            }  
            then = then->next;  
        }  
        current = current->next;  
    }   
}

static int array_contains(pokemon_type type, pokemon_type arr_type[MAX_LENGTH], 
                          int type_count) {
    for(int i = 0; i < type_count; i++) {
        if (arr_type[i] == type) {
            return 1;
        }
    }
    return 0;
}

static int name_search(char *name, char *text) {
    int diff = 'A' - 'a';
    int len_name = str_len(name);
    int len_text = str_len(text);
    
    for (int i = 0; i < len_name; i++) {
        if ((name[i] == text[0] || name[i] == text[0] + diff || 
            name[i] == text[0] - diff) && len_name >= (len_text + i)) {
            int flag = 1;
            for (int j = 0; j < len_text; j++) {
                if (name[i + j] == text[j] || name[i + j] == text[j] + diff ||
                    name[i + j] == text[j] - diff) {
                    continue;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                return 1;
            }
        }
    }
    return 0;
}
    


