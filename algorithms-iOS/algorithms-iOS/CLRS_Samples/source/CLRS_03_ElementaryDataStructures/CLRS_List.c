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

List* list_new_empty_list(){
  List *newList = (List *)malloc(sizeof(List));
  if (newList == NULL) return NULL;

  newList->size = 0;
  newList->head = NULL;
  newList->tail = NULL;

  return newList;
}

ListElement *list_create_element(const void *data){
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
void list_destroy(List *list){

  while(list->size > 0){
    ListElement *anElement = list->head;

    /*remove_element_from_list(list, anElement);*/
    list->head = anElement->next;
    list->size--;
    anElement->next = NULL;
    free(anElement->data);
    free(anElement);
  }
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
int list_insert_data_after_element(List *list, const void *data, ListElement *theElementOrNull){
  if (NULL != theElementOrNull && !list_has_element(list, theElementOrNull)){
    // wrong operation, could not insert the new element after the specified
    // element.
    return -1;
  }

  ListElement *newElement = list_create_element(data);
  if (NULL == newElement) return -1;

  if (list->size == 0) {
    list->head = newElement;
    list->tail = newElement;
  }else if (theElementOrNull == NULL){
    // insert in the head
    newElement->next = list->head;
    list->head = newElement;
  }else{
    // we can insert the element now.
    if (theElementOrNull == list->tail){
      // theElementOrNull is the tail, special work need to be done to 
      // maintain the tail pointer
      theElementOrNull->next = newElement;
      list->tail = newElement;
    }else{
      newElement->next = theElementOrNull->next;
      theElementOrNull->next = newElement;
    }
  }

  list->size++;

  return 0;
}

/******************************************************************************
 * List methods - deletion
 *
 * The element if moved out of the list, but the value it holds should be 
 * transferred outside the function. This is the reason why we need `**data`
 * parameter.
 *****************************************************************************/
int list_remove_element(List *list, ListElement *element, void **data){
  // If the element has no element, do nothing.
  if (list->head == NULL) return -1;

  if (!list_has_element(list, element)) return -1;

  if (list->head == element){
    // the element is the first element.
    list->head = element->next;
    *data = element->data;
  }else{
    ListElement *currentElement = list->head;
    ListElement *prevElement = NULL;

    while (currentElement != element && currentElement != NULL){
      prevElement = currentElement;
      currentElement = currentElement->next;
    }

    // Not reached the tail and also find the element.
    prevElement->next = element->next;
    *data = element->data;

    if (list->tail == element){
      list->tail = prevElement;
    }
  }

  free(element);          // free the element here or outside the function
                          // is debatable, I choose to free it here.
  list->size--;

  return 0;
}

void list_print(List *list){
  if (list->size == 0) {
    fprintf(stdout, "the list is empty\n");
    return;
  }

  fprintf(stdout, "List at     : %p\n", list);
  fprintf(stdout, "Size        : %d\n", list->size);
  fprintf(stdout, "Head at     : %p\n", list->head);
  fprintf(stdout, "Tail at     : %p\n", list->tail);
  fprintf(stdout, "-------------\n");

  ListElement *currentElement = list->head;
  int i = 0;
  while (currentElement != NULL){
    fprintf(stdout, "Elmt[%2d]  : [%p]%d\n", i, currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }
}
