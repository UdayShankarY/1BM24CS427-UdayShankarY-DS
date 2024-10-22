    #include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an operator to the stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop an operator from the stack
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to check the precedence of an operator
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check the associativity of operators
int isRightAssociative(char c) {
    return c == '^';  // '^' is right associative
}

// Main function to convert infix expression to postfix
void infixToPostfix(char *exp) {
    char *e = exp;
    char x;

    while (*e != '\0') {
        // If the character is an operand, print it
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        // If the character is '(', push it to the stack
        else if (*e == '(') {
            push(*e);
        }
        // If the character is ')', pop and print until '(' is found
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        // If the character is an operator
        else if (isOperator(*e)) {
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                if (precedence(stack[top]) == precedence(*e) && isRightAssociative(*e)) {
                    break;
                } else {
                    printf("%c", pop());
                }
            }
            push(*e);
        }
        e++;
    }

    // Pop all operators from the stack
    while (top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char exp[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("Postfix expression: ");
    infixToPostfix(exp);
    printf("\n");
    return 0;
}