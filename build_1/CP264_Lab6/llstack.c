/*
-------------------------------------
File:    llstack.c
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llstack.h"

Stack_t stackCreate()
{
   return llCreate();
}

void stackDestroy(Stack_t* stack)
{
   llDestroy(stack);
}

void stackPrint(const Stack_t stack)
{
   llPrint(stack);
}

bool stackIsEmpty(const Stack_t stack)
{
   return llIsEmpty(stack);
}

void stackPopAll(Stack_t* stack)
{
   for (int i = 0; i < llLength(*stack); i++)
      llPop(stack);
}

int stackSize(const Stack_t stack)
{
   return llLength(stack);
}

void stackPush(Stack_t* stack, ItemType value)
{
  llAppend(stack, value);
  stack->head->count++;
}

ItemType stackTop(const Stack_t stack)
{
   return llHead(stack);
}

ItemType stackPop(Stack_t* stack)
{
   ItemType x = llPop(stack);

   return x;
}
