//
//  QuickSort.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/6/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_DivideAndConquer.h"

void quickSort(int array[], unsigned int startIndex, unsigned int endIndex);
unsigned int partition(int array[], unsigned int startIndex, unsigned int pivotIndex, unsigned int endIndex);

#ifndef TONNY_IOS_APP
int main(void){
  
  doQuickSort(100000);
  return 0;
}
#endif

void doQuickSort(unsigned int numberOfElements){
  const char* algorithmName = "Quick Sort";
  printf("[%s] sort %d elements.\n", algorithmName, numberOfElements);
  int array[numberOfElements];
  
  generateInt32Array(array, numberOfElements, 1, numberOfElements);
  int minNumOfElements = MIN(numberOfElements, 20);
  printf("[%s] top %d unsorted elements:\n", algorithmName, minNumOfElements);
  for (int i = 0; i < minNumOfElements; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  
  struct timeval start;
  gettimeofday(&start, NULL);
  
//  mergeSort(array, 0, numberOfElements -1);
  quickSort(array, 0, numberOfElements -1);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
  
  for (int i = 0; i < minNumOfElements; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  printf("[%s] top %d sorted elements.\n", algorithmName, minNumOfElements);

}


void quickSort(int array[], unsigned int startIndex, unsigned int endIndex){
  // only one element, no need to sort.
  if (startIndex >= endIndex) return;
  
  // pick a ramdon index as the pivot to satisfy `startIndex` <= pivot <= `endIndex`
  unsigned int pivotIndex = (arc4random() % (endIndex - startIndex)) + startIndex;

  int pivotIndexAfterPartition = partition(array, startIndex, pivotIndex, endIndex);
  quickSort(array, startIndex, pivotIndexAfterPartition - 1);
  quickSort(array, pivotIndex + 1, endIndex);
  
}

unsigned int partition(int array[], unsigned int startIndex, unsigned int pivotIndex, unsigned int endIndex){
  // first, exchange the value at pivotIndex and startIndex to make sure 
  // the first element is the pivot
  if (endIndex != pivotIndex) {
    swap(&array[endIndex], &array[pivotIndex]);
  }
  
  // loop the rest elements.
  int pivotValue = array[endIndex];
  int partitionSeparatorIndex = startIndex - 1;
  for (int j = startIndex; j < endIndex; j++) {
    if (array[j] <= pivotValue) {
      partitionSeparatorIndex++;
      swap(&array[partitionSeparatorIndex], &array[j]);
    }
  }
  
  partitionSeparatorIndex++;
  swap(&array[partitionSeparatorIndex], &array[endIndex]);
  
  return partitionSeparatorIndex;
}

