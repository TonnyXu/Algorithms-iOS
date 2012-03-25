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


Stack* stack_new_empty_stack(){
  return list_new_empty_list();
}
void stack_destroy(Stack *stack){
  list_destroy(stack);
}

StackElement *stack_create_element(const void *data){
  return list_create_element(data);
}

void stack_print(Stack *stack){
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
    fprintf(stdout, "Stack[%2d]    : [%p]%d\n", i, currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }

}

int stack_pop(Stack *stack, void **data){
  return list_remove_element(stack, stack->head, data);
}

int stack_push_data(Stack *stack, const void *data){
  return list_insert_data_after_element(stack, data, NULL);
}
