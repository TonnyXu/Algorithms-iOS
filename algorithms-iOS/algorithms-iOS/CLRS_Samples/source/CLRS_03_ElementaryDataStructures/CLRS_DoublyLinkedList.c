/*
 * Doubly Linked List.c
 *
 * Implement all the necessary methods for a Doubly linked list.
 */
#include "CLRS_DoublyLinkedList.h"
#include <stdio.h>

/******************************************************************************
 * Doubly linked list methods
 *****************************************************************************/
DoublyLinkedList *dlist_new_empty_dlist(){
	DoublyLinkedList *newDList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if (!newDList){
		return NULL;
	}

	newDList->size = 0;
	newDList->head = NULL;
	newDList->tail = NULL;

	return newDList;
}

DoublyLinkedListElement *dlist_create_element(const void *data){
	DoublyLinkedListElement *newElement = (DoublyLinkedListElement*)malloc(sizeof(DoublyLinkedListElement));
	if (!newElement){
		return NULL;
	}

	newElement->data = (void *)data;
	newElement->prev = NULL;
	newElement->next = NULL;

	return newElement;
}

bool dlist_has_element(DoublyLinkedList *dlist, DoublyLinkedListElement *element){
	if (dlist->size == 0) return false;
	if (NULL == element) return false;

	DoublyLinkedListElement *currentElement = dlist->head;
	while (currentElement != NULL){
		if (currentElement == element){
			return true;
		}
		currentElement = currentElement->next;
	}

	return false;
}

void dlist_destroy(DoublyLinkedList *dlist){
	while(dlist->size > 0){

		DoublyLinkedListElement *anElement = dlist->head;
		dlist->head = anElement->next;
		anElement->next->prev = NULL;
		anElement->next = NULL;
		dlist->size--;
		free(anElement->data);
		free(anElement);
	}
}

int dlist_insert_data_after_element(DoublyLinkedList *dlist, const void *data, DoublyLinkedListElement *theElementOrNull){
	if (NULL == dlist) return -1;
	if (NULL == data) return -1;

	DoublyLinkedListElement *newElement = dlist_create_element(data);
	
	if (dlist->size == 0){
		// first element
		dlist->head = newElement;
		dlist->tail = newElement;
	}else if (theElementOrNull == NULL){
		// insert to the tail
		newElement->prev = dlist->tail;
		dlist->tail->next = newElement;
		dlist->tail = newElement;
	}else {
		// insert the new element after the specified element
		if (theElementOrNull == dlist->tail){
			// the last Element
			theElementOrNull->next = newElement;
			newElement->prev = theElementOrNull;
			dlist->tail = newElement;
		}else{
			// normal element
			newElement->next = theElementOrNull->next;
      theElementOrNull->next->prev = newElement;
			newElement->prev = theElementOrNull;
			theElementOrNull->next = newElement;
		}
	}
	dlist->size++;
	
	return 0;
}

int dlist_insert_data_before_element(DoublyLinkedList *dlist, const void *data, DoublyLinkedListElement *theElementOrNull){
	if (NULL == dlist) return -1;
	if (NULL == data) return -1;

	DoublyLinkedListElement *newElement = dlist_create_element(data);
	
	if (dlist->size == 0){
		// first element
		dlist->head = newElement;
		dlist->tail = newElement;
	}else if (theElementOrNull == NULL){
		// insert to the head
		newElement->next = dlist->head;
		dlist->head->prev = newElement;
		dlist->head = newElement;
	}else {
		// insert the new element before the specified element
		if (theElementOrNull == dlist->head){
			// the first Element
			newElement->next = dlist->head;
			dlist->head->prev = newElement;
			dlist->head = newElement;
		}else{
			// normal element
      newElement->next = theElementOrNull;
      theElementOrNull->prev->next = newElement;
      newElement->prev = theElementOrNull->prev;
      theElementOrNull->prev = newElement;
		}
	}
	dlist->size++;
	
	return 0;
}

int dlist_remove_element(DoublyLinkedList *dlist, DoublyLinkedListElement *element, void **data){
  if (NULL == dlist) return -1;
  if (NULL == element) return -1;
  if (!dlist_has_element(dlist, element)) return -1;

  if (element == dlist->head){
    dlist->head = element->next;
    element->next->prev = NULL;
    element->next = NULL;
  }else if (element == dlist->tail){
    dlist->tail = element->prev;
    element->prev->next = NULL;
    element->prev = NULL;
  }else{
    element->prev->next = element->next;
    element->next->prev = element->prev;
    element->next = NULL;
    element->prev = NULL;
  }

  *data = element->data;

  free(element);

  return 0;
}

void dlist_print(DoublyLinkedList *dlist){
  if (dlist->size == 0) {
    fprintf(stdout, "the list is empty\n");
    return;
  }

  fprintf(stdout, "List at     : %p\n", dlist);
  fprintf(stdout, "Size        : %d\n", dlist->size);
  fprintf(stdout, "Head at     : %p\n", dlist->head);
  fprintf(stdout, "Tail at     : %p\n", dlist->tail);
  fprintf(stdout, "-------------\n");

  DoublyLinkedListElement *currentElement = dlist->head;
  int i = 0;
  while (currentElement != NULL){
    fprintf(stdout, "Elmt[%2d]  : [%p]%d\n", i, currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }
}

