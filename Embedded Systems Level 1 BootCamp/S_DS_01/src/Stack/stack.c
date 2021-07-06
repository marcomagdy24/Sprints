#include "stack.h"

// Initialize head Node


int isEmpty()
{
    return head == NULL;
}

void push(uint8_t u8_data)
{
    StackNode *newNode;
    newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = u8_data;
    if (head == NULL)
        newNode->next = NULL;
    else
        newNode->next = head;
    head = newNode;
}

uint8_t pull()
{
    uint8_t dataPulled = 0;
    if (head == NULL)
    {
        printf("[INFO] Stack is Empty\n");
        exit(1);
    }

    else
    {
        StackNode *temp;
        temp = head;
        head = head->next;
        dataPulled = temp->data;
        free(temp);
    }
    return dataPulled;
}

void printStack()
{
    StackNode *temp;
    if (isEmpty())
    {
        printf("[ERROR] Stack Underflow\n");
        exit(1);
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("[INFO] Data in stack is %d\n", temp->data);
            temp = temp->next;
        }
    }
}
