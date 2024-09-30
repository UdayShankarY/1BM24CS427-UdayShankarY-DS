#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow! Can't push the element %d\n", value);
    }
    else
    {
        top++;
        stack[top] = value;
        printf("\nElement %d is added to the stack successfully!\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack underflow! Can't pop an element\n");
    }
    else
    {
        printf("\nElement %d was popped successfully!\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nThe stack is empty, nothing to display!\n");
    }
    else
    {
        printf("\nThe stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nStack operations:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    }

    return 0;
}
