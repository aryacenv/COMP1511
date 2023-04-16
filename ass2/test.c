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
    struct dexnode *last;
    struct dexnode *current;
};


// You don't have to use the provided struct dexnode, you are free to
// make your own struct instead.
//
// If you use the provided struct dexnode, you will need to add fields
// to it to store other information.
struct dexnode {
    int found_or_not;
    struct dexnode *next;
    struct dexnode *prev;
    Pokemon pokemon;
};

// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------
struct sub_string {
    struct char_node *head;
    int length;
};

struct char_node {
    struct char_node *next;
    int ch;
}






// ----------------------------------------------
// Add prototypes for your own functions here.
static void print_name_found(struct dexnode *node);
static void print_type(struct dexnode *node, int type);
static int compare_str(const char *str_one, const char *str_two);
static int find_string(char *str, char *str2);
static int lower_case(int character);
// ----------------------------------------------

// Creates a new dexnode struct and returns a pointer to it.
static struct dexnode *create_new_dexnode(Pokemon pokemon, struct dexnode *node);


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
    pokedex->num_pokemon = 0;
    pokedex->head = NULL;
    pokedex->selected_dexnode = NULL;
    // TODO: Add your own code here.

    return pokedex;
}

// Create a new dexnode struct and returns a pointer to it.
//
// This function should allocate memory for a dexnode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct dexnode *create_new_dexnode(Pokemon pokemon, struct dexnode *node) {
    struct dexnode *n;
    n = malloc(sizeof (struct dexnode));
    assert(n != NULL);
    n->next = NULL;
    n->pokemon = pokemon;
    n->found_or_not = 1;
    n->previous = NULL;
    if (node != NULL) {
        node->next = n;
        n->previous = node;
    }
    return n;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct dexnode *node;
    if (pokedex->head == NULL) {
        node = NULL;
    } else {
        node = pokedex->current;
    }
    struct dexnode *newdexnode = create_new_dexnode(pokemon, node);
    if (pokedex->num_pokemon == 0) {
        pokedex->head = newdexnode;
        pokedex->selected_dexnode = newdexnode;
    }
    pokedex->num_pokemon++;
    pokedex->current = newdexnode;
}
    

// Print out all of the Pokemon in the Pokedex.
void print_pokedex(Pokedex pokedex) {
    struct dexnode *current_node = pokedex->head;
    //struct dexnode *selected_dexnode = pokedex->selected_dexnode;
    while (current_node != NULL) {
        if (current_node->pokemon == pokedex->selected_dexnode->pokemon) {
            printf("--> ");
        } else {
            printf("    ");
        }
        printf("#%03d: ", pokemon_id(current_node->pokemon));
        print_name_found(current_node);
        printf("\n");
        current_node = current_node->next;
    }
    
}

// Print out the details of the currently selected Pokemon.
void detail_current_pokemon(Pokedex pokedex) {
    struct dexnode *selected_dexnode = pokedex->selected_dexnode;
    if (selected_dexnode != NULL) {
        if (selected_dexnode->found_or_not == 0) {
            printf("ID: %03d\n", pokemon_id(selected_dexnode->pokemon));
            printf("Name: ");
            print_name_found(selected_dexnode);
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        } else {
            printf("ID: %03d\n", pokemon_id(selected_dexnode->pokemon));
            printf("Name: %s\n", pokemon_name(selected_dexnode->pokemon));
            printf("Height: %.6f m\n", pokemon_height(selected_dexnode->pokemon));
            printf("Weight: %.6f kg\n", pokemon_weight(selected_dexnode->pokemon));
            print_type(selected_dexnode, 1);
        }
    }
}

// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    Pokemon pokemon = NULL;
    if (pokedex->selected_dexnode != NULL) {
        pokemon = pokedex->selected_dexnode->pokemon;
    }
    return pokemon;
}

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    struct dexnode *selected = pokedex->selected_dexnode;
    if (selected != NULL) {
        if (selected->next != NULL && selected != NULL) {
            pokedex->selected_dexnode = pokedex->selected_dexnode->next;
        }
    }
}

// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    struct dexnode *selected = pokedex->selected_dexnode;
    if (selected != NULL) {
        if (selected->previous != NULL && selected != NULL) {
            pokedex->selected_dexnode = pokedex->selected_dexnode->previous;
        }
    }
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void jump_pokemon(Pokedex pokedex, int id) {
    struct dexnode *current = pokedex->head;
    while (current != NULL) {
        if (pokemon_id(current->pokemon) == id) {
            pokedex->selected_dexnode = current;
        }
        current = current->next;
    }
}

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Sets the currently selected pokemon's "found" status
void set_current_pokemon_found(Pokedex pokedex, int found) {
    if (pokedex->selected_dexnode != NULL) {
        pokedex->selected_dexnode->found_or_not = found;
    }
}

// Add a pokemon before the current pokemon.
void insert_pokemon_before_current(Pokedex pokedex, Pokemon pokemon) {
}

