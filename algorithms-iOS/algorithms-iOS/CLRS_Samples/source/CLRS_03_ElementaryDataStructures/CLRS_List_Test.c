#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){

  List *empty_list = list_new_empty_list();
  fprintf(stdout, "Test Case 0\n-------------------\n");
  list_print(empty_list);
  list_destroy(empty_list);

  fprintf(stdout, "\nTest Case 1\n-------------------\n");
  List *list_a = list_new_empty_list();
  for (int i=1; i<=10; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    list_insert_data_after_element(list_a, (void *)value, list_a->tail);
  }

  list_print(list_a);

  fprintf(stdout, "\nTest Case 2\n-------------------\n");
  for (int i=11; i<=20; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    if (i % 2 == 0){
      list_insert_data_after_element(list_a, value, NULL);
    }else{
      list_insert_data_after_element(list_a, (void *)value, list_a->tail);
    }
  }
  list_print(list_a);

  fprintf(stdout, "\nTest Case 3\n-------------------\n");
  for (int i=0; i<3; i++){
    void *data = NULL;
    list_remove_element(list_a, list_a->head, &data);
    fprintf(stdout, "removed an element[%3d]\n", *(int *)data);
    free(data);
  }
  list_print(list_a);

  fprintf(stdout, "\nTest Case 4\n-------------------\n");
  for (int i=0; i<3; i++){
    void *data = NULL;
    list_remove_element(list_a, list_a->tail, &data);
    fprintf(stdout, "removed an element[%3d]\n", *(int *)data);
    free(data);
  }
  list_print(list_a);

  list_destroy(list_a);
  fprintf(stdout, "Test Case 5\n-------------------\n");
  list_print(list_a);


  return 0;
}
#endif
