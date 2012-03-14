#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){

  List *empty_list = new_empty_list();
  print_list(empty_list);
  destroy_list(empty_list);

  fprintf(stdout, "Test Case 1\n-------------------\n");
  List *list_a = new_empty_list();
  int *value_1 = (int *)malloc(sizeof(int)); *value_1 = 1;
  int *value_2 = (int *)malloc(sizeof(int)); *value_2 = 2;
  int *value_3 = (int *)malloc(sizeof(int)); *value_3 = 3;
  int *value_4 = (int *)malloc(sizeof(int)); *value_4 = 4;

  insert_element_to_list_at_head(list_a, value_1);
  insert_element_to_list_at_head(list_a, value_2);
  insert_element_to_list_at_head(list_a, value_3);
  insert_element_to_list_at_head(list_a, value_4);
  print_list(list_a);
  destroy_list(list_a);

  fprintf(stdout, "Test Case 2\n-------------------\n");
  List *list_b = new_empty_list();
  int *b_value_1 = (int *)malloc(sizeof(int)); *b_value_1 = 1;
  int *b_value_2 = (int *)malloc(sizeof(int)); *b_value_2 = 2;
  int *b_value_3 = (int *)malloc(sizeof(int)); *b_value_3 = 3;
  int *b_value_4 = (int *)malloc(sizeof(int)); *b_value_4 = 4;
  insert_element_to_list_at_head(list_b, b_value_1);
  insert_element_to_list_at_end(list_b, b_value_2);
  insert_element_to_list_at_end(list_b, b_value_3);
  insert_element_to_list_at_end(list_b, b_value_4);
  print_list(list_b);
  destroy_list(list_b);

  fprintf(stdout, "Test Case 3\n-------------------\n");
  List *list_c = new_empty_list();
  int *c_value_1 = (int *)malloc(sizeof(int)); *c_value_1 = 1;
  int *c_value_2 = (int *)malloc(sizeof(int)); *c_value_2 = 2;
  int *c_value_3 = (int *)malloc(sizeof(int)); *c_value_3 = 3;
  int *c_value_4 = (int *)malloc(sizeof(int)); *c_value_4 = 4;
  insert_element_to_list_at_head(list_c, c_value_1);
  insert_element_to_list_at_end(list_c, c_value_2);
  insert_element_to_list_after_element(list_c, c_value_3, list_c->head);
  insert_element_to_list_before_element(list_c, c_value_4, list_c->tail);
  print_list(list_c);
  destroy_list(list_c);

  fprintf(stdout, "Test Case 4\n-------------------\n");
  List *list_d = new_empty_list();
  int *d_value_1 = (int *)malloc(sizeof(int)); *d_value_1 = 1;
  int *d_value_2 = (int *)malloc(sizeof(int)); *d_value_2 = 2;
  int *d_value_3 = (int *)malloc(sizeof(int)); *d_value_3 = 3;
  int *d_value_4 = (int *)malloc(sizeof(int)); *d_value_4 = 4;
  insert_element_to_list_at_head(list_d, d_value_2);
  insert_element_to_list_at_end(list_d, d_value_1);
  insert_element_to_list_after_element(list_d, d_value_3, list_d->head);
  insert_element_to_list_after_element(list_d, d_value_4, list_d->head);
  print_list(list_d);
  int *d_value_5 = (int *)malloc(sizeof(int)); *d_value_5 = 5;
  ListElement *newElement = create_an_element(d_value_5);
  assert(false == list_has_element(list_d, newElement));
  assert(true == list_has_element(list_d, list_d->head));
  remove_element_from_list(list_d, list_d->head);
  fprintf(stdout, "removed head\n");
  print_list(list_d);
  remove_element_from_list(list_d, list_d->tail);
  fprintf(stdout, "removed tail\n");
  print_list(list_d);
  remove_element_from_list(list_d, list_d->head);
  fprintf(stdout, "removed head\n");
  print_list(list_d);
  remove_element_from_list(list_d, list_d->head);
  fprintf(stdout, "removed head\n");
  print_list(list_d);
  destroy_list(list_d);
  free(d_value_5);

  return 0;
}
#endif
