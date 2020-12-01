// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Dictionary size
unsigned long dict_size = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    if (word[0] >= 97) {
        return (word[0] - 97);
    } else {
        return (word[0] - 65);
    }
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hash_of_the_word = hash(word);
    node *cursor = table[hash_of_the_word];
    // No entries in this bucket, so the word is not in the dictionary
    if (cursor == NULL) return false;

    while(cursor->next != NULL) {
        if (strcasecmp((cursor->word), word) == 0) {
            return true;            
        } 
        else {
            cursor = cursor->next;
        }
    }
    if (strcasecmp((cursor->word), word) == 0) {
        return true;
    } else {
        return false;
    }

}


// Added by SSH to insert a node into the given global table of length N
bool insert_into_table(node* to_insert_node, unsigned int hash_code)
{
    if (table[hash_code] == NULL) {
        // First item to be added at this index, all other will be addded before it, this will always be the last one
        to_insert_node->next = NULL;
        table[hash_code] = to_insert_node;
        return true;
    } else {
        to_insert_node->next = table[hash_code];
        table[hash_code] = to_insert_node;
        return true;
    }
    return false;
}
void initialize_table(void)
{
    for (int i = 0; i < N; i++){
        table[i] = NULL;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE* fp = fopen(dictionary, "r");

    if (fp == NULL) {
        printf("No enough memmory to open the dictonary file\n");   
        return false;
    }
    // Word read from the dictionary
    // Assumptions based on the course website
    /* 
    You may assume that any dictionary passed to your program will be structured exactly like ours, alphabetically sorted from top to bottom with one word per line, each of which ends with \n.You may also assume that dictionary will contain at least one word, that no word will be longer than LENGTH(a constant defined in dictionary.h) characters, that no word will appear more than once, that each word will contain only lowercase alphabetical characters and possibly apostrophes, and that no word will start with an apostrophe.
    */
    char* word = malloc(LENGTH * sizeof(char));
    initialize_table();
    // To keep count of the dictionary size
    int j = 0;
    for (int i = fscanf(fp, "%s", word); i != EOF; i = fscanf(fp, "%s", word), j++)
    {
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL){
            printf("Not enough memory for opening a new node for the hash table\n");
            return false;
        }
        
        strcpy(new_node->word, word);
        unsigned int table_index = hash(new_node->word);
        // Try to insert the node into the hash table
        // If failed, terminate
        if (!insert_into_table(new_node, table_index)){
            printf("Could not insert %s into table, terminate\n", word);
            return false;
        }
    }
    dict_size = j;
    
    free(word);
    fclose(fp);
    // Taken from the already implemented code in speller.c
    // Check whether there was an error
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (dict_size < 0) return 0;
    return dict_size;
}

void free_row(node* rowofTable)
{
    node *cursor = rowofTable, *tmp = rowofTable;
    while (cursor->next != NULL) {
        cursor = cursor->next;
        free(tmp);
        tmp = cursor;
    }
    free(cursor);
    return;    
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++) {
        // We might have fucked up our hash function and
        // some baskets are left empty
        if (table[i] == NULL) continue;
        free_row(table[i]);
        }
    return true;
}
