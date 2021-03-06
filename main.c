#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo_library.h"


/* Main takes input from user, creates a LinkedList with the input
    given, then can search, modify, and remove elements
    */

   // Compiling: gcc main.c demo_library.c

int main() {
    
    //Initializes list
    struct LinkedList List;
    List.head = NULL;
    List.tail = NULL;

    struct LinkedList* list_pt = &List;

    //Creates pointer to current node
    struct ListNode* cur = NULL;

    //Prints greeting
    char intro[] = "Enter information below";
    printf("%s\n",intro);

        //Code for initial debugging
        char testAdd[] = "Add Abcd 15";
        int q = classify(testAdd);
        addBack(testAdd, list_pt);

        cur = list_pt->tail;

        printf("cur: %s\n", cur->name);

        char testAdd2[] = "Add qwerty";
        int e = classify(testAdd2);
        addBack(testAdd2, list_pt);
        
        printf("q: %d\n", q);

        position(cur);
        currentElement(cur);
        printList(list_pt);

        printf("Cur name: '%s', value: %d\n", cur->name, cur->value);

        int list_size = listSize(list_pt);
        printf("List size: %d\n", list_size);
        
        
        
        //Testing findByPosition
        char testFindPos[] = "find 1";
        char testFindPos2[] = "find 2";
        int g = classify(testFindPos);
        int h = classify(testFindPos2);
        printf("g: %d, h: %d\n", g, h);
        findByPosition(testFindPos, list_pt);
        findByPosition(testFindPos2, list_pt);

        //Testing findByName
        char testFindName[] = "find Abcd";
        char testFindName2[] = "find QWerty"; //Testing with incorrect capitalization
        int zz = classify(testFindName);
        int zzz = classify(testFindName2);
        printf("zz: %d, zzz: %d\n", zz, zzz);
        findByName(testFindName, list_pt);
        cur = findByName(testFindName2, list_pt);

        //Testing next, prev: bug with addback and tail/ next?
        cur = next(cur, list_pt);
        currentElement(cur);
        cur = prev(cur, list_pt);
        currentElement(cur);
        cur = prev(cur, list_pt);
        currentElement(cur);
        cur = prev(cur, list_pt);
        currentElement(cur);
        cur = prev(cur, list_pt);
        currentElement(cur);

        //Testing changeValue

        changeValue(cur, "29");
        currentElement(cur);

        //Testing removeElement, commented out so elements are still available for other fxns

        /*

        cur = prev(cur, list_pt); //Shifts to element "Abcd"
        currentElement(cur);
        removeElement(cur, list_pt); //Removes element "Abcd"
        cur = NULL;
        currentElement(cur); //After removal, should be null
        printList(list_pt);
        cur = next(cur, list_pt); //Should go to front of list, which is now "qwerty"
        currentElement(cur);
        cur = next(cur, list_pt); //No other elements in list, therefore should become null again
        currentElement(cur);  
        cur = prev(cur, list_pt); //Should go back to qwerty
        currentElement(cur);
        removeElement(cur, list_pt);    // Always use cur = NULL after removeElement as freeing cur in the library makes it unassigned here
        cur = NULL;
        printList(list_pt);
        currentElement(cur);

        */

        //Testing moveBack

        printf("Testing moveBack\n");
        printList(list_pt);
        currentElement(cur);
        moveBack(cur, list_pt);
        printList(list_pt);
        cur = prev(cur, list_pt);
        currentElement(cur);
        printf("Last node: %d\n", list_pt->tail->value);
        moveBack(cur, list_pt);
        printList(list_pt);
        printf("Last node: %d\n", list_pt->tail->value);

        addBack(testAdd2, list_pt);
        printList(list_pt);
        printf("\n\nLast node: %d\n", list_pt->tail->value);
        printf("First node: %d\n", list_pt->head->value);
        currentElement(cur);
        moveBack(cur, list_pt);
        printList(list_pt);

        //Testing moveUp

        printf("\nTesting moveUp\n");
        currentElement(cur);
        moveUp(cur, list_pt);
        printList(list_pt);
        currentElement(cur);
        moveUp(cur, list_pt);
        printList(list_pt);
        currentElement(cur);
        moveBack(cur, list_pt);
        printList(list_pt);
        currentElement(cur);
        
        //Testing finalPrint

        finalPrint(list_pt);
/*
    
    //Takes user input up to 30 characters
    char input[30];
    input[0] = '\0';
    scanf("%30[^\n]", input);

    int classified = classify(input);


    while (classified != 0) {
        
        switch (classified)
        {
            case 1:
                //adds new element to back of list
                printf("Case 1\n");
                cur = addBack(input, list_pt);
            break;

            case 2:
                //returns current number of elements in list
                printf("Case 2\n");
                printf("List Size: %d", listSize(&List));
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


*/

    return 0;
}