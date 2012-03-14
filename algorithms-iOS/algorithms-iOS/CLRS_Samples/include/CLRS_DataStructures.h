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
 *****************************************************************************/
List* new_empty_list();
ListElement *create_an_element(const void *data);

void destroy_list(List *list);
void destroy_an_element(ListElement *element);

bool list_has_element(List *list, ListElement *element);
int insert_element_to_list_after_element(List *list, const void *data, ListElement *theElement);
int insert_element_to_list_before_element(List *list, const void *data, ListElement *theElement);
int insert_element_to_list_at_head(List *list, const void *data);
int insert_element_to_list_at_end(List *list, const void *data);

int remove_element_from_list(List *list, ListElement *element);

void print_list(List *list);

/******************************************************************************
 * Stack definition
 *****************************************************************************/
typedef ListElement     StackElement;
typedef List            Stack;

/******************************************************************************
 * Stack methods
 *****************************************************************************/
Stack* new_empty_stack();
void destroy_stack(Stack *stack);

StackElement *create_stack_element(const void *data);
void destroy_a_stack_element(StackElement *element);

void print_stack(Stack *stack);

int stack_pop(Stack *stack, StackElement *element);
int stack_push_element(Stack *stack, StackElement *element);
int stack_push_data(Stack *stack, const void *data);

#endif