// Return the total number of Pokemon in the Pokedex.
int count_pokemon_of_type(Pokedex pokedex, char *type) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    struct dexnode *node = pokedex->selected_dexnode;
    struct dexnode *next = node->next;
    struct dexnode *previous = node->previous;
    if (node != NULL && node != pokedex->head) {
        destroy_pokemon(node->pokemon);
        if (next == NULL) {
            pokedex->selected_dexnode = previous;
        } else {
            pokedex->selected_dexnode = next;
            node->next->previous = previous;
        }
        node->previous->next = next;
    }
    if (node == pokedex->head) {
        pokedex->selected_dexnode = next;
        destroy_pokemon(node->pokemon);
        if (pokedex->head->next != NULL) {
            pokedex->head = pokedex->head->next;
        } else {
            pokedex->head = NULL;
        }
    }
    free(node);
}

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    struct dexnode *node = pokedex->head;
    struct dexnode *next_node;
    while (node != NULL) {
        destroy_pokemon(node->pokemon);
        next_node = node->next;
        free(node);
        node = next_node;
    }
    free(pokedex);
    pokedex = NULL;
}

// Prints out all types of found Pokemon stored in the Pokedex
void show_types(Pokedex pokedex) {
    
    
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int count = 0;
    struct dexnode *current = pokedex->head;
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
    int count1 = 0;
    struct dexnode *current = pokedex->head;
    while (current != NULL) {
        count1++;
        current = current->next;
    }
    return count1;
}

// NOTE: Make sure you submit ass2_pokedex before completing these.
//////////////////////////////////////////////////////////////////////
//                     Stage 4 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

/*
 * Saves a pokedex to a text file
 * Use the functions in ext_save.h to save the contents to a file
 */
void save_pokedex(Pokedex pokedex, char* filename) {
    fprintf(stderr, "exiting because you have not implemented the save_pokedex function\n");
    exit(1);

}

/*
 * Loads a pokedex from a text file
 * Use the functions in ext_save.h to load the text from a file
 */
Pokedex load_pokedex(char* filename) {
    fprintf(stderr, "exiting because you have not implemented the load_pokedex function\n");
    exit(1);

    return NULL;
}

//////////////////////////////////////////////////////////////////////
//                     Stage 5 Extension Functions                  //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    fprintf(stderr, "exiting because you have not implemented the show_types function\n");
    exit(1);
}

// Free's the current sub-list and returns the original pokedex state, 
// prior to the search
Pokedex end_search(Pokedex sub_pokedex) {
    fprintf(stderr, "exiting because you have not implemented the end_search function\n");
    exit(1);
}

// Add definitions for your own functions here.


static void print_name_found(struct dexnode *node) {
    Pokemon pokemon = node->pokemon;
    char *name = pokemon_name(pokemon);
    char hidden[100] = {0};
    int i = 0;
    if (node->found_or_not == 0) {
        while (name[i] != '\0') {
            hidden[i] = 42;
            i++;
        }
    }
    if (node->found_or_not == 0) {
        printf("%s", hidden);
    } else {
        printf("%s", name);
    }
}

// This function will print out the pokemon type inside a dexnode
static void print_type(struct dexnode *node, int type) {
    Pokemon pokemon = node->pokemon;
    pokemon_type type_1 = pokemon_first_type(pokemon);
    pokemon_type type_2 = pokemon_second_type(pokemon);
    const char *type_1_str = type_code_to_str(type_1);
    const char *type_2_str = type_code_to_str(type_2);
    const char *none = "None";
    if (type == 1) {
        if (compare_str(type_2_str, none) == 1) {
            printf("Type: %s\n", type_1_str);
        } else {
            printf("Type: %s %s\n", type_1_str, type_2_str);
        }
    } else if (type == 2) {
        if (node->found_or_not == 1) {
            if (compare_str(type_2_str, none) == 1) {
                printf(" [%s]", type_1_str);
            } else {
                printf(" [%s, %s]", type_1_str, type_2_str);
            }
        } else {
            printf(" [????]");
        }
    }
}

// This function will check if two strings are the same and returns 1 if so
static int compare_str(const char *str_one, const char *str_two) {
    int one = 0;
    int two = 0;
    int same_char = 0;
    int i = 0;
    while (str_one[i] == str_two[i] && str_one[i] != '\0') {
        i++;
    }
    same_char = i;
    
    int j = 0;
    while (str_one[j] != '\0') {
        j++;
    }
    one = j;
    
    int k = 0;
    while (str_two[k] != '\0') {
        k++;
    }
    two = k;
    
    if (one == 0) {
        return 0;
    }
    if (one == two && two == same_char) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

//
static int find_string(char *str, char *str2) {
    char *name = str;
    char name2[50] = {0};
    char *search_name = str2;
    char search_name2[50] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    while (*(search_name + i) != '\0') {
        search_name2[i] = lower_case(*(search_name + i));
        i++;
    }
    int count_1 = i;
    i = 0;
    while (*(name + i) != '\0') {
        name2[i] = lower_case(*(name + i));
        i++;
    }
    i = 0;
    while (name2[i] != '\0') {
        i = 0;
        j = 0;
        count = 0;
        if (name2[j] == search_name2[k]) {
            i = j;
            while (count <= count_1) {
                if (name2[i] == search_name2[k]) {
                    i++;
                    k++;
                    if (search_name2[k] == '\0') {
                        return 1;
                    }
                } else {
                    count = count_1 + 1;
                }
                count++;
            }
        }
        j++;
    }
    return 0;
}
    
// This function converts all upper case characters into lower case.
static int lower_case(int character) {
    if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
    
    


