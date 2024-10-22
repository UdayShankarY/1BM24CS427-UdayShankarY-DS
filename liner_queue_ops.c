#include <stdio.h>
# define size 5
int a[size],front=-1,rear=-1;
int isfull(){
    if (rear == size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isempty(){
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
void Enqueue(int x){
    if (isfull())
    {
        printf("Queue is full");
    }
    else if(isempty()){
        front=rear=0;
    }
    else{
        rear = rear +1;
    }
    a[rear] = x;
}
void Dequeue(){
    if (isempty())
    {
        printf("queue is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else{
        front = front +1;
    }
}
void display(){
    if (isempty())
    {
        printf("queue is empty");
    }
    else{
        for (int  i = front; i <= rear; i++)
        {
            printf("%d",a[i]);
        }
    }
}

void main(){
    int choice;
    int item;
for (;;)
{
    printf("\n1:Enqueue\n2:Dequeue\n3:display\n4:exit\n");
    printf("enter your choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("enter the item to enqueue : \n");
        scanf("%d",&item);
        Enqueue(item);
        break;
    case 2:
        Dequeue();
        break;
    case 3:
        display();
        break;
    
    default:
        return;
    }
}
}
