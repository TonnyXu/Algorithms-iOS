/*
 * CLRS_Queue.c
 *
 * Implement all the necessary methods for a queue.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "CLRS_DataStructures.h"


Queue* queue_new_empty_queue(){
  return list_new_empty_list();
}
void queue_destroy(Queue *queue){
  list_destroy(queue);
}

QueueElement *queue_create_element(const void *data){
  return list_create_element(data);
}

void queue_print(Queue *queue){
  if (queue->size == 0) {
    fprintf(stdout, "the queue is empty\n");
    return;
  }

  fprintf(stdout, "Queue at     : %p\n", queue);
  fprintf(stdout, "Size         : %d\n", queue->size);
  fprintf(stdout, "--------------------\n");

  QueueElement *currentElement = queue->head;
  int i = 0;
  while (currentElement != NULL){
    fprintf(stdout, "Queue[%2d]    : [%p]%d\n", i, currentElement, *(int *)currentElement->data);
    currentElement = currentElement->next;
    i++;
  }

}

int queue_dequeue(Queue *queue, void **data){
  return list_remove_element(queue, queue->tail, data);
}

int queue_enqueue(Queue *queue, const void *data){
  return list_insert_data_after_element(queue, data, NULL);
}

