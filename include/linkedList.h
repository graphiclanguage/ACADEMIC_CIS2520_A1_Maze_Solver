/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _list_h_
#define _list_h_

#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

typedef struct listNode {
	int data;
	struct listNode * next;
} Node;

/*
 * createList
 * PRE: N/A
 * POST: Memory is allocated for a dummy node, which is returned as a pointer 
 * ERROR: No memory - returns NULL
 */
void * createList();

/*
 * destroyList
 * PRE: All attached list nodes are dynamically allocated and not yet freed
 * POST: Memory is freed for all nodes including the one passed
 */
void destroyList(Node * node);

/*
 * createNode
 * PRE: A valid integer is passed
 * POST: A pointer to allocated memory for a list node is returned
 * 		containing the passed node value
 * ERROR: No memory - returns NULL
 */
void * createNode(int nodeVal);

/*
 * destroyNode
 * PRE: Passed node must be dynamically allocated and not yet freed
 * POST: Memory is freed for passed node
 */
void destroyNode(Node * node);

/*
 * addFront
 * PRE: The dummy node and a valid integer is passed
 * POST: A node created by createNode is placed at the front of the list
 * 		 Returns 0 on success
 * ERROR: No list passed - returns -1
 *		  No memory - returns -1
 */
int addFront(Node * dummy, int nodeVal);

/* 
 * removeFront
 * PRE: The dummy node is passed
 * POST: The front node is removed from the list and freed. Dummy points at
 * 		 the next node
 * ERROR: No list passed - printed error
 * 		  No nodes in list - printed error
 */
int removeFront(Node * dummy, int * ifError);

/*
 * getFrontVal
 * PRE: The dummy node and a valid integer pointer are passed
 * POST: Returns value inside the first list node, sets ifError 0
 * ERROR: No list passed - sets ifError -1, return 0
 * 		  No nodes in list - sets ifError -1, return 0
 */
int getFrontVal(Node * dummy, int * ifError);

/*
 * listLength
 * PRE: The dummy node is passed
 * POST: The length of the list (excluding dummy) is returned
 * ERROR: No list passed - returns -1
 */
int listLength(Node * dummy);

/*
 * printList
 * PRE: The dummy node is passed
 * POST: A list of all node values in the list are printed
 * ERROR: No list passed - printed error
 */
void printList(Node * dummy);

#endif