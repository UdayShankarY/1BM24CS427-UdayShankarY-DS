#include <stdio.h>
#define size 5
int queue[size], front = -1, rear = -1;
int isfull()
{
    if ((rear + 1) % size == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int x)
{
    if (isfull())
    {
        printf("Queue is full");
    }
    else if (isempty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    queue[rear] = x;
}
void dequeue()
{
    if (isempty())
    {
        printf("queue is empty cant dequeue\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}
void display()
{
    if (isempty())
    {
        printf("queue is empty cant display\n");
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d \n", queue[i]);
        }
        printf("%d", queue[rear]);
    }
}

int main()
{
    int choice;
    int item;
    for (;;)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the item to enqueue : ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;

        default:
            return -1;
        }
    }
    return 0;
}