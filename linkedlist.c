#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct node
{
    char alpha;          // Character data stored in the node
    struct node *next;   // Pointer to the next node
} node;

int main(int argc, char *argv[])
{
    node *head = NULL;   // Pointer to the first node in the linked list
    node *temp = NULL;   // Temporary pointer for iterating through the linked list

    // Iterate through the command-line arguments
    for (int i = 1; i < argc; i++)
    {
        char *abc = argv[i];   // Get the current argument

        // Allocate memory for a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Memory allocation failed");
            return 1;
        }

        // Initialize the new node's data and next pointer
        new_node->alpha = abc[0];
        new_node->next = NULL;

        // Add the new node to the linked list
        if (head == NULL)
        {
            head = temp = new_node;   // If the list is empty, set head and temp to the new node
        }
        else
        {
            temp->next = new_node;    // Link the previous node's next pointer to the new node
            temp = new_node;          // Move temp to the new node
        }
    }

    // Traverse and print the linked list
    temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->alpha); // Print the character stored in the current node
        temp = temp->next;          // Move to the next node
    }

    // Free allocated memory for the linked list nodes
    temp = head;
    while (temp != NULL)
    {
        node *next_node = temp->next;
        free(temp);                 // Free memory for the current node
        temp = next_node;           // Move to the next node
    }

    return 0;
}
