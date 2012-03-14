/*
 * Stack.c 
 *
 * Implement all the necessary methods for a stack.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "CLRS_DataStructures.h"


Stack* new_empty_stack(){
  return (Stack*)new_empty_list();
}
void destroy_stack(Stack *stack){
  destroy_list((List *)stack);
}

StackElement *create_stack_element(const void *data){
  return create_an_element(data);
}
void destroy_a_stack_element(StackElement *element){
  destroy_an_element(element);
}

void print_stack(Stack *stack){
  if (stack->size == 0) {
    fprintf(stdout, "the stack is empty\n");
    return;
  }

  fprintf(stdout, "Stack at     : %p\n", stack);
  fprintf(stdout, "Size         : %d\n", stack->size);
  fprintf(stdout, "--------------------\n");

  StackElement *currentElement = stack->head;
  int i = 0;
  while (currentElement != NULL){
    fprintf(stdout, "Stack[%2d] : [%p]%d\n", i, currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }

}

int stack_pop(Stack *stack, StackElement *element){
  if (stack->size == 0) return -1;

  element = stack->head;
  stack->head = element->next;
  element->next = NULL;
  stack->size--;
  return 0;
}
int stack_push_element(Stack *stack, StackElement *element){
  return insert_element_to_list_at_head(stack, element);
}
int stack_push_data(Stack *stack, const void *data){
  StackElement *element = create_stack_element(data);
  return insert_element_to_list_at_head(stack, element);
}
