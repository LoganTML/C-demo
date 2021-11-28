// defines functions to manipulate list

#ifndef _MYLIB_H_
#define _MYLIB_H_


//Defines ListNode
typedef struct{
        int value;
        char name[20];
        ListNode* next;
        ListNode* prev;
    } ListNode;

    typedef struct{
    ListNode* head;
    ListNode* tail;
} LinkedList;


//Checks input for value
int classify(char* input[]);


// Case 1, Adds element to back of list
void addBack(char* input[], LinkedList* List);


// Case 2, Returns size of list
int listSize(LinkedList* List);


// Case 3, Prints list with values
void printList(LinkedList* List);


// Case 4, Finds element in list by number, prints name and shows value
ListNode* findByPosition(char* input[], LinkedList* List);


// Case 5, Finds element in list by name, calculates position in list and shows value
ListNode* findByName(char name[], LinkedList* List);


// Case 6, Moves to next element (towards back)
void next(ListNode* cur, LinkedList* List);


// Case 7, Moves to previous element (towards front/head)
void prev(ListNode* cur, LinkedList* List);


// Case 8, Displays current element
void currentElement(ListNode* cur);


// Case 9, Modifies value of element in list
void changeValue(ListNode* cur, int newValue);


// Case 10, Removes element from list
void removeElement(ListNode* cur, LinkedList* List);


// Case 11, moves element towards back of list
void moveBack(ListNode* cur, LinkedList* List);


// Case 12, moves element towards front of list
void moveUp(ListNode* cur, LinkedList* List);


// Case 13, Prints all elements and values to file in order
void finalPrint(LinkedList* List);

// Case 14, displays all possible commands
void displayCommands();

// Case 15, finds current element's index
int position(ListNode* cur);

#endif