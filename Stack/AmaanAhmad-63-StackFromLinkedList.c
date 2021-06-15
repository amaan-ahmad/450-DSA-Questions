#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * top;

void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Overflow.");
        return;
    }
    if (top == NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
        top = newNode;
    }
    else
    {
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Underflow.");
        return;
    }

    struct Node *ptr;
    ptr = top;
    top = ptr->next;
    free(ptr);
}

void display()
{
    if (top == NULL)
    {
        printf("Empty stack");
        return;
    }

    struct Node *ptr;
    ptr = top;
    printf("TOP ");
    while (ptr != NULL)
    {
        printf(" %d -> ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice, val;
    printf("Stack using Linked List\n");
    printf("Made by: Amaan Ahmad 63-CSE-B-19\n");
    while (choice != 4)
    {
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nexiting...");
            break;
        default:
            printf("\nEnter a valid choice...");
        }
    }
    printf("\nMADE BY: Amaan Ahmad CSE-B 63");
    return 0;
}