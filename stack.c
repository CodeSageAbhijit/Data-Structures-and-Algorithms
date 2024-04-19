#include <stdio.h>

#define N 5

// Define the stack and top of the stack
int stack[N];
int top = -1;

// Function to push an element onto the stack
void push() {
    printf("Enter the number to add to the stack: ");
    int x;
    scanf("%d", &x);

    // Check for stack overflow
    if (top == N - 1) {
        printf("OVERFLOW\n");
    } else {
        top++;
        stack[top] = x;
        printf("Inserted element: %d\n", stack[top]);
    }
}

// Function to pop an element from the stack
void pop() {
    int item;
    if (top == -1) {
        printf("There's nothing in the stack\n");
    } else {
        item = stack[top];
        top--;
        printf("Deleted item: %d\n", item);
    }
}

// Function to display the elements in the stack
void display() {
    if (top == -1) {
        printf("There's nothing in the stack\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to peek at the top element of the stack
void peek() {
    if (top == -1) {
        printf("There's nothing in the stack\n");
    } else {
        printf("The element at the top: %d\n", stack[top]);
    }
}

// Main function
int main() {
    int n;

    do {
        printf("Enter the action you want to perform on the stack:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                
        }

    } while (n != 5);

    return 0;
}
