/*
-------------------------------------
File:    llqueue.c
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

#include "llqueue.h"

Queue_t qCreate()
{
   return llCreate();
}

void qDestroy(Queue_t *q)
{
   llDelete(q);
}

void qPrint(const Queue_t q)
{
   llPrint(q);
}

bool qIsEmpty(const Queue_t q)
{
   return llIsEmpty(q);
}

void qClear(Queue_t *q)
{
   for (int i = 0; i < llLength(*q); i++)
      llPop(q);
}

int qLength(const Queue_t q)
{
   return llLength(q);
}

void qEnqueue(Queue_t *q, ItemType value)
{
   llPush(q, value);
   
}

ItemType qFront(const Queue_t q)
{
   return q.head->data;
}

ItemType qDequeue(Queue_t *q)
{
   ItemType x = llHead(*q);

   llDelete(q);

   return x;
}
