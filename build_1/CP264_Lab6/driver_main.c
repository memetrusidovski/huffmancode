/*
-------------------------------------
File:    driver_main.c
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 *
 * This lab give you a practice on how to build and test stacks
 * and queues. You have to give or complete the given code to
 * get the required output
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llstack.h"

//----- TEST DRIVER -----
int main( )
{
	ItemType v;
   Node_t* tmp;

   Stack_t stack = stackCreate();
   assert(stackIsEmpty(stack));
   assert(stackSize(stack) == 0);

   v = "c";
   stackPush(&stack, v);
   v = "p";
   stackPush(&stack, v);
   v = "\n";
   stackPush(&stack, v);
   v = " ";
   stackPush(&stack, v);
   v = "4";
   stackPush(&stack, v);
   stackPrint(stack);

   stackPop(&stack);
   stackIsEmpty(stack);
   

      
}

