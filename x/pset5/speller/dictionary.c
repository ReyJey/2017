/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LENGTH 45
#include "dictionary.h"

typedef struct node
{
    bool  realword;
    struct node* children[27];
} node;
node* position = NULL;
node* root;
int counter = 0;
bool nodefree(node* freenode, int newposition);
int wordindex(char leter) {
    if (isalpha(leter)) 
		{
		    int n;
			if (isupper(leter)) 
			{
				n = (leter - 65);
			}
			if (islower(leter)) 
			{
				n = (leter - 97);
			}
			return n;
		} 
	else{
	    return 27;
	}
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    bool result = false;
    int numWord = 0;
    position = root;
    int leter = wordindex(word[numWord]);
    while (word[numWord]!='\0'){
        if (position -> children[leter]!= NULL){
            position = position -> children[leter];
            if ((word[numWord + 1] == '\0')&&(position -> realword == true)){
                result = true;
                goto end;
            }
            else {
                result = false;
            }
        }
        else {
            result = false;
            goto end;
        }
        numWord ++;
        leter = wordindex(word[numWord]);
    }
    end:
    return result;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    char line[LENGTH + 1];
    node* newnode = NULL;
    FILE* infile = fopen(dictionary, "r");
    if (infile == NULL){
        return false;
    }
    while (fscanf(infile,"%s", line)!= EOF){
        int numWord = 0;
        position = root;
        int leter = wordindex(line[numWord]);
        if (root == NULL){
            root = malloc(sizeof(node));
            for (int m = 0; m < 27; m ++){
                root -> children[m] = NULL;
            }
            position = root;
        }
        while (line[numWord]!= 0){
            if (position -> children[leter] == NULL){
                newnode = malloc(sizeof(node));
                for (int m = 0; m < 27; m ++){
                    newnode -> children[m] = NULL;
                }
                if (line[numWord + 1]== '\0'){
                    newnode -> realword = true;
                    counter ++;
                }
                else {
                    newnode -> realword = false;
                }
                position -> children[leter] = newnode;
                position = position -> children[leter];
            }
            else {
                position = position -> children[leter];
            }
            numWord ++;
            leter = wordindex(line[numWord]);
        }
    }
    fclose (infile);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return counter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return nodefree(root,26);
}
bool nodefree(node* freenode, int newposition){
    if (newposition >= 0){
        if (freenode -> children[newposition]!= NULL){
            nodefree(freenode -> children[newposition], 26);
            free(freenode -> children[newposition]);
        }
        if (freenode != NULL){
            nodefree(freenode, newposition - 1);
        }
    }
    if (freenode == root && newposition == 0){
        free(root);
    }
    return true;
    
}
