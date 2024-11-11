#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void createLinkedList(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("enter the element %d : ", i + 1);
        int data;
        scanf("%d", &data);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            struct node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}
void insertAtBegining(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void insertAtEnd(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insertAtPosition(int data, int position)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (position == 0)
    {
        insertAtBegining(data);
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            printf("position out of Bound");
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display(){
    struct node* temp =head;
    if (temp == NULL)
    {
        printf("the list is empty...!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ",temp ->data);
        temp=temp->next; 
    }
    printf("NULL\n");
}
int main()
{
    int choice,n,data,position;
    
    printf("enter the number of elements to initialize linked list : ");
    scanf("%d", &n);
    createLinkedList(n);
    while(1){
    printf("Linked List Operations : \n");
    printf("1.Insert At Begining\n");
    printf("2.Insert At End\n");
    printf("3.Insert at Position\n");
    printf("4.Display\n");
    printf("5.exit\n");
    printf("enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("enter data to insert : ");
        scanf("%d",&data);
        insertAtBegining(data); 
        break;
    case 2:
        printf("enter data to insert : ");
        scanf("%d",&data);
        insertAtEnd(data);
        break;
    case 3:
        printf("enter the position to insert : ");
        scanf("%d",&position);
        printf("enter data to insert : ");
        scanf("%d",&data);
        insertAtPosition(data,position);
        break;

    case 4:
        display();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("invalid choice..!");
    }
    }
    return 0;
}