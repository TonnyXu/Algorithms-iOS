#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){
  fprintf(stdout, "Test Case 1\n===========================\n");
  Stack *empty_stack = stack_new_empty_stack();
  stack_print(empty_stack);
  stack_destroy(empty_stack);

  fprintf(stdout, "\nTest Case 2\n===========================\n");
  Stack *stack_a = stack_new_empty_stack();
  for (int i=1; i<=10; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    stack_push_data(stack_a, value);
  }
  stack_print(stack_a);

  fprintf(stdout, "\nTest Case 3\n===========================\n");
  for (int i=1; i<=5; i++){
    void *data = NULL;
    stack_pop(stack_a, &data);
    fprintf(stdout, "Popped: %d\n", *(int *)data);
    free(data);
  }
  stack_print(stack_a);

  fprintf(stdout, "\nTest Case 4\n===========================\n");
  stack_destroy(stack_a);
  stack_print(stack_a);

  return 0;
}
#endif

