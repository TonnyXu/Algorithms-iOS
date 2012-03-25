//
//  CLRS_DataStructures.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/9/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdbool.h>
#include <stdlib.h>

#ifndef algorithms_iOS_CLRS_DataStructures_h
#define algorithms_iOS_CLRS_DataStructures_h

/******************************************************************************
 * naming convesion
 * ----------------
 *
 * Tonny Mar 25, 2012
 *
 * put a prefix in each method to indicate what this method works for, also,
 * this naming convension helps CTag to sort the method much more clearly.
 *****************************************************************************/


/******************************************************************************
 * List definition
 *****************************************************************************/
typedef struct ListElement_{
  void                    *data;
  struct ListElement_     *next;
} ListElement;

typedef struct List_{
  int                      size;

  struct ListElement_     *head;
  struct ListElement_     *tail;

} List;

/******************************************************************************
 * List methods
 *
 * Here we suppose to use `malloc` and `free` to do all the memory operations.
 * If you want to use other method to destroy the memory, passing the function
 * point of your own `free` method is highly recommended.
 *****************************************************************************/
List* list_new_empty_list();
ListElement *list_create_element(const void *data);
void list_destroy(List *list);

bool list_has_element(List *list, ListElement *element);
int list_insert_data_after_element(List *list, const void *data, ListElement *theElementOrNull);
int list_remove_element(List *list, ListElement *element, void **data);

void list_print(List *list);

/******************************************************************************
 * Stack definition
 *****************************************************************************/
typedef ListElement     StackElement;
typedef List            Stack;

/******************************************************************************
 * Stack methods
 *****************************************************************************/
Stack* stack_new_empty_stack();
void stack_destroy(Stack *stack);

StackElement *stack_create_element(const void *data);

void stack_print(Stack *stack);

int stack_pop(Stack *stack, void **data);
int stack_push_data(Stack *stack, const void *data);

/******************************************************************************
 * Queue definition
 *****************************************************************************/
typedef ListElement     QueueElement;
typedef List            Queue;

/******************************************************************************
 * Queue methods
 *****************************************************************************/
Queue* queue_new_empty_queue();
void queue_destroy(Queue *queue);

QueueElement *queue_create_element(const void *data);

void queue_print(Queue *queue);

int queue_dequeue(Queue *queue, void **data);
int queue_enqueue(Queue *queue, const void *data);
#endif
