/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _stack_h_
#define _stack_h_

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct stack {
	int data;
	Node * next;
} Stack;

// Refer to linkedList.h:createList for usage
extern void * (*createStack)();

// Refer to linkedList.h:destroyList for usage
extern void (*destroyStack)(Node * node);

// Refer to linkedList.h:addFront for usage
extern int (*push)(Node * dummy, int nodeVal);

// Refer to linkedList.h:removeFront for usage
extern int (*pop)(Node * dummy, int * ifError);

// Refer to linkedList.h:getFrontVal for usage
extern int (*peek)(Node * dummy, int * ifError);

#endif