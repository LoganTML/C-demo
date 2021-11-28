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

typedef struct{
    ListNode* head;
    ListNode* tail;
} LinkedList;


// Scans input for a command
int classify(char* input[]) {
    
    //Copies input to command string and truncates it to the first word only
    char cmd[] = *input;
    int i = 0;
    for (i = 0; cmd[i] != ' ' && cmd[i] != '\0'; i++) {}
    cmd[i] = '\0';

    // could also be done with strcpy, strlen, 

    //If there's more input after the command, removes command from the front of input
    if (*input[i] == ' ') {
        int j = 0;
        for (j = 0; input[i] != '\0'; j++) {
                *input[j] = *input[i];
                i++;
        }
        *input[j] = '\0';
        
    }

    strlwn(cmd);

    /* 
    Compares cmd to list of known commands
    Strcasecmp is like strcmp; compares to strings and returns 0 if they're identical
         but isn't case sensitive

    Update: uses strlwn instead to convert all characters of cmd to lowercase;
        saves runtime for strcmp
    */

    if (!strcmp(cmd, "add")) {
        // adds element to back of list

        printf("Adding element to list: %s\n", *input);
        return 1;

    } else if (!strcmp(cmd, "count")) {
        // counts elements in list (also pretty self explanatory but hey I like commenting)

        printf("Counting elements in list:\n");
        return 2;

    } else if (!strcmp(cmd, "print")) {
        // Prints list

        printf("Printing list:\n");
        return 3;

    } else if (!strcmp(cmd, "find") && 47 < *input[0] && *input[0] < 58) {
        // finds an element by position in list

        printf("Selecting element at position: %s\n", input);
        return 4;

    } else if (!strcmp(cmd, "find") && ((64 < *input[0] && *input[0] < 91) || (96 < *input[0] && *input[0] < 123))) {
        // finds an element by its given name

        printf("Finding element: '%s'\n", *input);
        return 5;

    } else if (!strcmp(cmd, "find")) {
        // if input is invalid

        printf("Invalid input. " "For list of available commands enter 'help'.\n");
        return 0;

    } else if (!strcmp(cmd, "next")) {
        // selects next element

        printf("Finding next element\n");
        return 6;

    } else if (!strcmp(cmd, "prev")) {
        // selects previous element

        printf("Finding previous element\n");
        return 7;
        
    } else if (!strcmp(cmd, "cur")) {
        // prints values of current element

        printf("Current element: \n");
        return 8;

    } else if (!strcmp(cmd, "cv")) {
        // changes value of current element

        printf("Changing value of input to: %s\n", *input);
        return 9;

    } else if (!strcmp(cmd, "del")) {
        // deletes current element

        printf("Deleting current element");
        return 10;

    } else if (!strcmp(cmd, "back")) {
        // moves towards end of list

        printf("Moving current element towards end of list\n");
        return 11;

    } else if (!strcmp(cmd, "forward")) {
        // moves element towards front of list aka head

        printf("Moving current element towards beginning of list\n");
        return 12;

    } else if (!strcmp(cmd, "file")) {
        // prints entire list to file

        printf("Printing list to file output.txt (creative name eh?)\n");
        return 13;

    } else if (!strcmp(cmd, "help")) {
        // shows all commands

        printf("Printing commands:\n");
        return 14;

    } else if (!strcmp(cmd, "position")) {
        // locates current element's position (index + 1)
        printf("Locating position: \n");
        return 15;
    } else {
        // if command unrecognized

        printf("Command unrecognized; enter 'help' for list of commands");
        return 0;
    }

}


// Case 1, Adds element to back of list
void addBack(char* input[], LinkedList* List) {

        // Creates new node
        ListNode* new_node = malloc(sizeof(ListNode));

    //First part: sets pointers

    if (main_list->tail == NULL) {
        // if this is the first element added:

        new_node->next = NULL;
        new_node->prev = NULL;
        main_list->head == &new_node;
        main_list->tail == &new_node;
    } else {
        // Otherwise connects new element with previous tail

        ListNode* current = main_list->tail;
        current->next = &new_node;
        new_node->prev = &current;
        main_list->tail = &new_node;
    }


    // Second part: sets values

    //If first characters are numbers, set element value to them, then scan input for name
    if ((47 < input[0] && input[0] < 58)) {
        int in_value = atoi(*input);
        new_node->value = in_value;

        int i = 0;
        int q = 0;
        while (input[i] != '\0') {
            if (64 < *input[i] && *input[i] < 91) || (96 < *input[i] && *input[i] < 123) {
                new_node->name[k] = input[i];
            }
            i++;
        }
        

    } else {
        // Otherwise take input and set it to name

        int i = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            new_node->name[i] = input[i];
            i++;
        }
        new_node->name[i] = '\0';

        int k = 0;
        char numbers[30];
        while (input[i] != '\0' && (47 < input[++i] && input[i] < 58)) {
            // If the file isn't over and the following characters are numbers, set val to them
            numbers[k] = input[i];
            k++;
            i++;
        }
        new_node->value = atoi(*numbers);
    }

    printf("New node created\n" "Name: '%s'\n" "Value: %d\n", new_node->name, new_node->value);

}


