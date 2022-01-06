//implements functions to manipulate list

// defines functions to manipulate list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "demo_library.h"



//ListNode and LinkedList defined in library?



// Scans input for a command
int classify(char input[]) {
    
    //Copies input to command string and truncates it to the first word only
    char cmd[30];
    strcpy(cmd, input);
    int i = 0;
    for (i = 0; cmd[i] != ' ' && cmd[i] != '\0'; i++) {}
    cmd[i] = '\0';
    
    printf("cmd: %s\n", cmd);

    //If there's more input after the command, removes command from the front of input
    if (input[i] == ' ') {
        int j = 0;
        for (j = 0; input[i+1] != '\0'; j++) { //Plus 1 to avoid keeping the space 
                input[j] = input[i+1];
                i++;
        }
        input[j] = '\0';
        
    }

     strlwr(cmd); // what does this mean again

    printf("cmd but now lowercase: %s\n");
    
    /* Compares cmd to list of known commands
    Strcasecmp is like strcmp; compares to strings and returns 0 if they're identical
         but isn't case sensitive

    Update: uses strlwn instead to convert all characters of cmd to lowercase;
        saves runtime for strcmp
    */

   printf("input now: %s\natoi(input): %d\nisdigit(input): %d\n", input, atoi(input), isdigit(input[0]));

   


    if (!strcmp(cmd, "add")) {
        // adds element to back of list

        printf("Adding element to list: %s\n", input);
        return 1;

    } else if (!strcmp(cmd, "count")) {
        // counts elements in list (also pretty self explanatory but hey I like commenting)

        printf("Counting elements in list:\n");
        return 2;

    } else if (!strcmp(cmd, "print")) {
        // Prints list

        printf("Printing list:\n");
        return 3;

    } else if (!strcmp(cmd, "find") && isdigit(input[0])) {
        // finds an element by position in list

        printf("Locating element at position: %s\n", input);
        return 4;

    } else if (!strcmp(cmd, "find") && isalpha(input[0])) {
        // finds an element by its given name

        printf("Finding element: '%s'\n", input);
        return 5;

    } else if (!strcmp(cmd, "find")) {
        // if input is invalid

        printf("Invalid input. For list of available commands enter 'help'.\n");
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

        printf("Changing value of input to: %s\n", input);
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

        printf("Command unrecognized; enter 'help' for list of commands\n");
        return 0;
    }

}


// Case 1, Adds element to back of list
struct ListNode* addBack(char input[], struct LinkedList* List) {

        // Creates new node
        struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

    //First part: sets pointers

    if (List->tail == NULL) {
        // if this is the first element added:

        printf("first element added\n");

        new_node->next = NULL;
        new_node->prev = NULL;
        List->head = new_node;
        List->tail = new_node;
    } else {
        // Otherwise connects new element with previous tail

        printf("not first element added\n");

        struct ListNode* current_tail = List->tail;
        current_tail->next = new_node;
        new_node->prev = current_tail;
        List->tail = new_node;
        new_node->next = NULL;
    }


    // Second part: sets values

    //If first characters are numbers, set element value to them, then scan input for name
        int in_value = atoi(input);
        new_node->value = in_value;

        int i = 0;
        int q = 0;
        int k = 0;
        char numbers[30];
        while (input[i] != '\0') {
            if (isalpha(input[i])) {
                new_node->name[q] = input[i];
                q++;
            } else if (isdigit(input[i])) {
                numbers[k] = input[i];
                k++;
            }
            i++;
        }
        new_node->value = atoi(numbers);

    printf("New node created\n" "Name: '%s'\n" "Value: %d\n", new_node->name, new_node->value);

}



// Case 2, Returns size of list
int listSize(struct LinkedList* List) {
    if (List->head == NULL) {
        return 0;
    } else {
        int i = 0;
        struct ListNode* cur = List->head;
        while (cur != NULL) {
            cur = cur->next;
            i++;
        }
        return i;
    }
}


// Case 3, Prints list with values
void printList(struct LinkedList* List) {
    if (List->head == NULL) {
        printf("List empty\n");
    }

        int i = 0;
        struct ListNode* curr = List->head;
        while (curr != NULL) {
            i++;

            printf("%d) '%s', %d\n", i, curr->name, curr->value);

            curr = curr->next;
        }
    return;
}


// Case 4, Finds element in list by number, prints name and shows value
struct ListNode* findByPosition(char input[], struct LinkedList* List) {
    int i = 1;
    printf("findByPosition, input: %s\n", input);
    int position = atoi(input);
    struct ListNode* cur = List->head;
    while (i != position) {
        cur = cur->next;
        i++;
    }
    currentElement(cur);
    return cur;
}


