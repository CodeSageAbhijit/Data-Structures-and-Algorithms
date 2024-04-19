#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *next;
}node;

node *top = NULL;


void push(char x){
    node *newnode = malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if (top==NULL){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(){
    node *temp;
    temp = top;
    if (top==NULL){
        printf("stack is empty");
        return;
    }
    else{
        top = top->next;
        free(temp);

    }
}


void display(){
    node *temp;
    temp = top;
    if (top==NULL){
        printf("stack is empty");
        return;
    }
    else{
        while(top!=NULL){
            printf(" %c",temp->data);
            temp = temp->next;
        }
    }
}


int main (void){
    int choice;
    char c;
    do{
        printf("Enter what action you want to perform\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf(" %d",&choice);
        switch(choice){
            case 1:
            printf("enter element to be pushed:");
            scanf(" %c",&c);
            push(c);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
        
        }
    }while(choice!=4);

}