// Case 2, Returns size of list
int listSize(LinkedList* List) {
    if (List->head == NULL) {
        return 0;
    } else {
        int i = 0;
        ListNode* cur = List->head;
        while (cur->next != NULL) {
            cur = cur->next;
            i++;
        }
        return i;
    }
}


// Case 3, Prints list with values
void printList(LinkedList* List) {
    if (List->head == NULL) {
        printf("List empty\n");
    }

        int i = 0;
        ListNode* cur = List->head;
        while (cur->next != NULL) {
            i++;

            printf("%d) '%s', %d\n", i, cur->name, cur->value);

            cur = cur->next;
        }

}


// Case 4, Finds element in list by number, prints name and shows value
ListNode* findByPosition(char* input[], LinkedList* List) {
    int i = 1;
    int position = atoi(*input);
    ListNode* cur = List->head;
    while (i != position) {
        cur = cur->next;
        i++;
    }
    currentElement(cur);
    return cur;
}


// Case 5, Finds element in list by name, calculates position in list and shows value
ListNode* findByName(char name[], LinkedList* List) {
    if (List->head == NULL) {
        return NULL;
    } else {

    }
}


// Case 6, Moves to next element (towards back)
void next(ListNode* cur, LinkedList* List) {
    if (cur == NULL) {
        cur = List->head;
    } else {
        cur = cur->next;
    }
}


// Case 7, Moves to previous element (towards front/head)
void prev(ListNode* cur, LinkedList* List) {
    if (cur == NULL) {
        cur = List->tail;
    } else {
        cur = cur->prev;
    }
}


// Case 8, Displays current element
void currentElement(ListNode* cur) {
    if (cur == NULL) {
        printf("No element currently selected\n");
    } else {
        printf("Current node: '%s', %d, position: %d", cur->name, cur->value, position(cur));
    }
}


// Case 9, Modifies value of element in list
void changeValue(ListNode* cur, char* input[]) {
    int newValue = atoi(*input);
    if (cur == NULL || newValue != NULL) {
        printf("Error: invalid input\n");
        return;
    }
    cur->value = newValue;
}


// Case 10, Removes element from list
void removeElement(ListNode* cur, LinkedList* List) {
    if (cur == NULL) {
        return;
    } else if (cur == List->head) {
        free(cur);
    } else if (cur == List->tail) {
        cur->prev->next = NULL;
        free(cur);
    } else {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    cur = NULL;
}


// Case 11, moves element towards back of list
// Slightly confusing because "next" goes towards the back, I know my b
void moveBack(ListNode* cur, LinkedList* List) {

    // If cur is null or last element in list, can't switch with next
    if (cur == NULL || cur->next == NULL) {
        return;
    }

    ListNode* next_node = cur->next;
    
    //Connect outsides to outsides
    cur->next = next_node->next;
    next_node->prev = cur->prev;
    //Connect them to each other
    cur->prev = next_node;
    next_node->next = cur;

}


// Case 12, moves element towards top of list
void moveUp(ListNode* cur, LinkedList* List) {
    // If cur is first element, can't move up
    if (cur == NULL || cur->prev == NULL) {
        return;
    }

    ListNode* prev_node = cur->prev;

    //Link outsides
    cur->prev = prev_node->prev;
    prev_node->next = cur->next;
    //Link insides
    cur->next = prev_node;
    prev_node->prev = cur;

}


// Case 13, Prints all elements and values to file and console in order.  Deletes list.
void finalPrint(LinkedList* List) {
    if (List->head == NULL) {
        printf("List empty\n");
        return;
    } else {
        ListNode* cur = NULL;
        ListNode* next_e = List->head;

        FILE* output_file = fopen("output.txt", "w+");

        int i = 0;
        while (next_e != NULL) {
            cur = next_e;
            printf("%d) '%s', %d\n", ++i, cur->name, cur->value);
            fprintf("%d) '%s', %d\n", ++i, cur->name, cur->value);

            next_e = cur->next;
            free(cur);
        }

        fclose(output_file);
    }
}

// Case 14, displays all possible commands
void displayCommands() {
    FILE* command_list = fopen("command_list.txt", "r");
        char c = fgetc(command_list);
        while (c != EOF) {
            printf("%c", c);
            c = fgetc(command_list);
        }
        printf("\n");
        fclose(command_list);
}

int position(ListNode* cur) {
    if (cur == NULL) {
        return 0;
    } else {
        int i = 1;
        while (cur->prev != NULL) {
            cur = cur->prev;
            i++;
        }
        return i;
    }
}