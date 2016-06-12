/* Shawn Hustins
 * ID: 0884015
 */

#include "linkedList.h"

void * createList(){ 
	
	Node * dummy = calloc(sizeof(Node), 1);
	check(dummy != NULL, "No memory allocated for dummy node.");
	dummy->next = NULL;
	
	return dummy;
	
error:
	return NULL;
}

void destroyList(Node * node) {
	
	while (node) {
		Node * next = node->next;
		destroyNode(node);
		node = next;
	}
	
	return;
}

void * createNode(int nodeVal) {
	
	Node * new = calloc(sizeof(Node), 1);
	check(new != NULL, "No memory allocated for new node.");
	
	new->data = nodeVal;
	new->next = NULL;
	
	return new;
	
error:
	return NULL;

}
void destroyNode(Node * node) {
	
	if (node) free(node);
	
	return;
}

int addFront(Node * dummy, int nodeVal) {
	
	check(dummy != NULL, "No list to add to.");
	Node * prevFront = dummy->next;
	
	dummy->next = createNode(nodeVal);
	check(dummy->next != NULL, "Node could not be initialized.");
	
	dummy->next->next = prevFront;
	
	return 0;
	
error:
	return -1;
}

int removeFront(Node * dummy, int * ifError) {
	
	check(dummy != NULL, "No list to remove from.");
	check(dummy->next != NULL, "No list nodes to remove.");
	
	Node * newFront = dummy->next->next;
	int data = dummy->next->data;
	destroyNode(dummy->next);
	dummy->next = newFront;
	*ifError = 0;
	
	return data;
	
error:
	*ifError = -1;
	return 0;
}

int getFrontVal(Node * dummy, int * ifError) {
	
	check(dummy != NULL, "No list to retrieve data from.");
	check(dummy->next != NULL, "No list node to retrieve data from.");
	*ifError = 0;
	return dummy->next->data;
	
error:
	*ifError = -1;
	return 0;
}

int listLength(Node * dummy) {
	
	check(dummy != NULL, "No list to retrieve data from.");
	
	Node * node = dummy->next;
	int length = 0;
	
	while (node) {
		length++;
		node = node->next;
	}
	
	return length;
	
error:
	return -1;
}

void printList(Node * dummy) {
	
	check(dummy != NULL, "No list to print from.");
	
	Node * node = dummy->next;
	
	while (node) {
		printf("%d\n", node->data);
		node = node->next;
	}
	
	return;
	
error:
	return;
}