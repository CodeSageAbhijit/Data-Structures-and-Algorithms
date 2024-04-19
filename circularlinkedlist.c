#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Initialize pointers for the head, tail, and a temporary node
node *head = NULL;
node *temp = NULL;
node *tail = NULL;

// Function to insert a node at the beginning of the list
void insert_at_start() {
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d", &newnode->data);
    tail->next = newnode;
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at a specified position in the list
void insert_at_position() {
    temp = head;
    int position, i = 1;
    printf("Enter position:");
    scanf(" %d", &position);
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d", &newnode->data);
    while (i < position - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to insert a node at the end of the list
void insert_at_end() {
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d", &newnode->data);
    tail->next = newnode;
    tail = newnode;
    newnode->next = head;
}

// Function to delete a node from the beginning of the list
void delete_at_start() {
    temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}

// Function to delete a node from a specified position in the list
void delete_at_position() {
    temp = head;
    node *tempx = NULL;
    int position, i = 1;
    printf("Enter position:");
    scanf(" %d", &position);
    while (i < position - 1) {
        temp = temp->next;
        i++;
    }
    tempx = temp->next;
    temp->next = temp->next->next;
    free(tempx);
}

// Function to delete a node from the end of the list
void delete_at_end() {
    temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
}

// Function to print the elements in the circular linked list
void print_function() {
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Create a circular linked list from command line arguments
    for (int i = 1; i < argc; i++) {
        node *newnode = malloc(sizeof(node));
        newnode->data = atoi(argv[i]);
        newnode->next = NULL;

        if (head == NULL) {
            head = tail = newnode;
            newnode->next = head;
        } else {
            tail->next = newnode;
            tail = newnode;
            newnode->next = head;
        }
    }

    int choice;
    do {
        // Display menu options
        printf("1. Insert at start\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at start\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation based on user choice
        switch (choice) {
            case 1:
                insert_at_start();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_position();
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                delete_at_position();
                break;
            case 7:
                print_function();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    // Free all dynamically allocated memory
    temp = head;
    while (temp != NULL) {
        node *next_node = temp->next;
        free(temp);
        temp = next_node;
        if (temp == head) break; // Avoid infinite loop
    }

    return 0;
}
