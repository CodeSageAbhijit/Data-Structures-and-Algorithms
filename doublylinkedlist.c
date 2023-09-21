#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *previous;
} node;

node *head = NULL;
node *temp = NULL;

void insert_at_start(){
    temp = head;
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d",&newnode->data);
    newnode->previous = NULL;
    newnode->next = head;
    head->previous = newnode;
    head = newnode;

}

void insert_at_position(){
    int position,i=1;
    
    printf("Enter position:");
    scanf(" %d",&position);
    temp = head;
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d",&newnode->data);
    while(i < position - 1){
        temp = temp->next;
        i++;
    }
    newnode->previous = temp;
    newnode->next = temp->next;
    temp->next->previous = newnode;
    temp->next = newnode;

}

void insert_at_end(){
    temp = head;
    node *newnode = malloc(sizeof(node));
    printf("Enter data:");
    scanf(" %d",&newnode->data);
    newnode->next = NULL;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->previous = temp;
}

void delete_at_start(){
    temp = head;
    head = head->next;
    free(temp);
}

void delete_at_position(){
    temp = head;
    int position,i=1;
    printf("Enter position:");
    scanf(" %d",&position);
    while(i < position - 1){
        temp = temp->next;
        i++;
    }
    node *temp1 = temp->next;
    temp->next = temp->next->next;
    temp1->next->previous = temp;
    free(temp1);
    
}

void delete_at_end(){
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp = temp->previous;
    free(temp->next);
    temp->next = NULL;
}

void print(){
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    

    for (int i = 1; i < argc; i++) {
        node *newnode = malloc(sizeof(node));
        if (newnode == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }

        newnode->data = atoi(argv[i]);
        newnode->next = NULL;
        newnode->previous = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->previous = temp;
            temp = newnode;
        }
    }

    int choice;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at a specific position\n");
        printf("3. Insert at the end\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from a specific position\n");
        printf("6. Delete from the end\n");
        printf("7. Print the linked list\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_at_start();
                break;
            case 2:
                insert_at_position();
                break;
            case 3:
                insert_at_end();
                break;
            case 4:
                delete_at_start();
                break;
            case 5:
                delete_at_position();
                break;
            case 6:
                delete_at_end();
                break;
            case 7:
                print();
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);


    // Free memory to avoid memory leaks
    temp = head;
    while (temp != NULL) {
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
