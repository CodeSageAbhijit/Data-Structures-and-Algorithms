#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
typedef struct node {
    char data;
    struct node *next;
} node;

// Declare global pointers for the front and rear of the queue
node *front = NULL;
node *rear = NULL;
node *temp;

// Function to enqueue (insert) an element into the queue
void Enqueue(char x) {
    // Allocate memory for a new node
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL) {
        printf("malloc fails");
        return;
    }
    // Initialize the new node with data and next pointer
    newnode->data = x;
    newnode->next = NULL;
    
    // Check if the queue is empty
    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        // Add the new node to the rear of the queue
        rear->next = newnode;
        rear = newnode;
    }
}

// Function to dequeue (remove) an element from the queue
void Dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty. Nothing to delete.\n");
    } else {
        temp = front;
        front = front->next;
        free(temp); // Free the memory of the removed node
    }
}

// Function to display the elements in the queue
void Display() {
    temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty. Nothing to display.\n");
    } else {
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to clear the entire queue and free memory
void ClearQueue() {
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp); // Free the memory of each node
    }
    rear = NULL; // Set rear to NULL to indicate an empty queue
}


int main(void) {
    int choice;

    do {
        printf("Enter the action you want to perform on the Queue\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

        // Reading user's choice
        scanf(" %d", &choice);

        // Performing actions based on user's choice using switch-case
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                char x;
                scanf(" %c", &x); // Notice the space before %c to consume any leading whitespace
                Enqueue(x);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
        }

    } while (choice != 4);

    
    
    //Function to return the memory to the OS(i.e, deallocation of memory)
    ClearQueue();
    return 0; // Return 0 to indicate successful execution
}
