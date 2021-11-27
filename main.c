#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demo_library.h"


/* Main takes input from user, creates a LinkedList with the input
    given, then can search, modify, and remove elements
    */


int main() {
    
    //Initializes list
    ListNode* head = NULL;
    ListNode* cur = NULL;

    //Prints greeting
    char intro[] = "Enter information below";
    printf("%c",intro);

    
    
    char input[30];
    input[0] = '\0';
    scanf("%s", input);

    int classified = classify(input);


    while (classified != 0) {
        
        switch (classified)
        {
            case 1:
                //adds new element to back of list
                addBack(input);
            break;

            case 2:
                //returns current number of elements in list
                fprint("List Size: %d", listSize);
            break;

            case 3:
                //prints list with values

            break;

            case 4:
                //Selects element by name, calculates position, shows value

            break;

            case 5:
                //Selects element by number, shows name and value

            break;

            case 6:
                //Moves to next element

            break;

            case 7:
                //Moves to prev element

            break;

            case 8:
                //Instructions for operations on element

            break;

            case 9:
                //Modifies value of selected element

            break;

            case 10:
                //Removes element from list

            break;

            case 11:
                //Prints all elements and values to file in order

            break;

            /*
            case x:
                FILE* output_file = fopen("output.txt", "w+")

                int fclose(FILE* fp)
            */


           while (cur != NULL) {
            
               //Prints current element
                currentElement(cur);

                //Gets user input
                scanf("%s", input);
                classified = classify(input);

                switch (classified)
                {
                    case 
                }
           }

        }


        scanf("%s", input);
        classified = classify(input);

    }




    return 0;
}