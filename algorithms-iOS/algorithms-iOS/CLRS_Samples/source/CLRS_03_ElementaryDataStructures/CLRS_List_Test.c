#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){

  List emptyList;
  print_list(&emptyList);

  List list_a;
  init_list(&list_a);
  fprintf(stdout, "---- init list finished.\n");
  int *value_1 = (int *)malloc(sizeof(int)); *value_1 = 1;
  int *value_2 = (int *)malloc(sizeof(int)); *value_2 = 2;
  int *value_3 = (int *)malloc(sizeof(int)); *value_3 = 3;
  int *value_4 = (int *)malloc(sizeof(int)); *value_4 = 4;
  fprintf(stdout, "---- init data finished.\n");
  insert_element_to_list_at_head(&list_a, value_1);
  insert_element_to_list_at_head(&list_a, value_2);
  insert_element_to_list_at_head(&list_a, value_3);
  insert_element_to_list_at_head(&list_a, value_4);
  print_list(&list_a);

  return 0;
}
#endif
