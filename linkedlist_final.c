#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct node {
    char data;
    struct node *next;
} node;

// Global pointers to the head and temporary nodes
node *head = NULL;
node *temp = NULL;

// Function to print the linked list
void print() {
    temp = head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the linked list
void free_memory() {
    temp = head;
    while (temp != NULL) {
        node *temp1 = temp->next;
        free(temp);
        temp = temp1;
    }
}

// Function to insert a node at the start of the linked list
void insertatstart(char x) {
    temp = head;
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("malloc fails");
    }

    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at a specific position in the linked list
void insertatposition(char x, int position) {
    temp = head;
    int i = 1;

    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("malloc fails");
    }

    while (i < position -1) {
        temp = temp->next;
        i++;
    }

    newnode->data = x;
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to insert a node at the end of the linked list
void insertatend(char x) {
    temp = head;
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        printf("malloc fails");
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newnode->data = x;
    temp->next = newnode;
    newnode->next = NULL;
}

// Function to delete a node from the start of the linked list
void deleteatstart() {
    temp = head;
    node *temp1;
    if (head == NULL) {
        printf("list is empty");
        return;
    }
    head = head->next;
    free(temp);
    temp = head;
}

// Function to delete a node from the end of the linked list
void deleteatend() {
    temp = head;
    node *prev_node;
    while (temp->next != NULL) {
        prev_node = temp;
        temp = temp->next;
    }
    free(temp);
    prev_node->next = NULL;
}

// Function to delete a node from a specific position in the linked list
void deleteatposition(int position) {
    temp = head;
    node *temp1;
    int i = 1;

    while (i < position - 1) {
        temp = temp->next;
        i++;
    }

    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

int main(int argc, char *argv[]) {

    // Creating the linked list from command-line arguments
    for (int i = 1; i < argc; i++) {
        char *abc = argv[i];

        // Allocating memory for a new node
        node *newnode = malloc(sizeof(node));

        if (newnode == NULL) {
            printf("malloc fails");
        }

        // Storing data from command-line argument in the new node
        newnode->data = abc[0];
        newnode->next = NULL;

        // Connecting the new node to the linked list
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    int choice;

    // Menu-driven loop to perform linked list operations
    do {
        printf("Your Linked List is created.\nEnter what actions you want to perform on linked list\n");
        printf("1.insertatstart\n2.insertatposition\n3.insertatend\n");
        printf("4.deleteatstart\n5.deleteatposition\n6.deleteatend\n");
        printf("7.Print the list\n8.Exit\n");
        int position;
        char c;

        // Reading user's choice
        scanf("%d", &choice);

        // Performing actions based on user's choice using switch-case
        switch (choice) {
            case 1:
                printf("Enter element to be entered:");
                // Reading the character to be inserted at the start
                scanf(" %c", &c);
                insertatstart(c);
                break;
            case 2:
                printf("Enter element to be entered:");
                // Reading the character to be inserted
                scanf(" %c", &c);
                // Reading the position at which the element will be inserted
                printf("Enter the position at which the element to be inserted:");
                scanf(" %d", &position);
                insertatposition(c, position);
                break;
            case 3:
                printf("Enter element to be entered:");
                // Reading the character to be inserted at the end
                scanf(" %c", &c);
                insertatend(c);
                break;
            case 4:
                deleteatstart();
                break;
            case 5:
                printf("Enter the position at which the element to be deleted:");
                // Reading the position of the element to be deleted
                scanf(" %d", &position);
                deleteatposition(position);
                break;
            case 6:
                deleteatend();
                break;
            case 7:
                print();
                break;
        }

    } while (choice != 8); // Exit the loop when choice is 8

    // Freeing memory allocated for the linked list
    free_memory();
}
