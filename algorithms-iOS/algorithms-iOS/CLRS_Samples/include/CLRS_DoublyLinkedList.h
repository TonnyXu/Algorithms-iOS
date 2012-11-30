/*
 *  CLRS_DoublyLinkedList.h
 *  algorithms-iOS
 *
 *  Created by Tonny Xu on 3/25/12.
 *  Copyright (c) 2012 Tonny Xu. All rights reserved.
 */

#ifndef CLRS_DOUBLYLINKEDLIST_H_
#define CLRS_DOUBLYLINKEDLIST_H_

#include <stdbool.h>
#include <stdlib.h>

/******************************************************************************
 * Doubly linked list definition
 *****************************************************************************/
typedef struct DoublyLinkedListElement_ {
  void                              *data;

  struct DoublyLinkedListElement_   *prev;
  struct DoublyLinkedListElement_   *next;
} DoublyLinkedListElement;

typedef struct DoublyLinkedList_ {
  int                   size;

  DoublyLinkedListElement     *head;
  DoublyLinkedListElement     *tail;

} DoublyLinkedList;

/******************************************************************************
 * Doubly linked list methods
 *****************************************************************************/
DoublyLinkedList *dlist_new_empty_dlist();
DoublyLinkedListElement *dlist_create_element(const void *data);
void dlist_destroy(DoublyLinkedList *dlist);

bool dlist_has_element(DoublyLinkedList *dlist, DoublyLinkedListElement *element);
int dlist_insert_data_after_element(DoublyLinkedList *dlist, const void *data, DoublyLinkedListElement *theElementOrNull);
int dlist_insert_data_before_element(DoublyLinkedList *dlist, const void *data, DoublyLinkedListElement *theElementOrNull);
int dlist_remove_element(DoublyLinkedList *dlist, DoublyLinkedListElement *element, void **data);

void dlist_print(DoublyLinkedList *dlist);


#endif
