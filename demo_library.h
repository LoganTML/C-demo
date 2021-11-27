// defines functions to manipulate list

#ifndef _MYLIB_H
#define _MYLIB_H_


//Defines ListNode
typedef struct{
        int value;
        char name[20];
        ListNode* next;
        ListNode* prev;
    } ListNode;


//Checks input for value
int classify(char* input[]);


// Case 1, Adds element to back of list
void addBack(char nom[]);


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