//implements functions to manipulate list

// defines functions to manipulate list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "demo_library.h"



//Defines ListNode
typedef struct{
        int value;
        char name[20];
        ListNode* next;
        ListNode* prev;
    } ListNode;


//Checks input for value
int classify(char* input[]) {
    
    //Copies input to command string and truncates it to the first word only
    char cmd[] = *input;
    int i = 0;
    for (i = 0; cmd[i] != ' ' && cmd[i] != '\0'; i++) {}
    cmd[i] = '\0';

    if (input[i] == ' ') {
        int j = 0;
        for (j = 0; input[i] != '\0'; j++) {
            *input[j] = *input[i];
        }
        *input[j] = '\0';
        
    }
    

    //Compares cmd to list of known commands

    if (strcmp(cmd, "add") == 0) {
        printf("Adding element to list: %s\n", *input);
        return 1;
    }
}


// Case 1, Adds element to back of list
void addBack(char name[]);


// Case 2, Returns size of list
int listSize(ListNode* head);


// Case 3, Prints list with values
void printList(ListNode* head);


// Case 4, Finds element in list by name, calculates position in list and shows value
ListNode* findByName(char name[], ListNode* head);


// Case 5, Finds element in list by number, prints name and shows value
ListNode* findByPosition(int position, ListNode* head);


// Case 6, Moves to next element
ListNode* next(ListNode* cur);


// Case 7, Moves to previous element
ListNode* prev(ListNode* cur);


// Case 8, Instructions for operations on an element
void currentElement(ListNode* cur);


// Case 9, Modifies value of element in list
void changeValue(ListNode* cur, int newValue);


// Case 10, Removes element from list
void removeElement(ListNode* cur, ListNode* head);


// Case 11, Prints all elements and values to file in order
void finalPrint(ListNode* head);

#endif