#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;


void enqueuefront(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("queue is full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = x;
    } else if (front == 0) {
        front = N - 1;
        queue[front] = x;
    } else {
        front--;
        queue[front] = x;
    }
}


void enqueuerear(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("queue is full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if (rear == N - 1) {
        rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}


void dequeuefront() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
}

void dequeuerear() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = N - 1;
    } else {
        rear--;
    }
}


void display() {
    if (front == -1 && rear == -1) {
        printf("queue is empty\n");
        return;
    }

    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    } while (i != rear);
    printf("%d\n", queue[i]);
}


int main(void) {
    int n;

    do {
        printf("Enter the action you want to perform on the queue:\n");
        printf("1. Enqueuefront\n2. Dequeuefront\n3. Enqueuerear\n4. Dequeuerear\n5. Display\n6. Exit\n");

        scanf("%d", &n);
        switch (n) {
            case 1:
                printf("Enter the element you want to add to the queue: ");
                int y;
                scanf("%d", &y);
                enqueuefront(y);
                break;
            case 2:
                dequeuefront();
                break;
            case 3:
                printf("Enter the element you want to add to the queue: ");
                int m;
                scanf("%d", &m);
                enqueuerear(m);
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                display();
                break;
        }

    } while (n != 6);

    return 0;
}
