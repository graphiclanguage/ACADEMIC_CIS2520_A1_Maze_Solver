/* Shawn Hustins
 * ID: 0884015
 */

#include "stack.h"

void * (*createStack)() = createList;

void (*destroyStack)(Node * node) = destroyList;

int (*push)(Node * dummy, int nodeVal) = addFront;

int (*pop)(Node * dummy, int * ifError) = removeFront;

int (*peek)(Node * dummy, int * ifError) = getFrontVal;