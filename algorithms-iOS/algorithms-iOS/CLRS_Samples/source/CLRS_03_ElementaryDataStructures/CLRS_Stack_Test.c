#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){
  fprintf(stdout, "Test Case 1\n===========================\n");
  Stack *empty_stack = new_empty_stack();
  print_stack(empty_stack);
  destroy_stack(empty_stack);

  fprintf(stdout, "Test Case 2\n===========================\n");
  Stack *stack_a = new_empty_stack();
  int *value_1 = (int *)malloc(sizeof(int)); *value_1 = 1;
  stack_push_data(stack_a, value_1);
  print_stack(stack_a);
  int *value_2 = (int *)malloc(sizeof(int)); *value_2 = 1;
  stack_push_data(stack_a, value_2);
  print_stack(stack_a);
  int *value_3 = (int *)malloc(sizeof(int)); *value_3 = 1;
  stack_push_data(stack_a, value_3);
  print_stack(stack_a);
  int *value_4 = (int *)malloc(sizeof(int)); *value_4 = 1;
  stack_push_data(stack_a, value_4);
  print_stack(stack_a);

  fprintf(stdout, "Test Case 3\n===========================\n");
  fprintf(stdout, "Test Case 4\n===========================\n");
  fprintf(stdout, "Test Case 5\n===========================\n");
  fprintf(stdout, "Test Case 6\n===========================\n");
  return 0;
}
#endif