// Case 5, Finds element in list by name, calculates position in list and shows value
struct ListNode* findByName(char name[], struct LinkedList* List) {
    if (List->head == NULL) {
        return NULL;
    } else {
        struct ListNode* current = List->head;
        currentElement(current);
        printf("name: %s, current->name: %s\n", name, current->name);
        while (current != NULL) {
            if (!strcasecmp(name, current->name)) {
                printf("Located!\n");
                currentElement(current);
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}



// Case 6, Moves to next element (towards back)
struct ListNode* next(struct ListNode* cur, struct LinkedList* List) {
    if (cur == NULL) {
        cur = List->head;
    } else {
        return cur->next;
    }
}


// Case 7, Moves to previous element (towards front/head)
struct ListNode* prev(struct ListNode* cur, struct LinkedList* List) {
    if (cur == NULL) {
        cur = List->tail;
    } else {
        cur = cur->prev;
    }
}


// Case 8, Displays current element
void currentElement(struct ListNode* cur) {
            // printf("currentElement\n"); was used for debugging
    struct ListNode* currente = cur;
    if (currente == NULL) {
        printf("No element currently selected\n");
    } else {
        printf("Current node: '%s', %d, position: %d\n", currente->name, currente->value, position(currente));
    }
}


// Case 9, Modifies value of element in list
void changeValue(struct ListNode* cur, char input[]) {
    int newValue = atoi(input);
    if (cur == NULL || input == NULL) {
        printf("Error: invalid input\n");
        return;
    }
    cur->value = newValue;
}


// Case 10, Removes element from list
// Always call "cur = NULL" immediately after
void removeElement(struct ListNode* cur, struct LinkedList* List) {
    if (cur == NULL) {
        printf("No element selected\n");
        return;
    } else if (cur == List->head && cur == List->tail) { //If cur is the only element in the list
        printf("Only node in list, prepared for destruction\n");
        List->head = NULL;
        List->tail = NULL;
        free(cur);
    } else if (cur == List->head) { //If cur is the head
        printf("Head selected for deletion\n");
        cur->next->prev = NULL;
        List->head = cur->next;
        free(cur);
    } else if (cur == List->tail) { //If cur is the tail of the list
        printf("Tail selected for deletion\n");
        cur->prev->next = NULL;
        List->tail = cur->prev;
        free(cur);
    } else { //If cur is a node between the head and tail
        printf("Interior node selected for deletion\n");
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
        free(cur);
    }
    cur = NULL; //This doesn't work because cur is already freed. Is there a way to circumvent this?
}


// Case 11, moves element towards back of list
// Slightly confusing because "next" goes towards the back, I know my b
void moveBack(struct ListNode* cur, struct LinkedList* List) {

    // If cur is null or last element in list, can't switch with next
    if (cur == NULL) {
        printf("No element currently selected\n");
        return;
    } else if (cur == List->tail) {
        printf("Current element is already last in list\n");
        return;
    } else if (cur == List->tail && cur == List->head) {
        printf("Current element is alone in list\n");
        return;
    }

    struct ListNode* other_node = cur->next; // Takes node in front of cur and moves it behind (i.e. towards the head of the list)
    
    //Mirrors connections below, but for external nodes
    if (cur->prev != NULL) {
        cur->prev->next = other_node;
    }
    if (other_node->next != NULL) {
        other_node->next->prev = cur;
    }


    //Connect outsides to outsides
    cur->next = other_node->next;
    other_node->prev = cur->prev;
    //Connect them to each other
    cur->prev = other_node;
    other_node->next = cur;

    printf("List->head is %d\n", List->head->value);
    printf("cur is %d\n", cur->value);

    if (cur == List->head) {  //If current element is head of list, the new element inserted behind cur must become the head
        printf("Cur is head\n");
        List->head = other_node;
    }

    if (other_node == List->tail) {
        printf("Cur is one away from tail\n");
        List->tail = cur;
    }

    return;
}


// Case 12, moves element towards top of list
void moveUp(struct ListNode* cur, struct LinkedList* List) {
    // If cur is first element, can't move up
    if (cur == NULL) {
        printf("No element currently selected\n");
        return;
    } else if (cur == List->head) {
        printf("Current element is already first in list\n");
        return;
    } else if (cur == List->head && cur == List->tail) {
        printf("Current element is alone in list\n");
        return;
    }

    struct ListNode* other_node = cur->prev;

    //Connects cur and other_node to external nodes (before and after)
    if (cur->next != NULL) {
        cur->next->prev = other_node;
    }
    if (other_node->prev != NULL) {
        other_node->prev->next = cur;
    }


    //Link outsides
    cur->prev = other_node->prev;
    other_node->next = cur->next;
    //Link insides
    cur->next = other_node;
    other_node->prev = cur;

    if (cur == List->tail) {
        List->tail = other_node;
    }

    if (other_node == List->head) {
        List->head = cur;
    }

    return;
}



// Case 13, Prints all elements and values to file and console in order.  Deletes list.
void finalPrint(struct LinkedList* List) {
    if (List->head == NULL) {
        printf("List empty\n");
        return;
    } else {
        struct ListNode* cur = NULL;
        struct ListNode* next_e = List->head;

        FILE* output_file = fopen("output.txt", "w+");

        int i = 0;
        while (next_e != NULL) {
            cur = next_e;
            printf("%d" ") " "'%s'" ", " "%d\n", ++i, cur->name, cur->value);
            fprintf(output_file, "%d" ") " "'%s'" ", " "%d\n", i, cur->name, cur->value);

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

// Case 15, returns position in list (given by index + 1)

int position(struct ListNode* cur) {
            // printf("position\n"); was used for debugging
    struct ListNode* currente = cur;
    if (currente == NULL) {
        return 0;
    } else {
        int i = 1;
        while (currente->prev != NULL) {
            currente = currente->prev;
            i++;
        }
        return i;
    }
}