#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo_library.h"


/* Main takes input from user, creates a LinkedList with the input
    given, then can search, modify, and remove elements
    */


int main() {
    
    //Initializes list
    LinkedList List;
    List.head = NULL;
    List.tail = NULL;

    LinkedList* list_pt = &List;

    //Creates pointer to current node
    ListNode* cur = NULL;

    //Prints greeting
    char intro[] = "Enter information below";
    printf("%c",intro);

    
    //Takes user input up to 30 characters
    char input[30];
    input[0] = '\0';
    scanf("%s", input);

    int classified = classify(input);


    while (classified != 0) {
        
        switch (classified)
        {
            case 1:
                //adds new element to back of list
                printf("Case 1\n");
                addBack(input, list_pt);
            break;

            case 2:
                //returns current number of elements in list
                printf("Case 2\n");
                fprint("List Size: %d", listSize);
            break;

            case 3:
                //prints list with values
                printf("Case 3\n");
                printList(list_pt);
            break;

            case 4:
                //Selects element by number, shows name and value
                printf("Case 4\n");
                cur = findByPosition(input, list_pt);
                currentElement(cur);
            break;

            case 5:
                //Selects element by name, calculates position, shows value
                printf("Case 5\n");
                cur = findByPosition(input, list_pt);
                currentElement(cur);
            break;

            case 6:
                //Moves to next element
                printf("Case 6\n");
                next(cur, list_pt);
                currentElement(cur);
            break;

            case 7:
                //Moves to prev element
                printf("Case 7\n");
                prev(cur, list_pt);
                currentElement(cur);
            break;

            case 8:
                // Case 8, Displays current element
                printf("Case 8\n");
                currentElement(cur);
            break;

            case 9:
                //Modifies value of selected element
                printf("Case 9\n");
                changeValue(cur, input);
                currentElement(cur);
            break;

            case 10:
                //Removes element from list
                printf("Case 10\n");
                removeElement(cur, list_pt);
                currentElement(cur);
            break;

            case 11:
                // Case 11, moves element towards back of list
                printf("Case 11\n");
                moveBack(cur, list_pt);
                currentElement(cur);
            break;

            case 12:
                // Case 12, moves element towards front of list
                printf("Case 12\n");
                moveUp(cur, list_pt);
                currentElement(cur);
            break;

            case 13:
                //Prints all elements and values to file and console in order
                printf("Case 13\n");
                finalPrint(list_pt);
                return 0;
            break;

            case 14:
                //Displays all possible commands
                printf("Case 14\n");
                displayCommands();
            break;

            case 15:
                //Prints current index
                printf("Case 15\n");
                printf("Current position: %d\n", position(cur));
        }


        scanf("%s", input);
        classified = classify(input);

    }




    return 0;
}