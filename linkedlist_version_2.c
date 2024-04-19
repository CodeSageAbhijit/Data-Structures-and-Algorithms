#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char alpha;
    struct node *next;
}node;

node *head;
node *ptr;


void print(){
    //to print your linked list
    printf("Elements:");
    ptr=head;
    while(ptr!=NULL){
        printf("%c ",ptr->alpha);
        ptr=ptr->next;
    }
    printf("\n");
}

void insert_element() {
    // To insert an element after creating the linked list
    int index;
    printf("Enter the index to insert the element: ");
    scanf("%d", &index);

    if (index < 0) {
        printf("Invalid index.\n");
        return;
    }

    // Create a new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Malloc fails.\n");
        return;
    }

    printf("Enter the character to insert: ");
    scanf(" %c", &new_node->alpha);  

    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        ptr = head;
        while (index > 1 && ptr != NULL) {
            ptr = ptr->next;
            index--;
        }
        if (ptr == NULL) {
            printf("Index out of bounds.\n");
            free(new_node);
            return;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void free_memory(){
    //To free the linkde list that we've created
    ptr=head;
    while(ptr!=NULL){
        node *temp=ptr->next;
        free(ptr);
        ptr=temp;
    }
}

int main(int argc,char *argv[]){


//taking input through command line arguments
    if (argc<2){
        printf("Usage:./linkedlist_version_2 'linked list data...'\n");
    }


//initiating the pointer variables
    head=NULL;
    ptr=NULL;
//accepting data from user and creating linked list


    for(int i=1;i<argc;i++){
        char *abc=argv[i];
        
        node *new_node = malloc(sizeof(node));

        if(new_node==NULL){
            printf("Malloc fails");
            return 1;
        }

        new_node->alpha=abc[0];
        new_node->next=NULL;

        if(head==NULL){
            head=ptr=new_node;
        }
        else{
            ptr->next = new_node;    // Link the previous node's next pointer to the new node
            ptr = new_node;          // Move temp to the new node
        }
    }

    printf("Your linked list is created.\n");
    int choice;


    do{
    printf("Enter the action you want to perform to this linked list \n1.print_list\n2.insert_element\n3.exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        print();
        break;
        case 2:
        insert_element();
        
        
    }

    }while(choice!=3);

    


    
//Finally,give back all the memory that we've taken from the OS
    free_memory();
    return 0;
}