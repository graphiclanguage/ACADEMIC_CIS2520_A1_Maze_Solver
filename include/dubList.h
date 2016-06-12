/* Shawn Hustins
 * ID: 0884015
 */

#ifndef __dub_List_h__
#define __dub_List_h__

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

typedef struct dubList {
	char data;
	struct dubList * next;
	struct dubList * prev;
} DubList;

/*
 * addToBack
 * PRE: A pointer to the head of the list, or NULL if starting a new list, and
 * 		char to fill the struct must be passed.
 * POST: Memory is allocated for a new list element, is added to end of list
 * 		 and the list head is returned
 * ERROR: Unable to allocate memory - returns NULL
 */
void * addToBack(DubList * head, char data);

#endif