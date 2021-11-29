// defines functions to manipulate list

#ifndef _MYLIB_H_
#define _MYLIB_H_


//Defines ListNode
struct ListNode{
        int value;
        char name[20];
        struct ListNode* next;
        struct ListNode* prev;
};

struct LinkedList{
    struct ListNode* head;
    struct ListNode* tail;
};


//Checks input for value
int classify(char input[]);


// Case 1, Adds element to back of list
struct ListNode* addBack(char input[], struct LinkedList* List);


// Case 2, Returns size of list
int listSize(struct LinkedList* List);


// Case 3, Prints list with values
void printList(struct LinkedList* List);


// Case 4, Finds element in list by number, prints name and shows value
struct ListNode* findByPosition(char input[], struct LinkedList* List);


// Case 5, Finds element in list by name, calculates position in list and shows value
struct ListNode* findByName(char name[], struct LinkedList* List);


// Case 6, Moves to next element (towards back)
void next(struct ListNode* cur, struct LinkedList* List);


// Case 7, Moves to previous element (towards front/head)
void prev(struct ListNode* cur, struct LinkedList* List);


// Case 8, Displays current element
void currentElement(struct ListNode* cur);


// Case 9, Modifies value of element in list
void changeValue(struct ListNode* cur, char input[]);


// Case 10, Removes element from list
void removeElement(struct ListNode* cur, struct LinkedList* List);


// Case 11, moves element towards back of list
void moveBack(struct ListNode* cur, struct LinkedList* List);


// Case 12, moves element towards front of list
void moveUp(struct ListNode* cur, struct LinkedList* List);


// Case 13, Prints all elements and values to file in order
void finalPrint(struct LinkedList* List);

// Case 14, displays all possible commands
void displayCommands();

// Case 15, finds current element's index
int position(struct ListNode* cur); 

#endif