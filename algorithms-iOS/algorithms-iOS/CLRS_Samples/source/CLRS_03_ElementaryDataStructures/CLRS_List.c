/*
 * List.c 
 *
 * Implement all the necessary methods for a List.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "CLRS_DataStructures.h"

void init_list(List *list){

  list->size = 0;
  list->head = NULL;
  list->tail = NULL;

}
ListElement *create_an_element(const void *data){
  ListElement *newElement;

  newElement = (ListElement *)malloc(sizeof(ListElement));
  if (NULL == newElement){
    // the malloc does not feel well today.
    return NULL;
  }

  newElement->data = (void *)data;
  newElement->next = NULL;

  return newElement;
}

/******************************************************************************
 * List methods - destroy
 *****************************************************************************/
void destroy_list(List *list){

  while(list->size > 0){
    ListElement *anElement = list->head;

    remove_element_from_list(list, anElement);
  }
}
void destroy_an_element(ListElement *element){
  free(element->data);
  element->next = NULL;
  free(element);
}

/******************************************************************************
 * List methods - insertion
 *****************************************************************************/
bool list_has_element(List *list, ListElement *element){
  if (list->size == 0) return false;

  ListElement *currentElement = list->head;
  while (currentElement != element && currentElement != NULL){
    currentElement = currentElement->next;
  }

  // trevased to the end, got no match
  if (currentElement == NULL){
    return false;
  }else{
    return true;
  }
}
int insert_element_to_list_after_element(List *list, const void *data, ListElement *theElement){
  if (!list_has_element(list, theElement)) return -1;

  // do not insert into an empty list
  if (list->size == 0) return -1;

  ListElement *newElement = create_an_element(data);
  if (NULL == newElement) return -1;

  // insert a new node after a node is easy
  ListElement *nextElement = theElement->next;

  theElement->next = newElement;
  newElement->next = nextElement;

  list->size++;

  return 0;
}
int insert_element_to_list_before_element(List *list, const void *data, ListElement *theElement){
  if (!list_has_element(list, theElement)) return -1;

  // do not insert into an empty list
  if (list->size == 0) return -1;

  // insert a new node before a node need to search the list to find the previous node
  ListElement *previousElement = list->head;
  if (previousElement == theElement){
    // the element is the head.
    return insert_element_to_list_at_head(list, data);
  }

  // The first element is not the element
  while (previousElement->next != theElement && NULL != previousElement){
    previousElement = previousElement->next;
  }

  // we find the previous element now we 
  ListElement *newElement = create_an_element(data);
  if (NULL == newElement) return -1;

  newElement->next = previousElement->next;
  previousElement->next = newElement;

  list->size++;

  return 0;
}

int insert_element_to_list_at_head(List *list, const void *data){

  // because we only accept data as a parameter, we need to create the element
  // by ourselves.
  ListElement *newElement = create_an_element(data);
  if (NULL == newElement) return -1;

  if (list->tail == NULL){
    // means it's an empty list, insert at head need to update tail
    list->head = newElement;
    list->tail = newElement;
  }else{
    // a none empty list, insert at head is a little bit more easier
    newElement->next = list->head;
    list->head = newElement;
  }

  list->size++;

  return 0;
}
int insert_element_to_list_at_end(List *list, const void *data){
  // because we only accept data as a parameter, we need to create the element
  // by ourselves.
  ListElement *newElement = create_an_element(data);
  if (NULL == newElement) return -1;

  if (list->head == NULL){
    // means it's an empty list, insert at tail need to update head
    list->head = newElement;
    list->tail = newElement;
  }else{
    // a none empty list, insert at end is a little bit easier
    list->tail->next = newElement;
    list->tail = newElement;
  }

  list->size++;

  return 0;

}

/******************************************************************************
 * List methods - deletion
 *****************************************************************************/
int remove_element_from_list(List *list, ListElement *element){
  // If the element has no element, do nothing.
  if (list->head == NULL) return -1;

  if (!list_has_element(list, element)) return -1;

  if (list->head == element){
    // the element is the first element.
    list->head = element->next;
    destroy_an_element(element);
  }else{
    ListElement *currentElement = list->head;
    ListElement *oldElement = NULL;

    while (currentElement != element && currentElement != NULL){
      oldElement = currentElement;
      currentElement = currentElement->next;
    }

    // Not reached the tail and also find the element.
    oldElement->next = element->next;

    destroy_an_element(element);
  }

  list->size--;

  return 0;
}

void print_list(List *list){
  if (list->size == 0) {
    fprintf(stdout, "the list is empty\n");
    return;
  }

  fprintf(stdout, "List at     : %p\n", &list);
  fprintf(stdout, "Size        : %d\n", list->size);
  fprintf(stdout, "Head at     : %p\n", &list->head);
  fprintf(stdout, "Tail at     : %p\n", &list->tail);
  fprintf(stdout, "---------------------------------\n");

  ListElement *currentElement = list->head;
  int i = 0;
  while (currentElement != NULL){
    fprintf(stdout, "Elmt[%2d]  : [%p]%d\n", i, &currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }
}
