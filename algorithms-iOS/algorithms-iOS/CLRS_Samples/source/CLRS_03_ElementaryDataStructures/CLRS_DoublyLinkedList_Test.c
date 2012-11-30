#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DoublyLinkedList.h"

#ifndef TONNY_IOS_APP
int main(void){

  DoublyLinkedList *empty_list = dlist_new_empty_dlist();
  fprintf(stdout, "Test Case 0\n-------------------\n");
  dlist_print(empty_list);
  dlist_destroy(empty_list);

  fprintf(stdout, "\nTest Case 1\n-------------------\n");
  DoublyLinkedList *dlist_a = dlist_new_empty_dlist();
  for (int i=1; i<=10; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    dlist_insert_data_after_element(dlist_a, (void *)value, NULL);
  }

  dlist_print(dlist_a);

  fprintf(stdout, "\nTest Case 2\n-------------------\n");
  for (int i=11; i<=20; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    if (i % 2 == 0){
      dlist_insert_data_after_element(dlist_a, value, dlist_a->head);
    }else{
      dlist_insert_data_before_element(dlist_a, (void *)value, dlist_a->tail);
    }
  }
  dlist_print(dlist_a);

  fprintf(stdout, "\nTest Case 3\n-------------------\n");
  for (int i=0; i<3; i++){
    void *data = NULL;
    dlist_remove_element(dlist_a, dlist_a->head, &data);
    fprintf(stdout, "removed a head element[%3d]\n", *(int *)data);
    free(data);
    /*void *data2 = NULL;*/
    /*dlist_remove_element(dlist_a, dlist_a->tail, &data2);*/
    /*fprintf(stdout, "removed a tail element[%3d]\n", *(int *)data2);*/
    /*free(data);*/
  }
  dlist_print(dlist_a);

  fprintf(stdout, "\nTest Case 4\n-------------------\n");
  for (int i=0; i<3; i++){
    void *data = NULL;
    dlist_remove_element(dlist_a, dlist_a->tail, &data);
    fprintf(stdout, "removed an element[%3d]\n", *(int *)data);
    free(data);
  }
  dlist_print(dlist_a);

  dlist_destroy(dlist_a);
  fprintf(stdout, "Test Case 5\n-------------------\n");
  dlist_print(dlist_a);


  return 0;
}
#endif

