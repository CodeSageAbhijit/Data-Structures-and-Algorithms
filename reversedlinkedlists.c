#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct node
{
    char alphabet;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    // Create a list pointer variable and set it to NULL
    node *list = NULL;

    // Loop through command line arguments, starting from index 1
    for (int i = 1; i < argc; i++)
    {
        // Get the current argument
        char *abc = argv[i];

        
        // Dynamically allocate memory for a new node
        node *n = malloc(sizeof(node));

        // Check if memory allocation was successful
        if (n == NULL)
        {
            return 1; // Exit if memory allocation failed
        }

        // Assign values to the new node
        n->alphabet = abc[0]; // Store the first character of the argument
        n->next = NULL;       // Initialize the 'next' pointer to NULL

        // Point the 'next' pointer of the new node to the previous list
        n->next = list;

        // Update the 'list' pointer to point to the new node
        list = n;
    }

    // Traverse the linked list and print the characters
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%c\n", ptr->alphabet);
        ptr = ptr->next;
    }

    // Free the memory allocated for the nodes in the linked list
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next; // Store the next pointer before freeing the current node
        free(ptr);              // Free the current node
        ptr = next;             // Move to the next node
    }

    return 0; // Program finished successfully
}
