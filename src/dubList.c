/* Shawn Hustins
 * ID: 0884015
 */

#include "dubList.h"

void * addToBack(DubList * head, char data) {
	
	DubList * newItem = calloc(1, sizeof(DubList));
	check(newItem != NULL, "Unable to allocate memory for list item.");
	
	if (head == NULL) { //builds new list
		newItem->data = data;
		newItem->prev = NULL;
		newItem->next = NULL;
		
		head = newItem;
		
	} else { //adds to specified list
		DubList * temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		
		temp->next = newItem;
		newItem->data = data;
		newItem->prev = temp;
		newItem->next = NULL;
	}
	
	return head;
	
error:
	return NULL;
}