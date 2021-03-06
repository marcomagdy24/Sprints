#ifndef STACK_H_

#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "../types.h"



// Initialize Linked list Node
typedef struct Node
{
    uint8_t data;
    struct Node *next;
} StackNode;

StackNode *head;

// Define User Functions
void push(uint8_t u8_data);
uint8_t pull();
void printStack();

#endif
