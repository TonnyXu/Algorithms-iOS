#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#include "CLRS_DataStructures.h"

#ifndef TONNY_IOS_APP
int main(void){
  fprintf(stdout, "Test Case 1\n===========================\n");
  Queue *empty_queue = queue_new_empty_queue();
  queue_print(empty_queue);
  queue_destroy(empty_queue);

  Queue *queue_a = queue_new_empty_queue();
  for (int i=1; i<=10; i++){
    int *value = (int *)malloc(sizeof(int)); 
    *value = i;
    queue_enqueue(queue_a, value);
  }
  queue_print(queue_a);

  fprintf(stdout, "\nTest Case 3\n===========================\n");
  for (int i=1; i<=5; i++){
    void *data = NULL;
    queue_dequeue(queue_a, &data);
    fprintf(stdout, "dequeued: %d\n", *(int *)data);
		// Here, using free() is not a good idea.
    free(data);
  }
  queue_print(queue_a);

  fprintf(stdout, "\nTest Case 4\n===========================\n");
  for (int i=1; i<=5; i++){
    void *data = NULL;
    queue_dequeue(queue_a, &data);
    fprintf(stdout, "dequeued: %d\n", *(int *)data);
		// Here, using free() is not a good idea.
    free(data);
  }
  queue_print(queue_a);

  fprintf(stdout, "\nTest Case 5\n===========================\n");
  queue_destroy(queue_a);
  queue_print(queue_a);

  return 0;
}
#endif


