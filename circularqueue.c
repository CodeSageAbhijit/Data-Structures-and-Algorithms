#include <stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

// Function to enqueue an element into the queue
void enqueue(int x) {
    if ((rear+1)%N==front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear=(rear+1)%N;
        queue[rear] = x;
    }
}

// Function to dequeue an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    }
    else if(front=rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%N;
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Current element: %d\n", queue[front]);
    }
}

// Function to display the elements in the queue
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i = front;front!=rear;i=((i+1)%N)) 
        {
            printf("%d ", queue[i]);
        }
        printf("%d",queue[i]);
        printf("\n");
    }
}

// Main function
int main(void) {
    int n;

    do {
        printf("Enter the action you want to perform on the queue:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");

        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the element you want to add to the queue: ");
                int y;
                scanf("%d", &y);
                enqueue(y);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
        }

    } while (n != 5);

    return 0;
}
