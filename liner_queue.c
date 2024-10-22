#include <stdio.h>
#define size 5
int a[size], front = -1, rear = -1;

int isfull() {
    return rear == size - 1;
}

int isempty() {
    return front == -1 && rear == -1;
}

void Enqueue(int x) {
    if (isfull()) {
        printf("Queue is full\n");
    } else if (isempty()) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }
    a[rear] = x;
}

void Dequeue() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Dequeued: %d\n", a[front]);
        if (front == rear) { 
            front = rear = -1; 
        } else {
            front = front + 1;
        }
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    for (;;) {
        printf("\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                Enqueue(item);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; 
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0; 
}
