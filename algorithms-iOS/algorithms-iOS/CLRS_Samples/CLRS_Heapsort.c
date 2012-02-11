//
//  CLRS_HeapSort.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/6/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_DivideAndConquer.h"

int parentNodeIndexOf(int index);
int leftNodeIndexOf(int index);
int rightNodeIndexOf(int index);

void maxHeapify(int array[], unsigned int numOfArray, int nodeIndex);
void buildMaxHeap(int array[], unsigned int numOfArray);
void heapsort(int array[], unsigned int numOfArray);

#ifndef TONNY_IOS_APP
int main(void){
  doHeapsort(100000);
  return 0;
}
#endif

// Because CLRS use the index start from 1, thus we need to tweek the index to fit starting from 0
inline int parentNodeIndexOf(int index){
  return (((index + 1) >> 1) - 1);
}
inline int leftNodeIndexOf(int index){
  return (((index + 1) << 1) - 1);
}
inline int rightNodeIndexOf(int index){
  return ((index + 1) << 1);
}

void maxHeapify(int array[], unsigned int numOfArray, int nodeIndex){
  int leftNodeIndex = leftNodeIndexOf(nodeIndex);
  int rightNodeIndex = rightNodeIndexOf(nodeIndex);
  
  int maxValueIndex = nodeIndex;
  
  if (leftNodeIndex < numOfArray && array[leftNodeIndex] > array[nodeIndex]) {
    maxValueIndex = leftNodeIndex;
  }
  if (rightNodeIndex < numOfArray && array[rightNodeIndex] > array[maxValueIndex]) {
    maxValueIndex = rightNodeIndex;
  }
  
  if (maxValueIndex != nodeIndex) {
    swap(&array[maxValueIndex], &array[nodeIndex]);
    maxHeapify(array, numOfArray, maxValueIndex);
  }
}

void buildMaxHeap(int array[], unsigned int numOfArray){
  int lastNoneLeafNodeIndex = (numOfArray >> 1) - 1;
  for (int i = lastNoneLeafNodeIndex; i >= 0; i--) {
    maxHeapify(array, numOfArray, i);
  }
}

void heapsort(int array[], unsigned int numOfArray){
  buildMaxHeap(array, numOfArray);
  
  for (int heapSize = numOfArray - 1; heapSize >= 0; heapSize--) {
    swap(&array[heapSize], &array[0]);
    maxHeapify(array, heapSize, 0);
  }
}


void doHeapsort(unsigned int numberOfElements){
  const char* algorithmName = "Heapsort";
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

  heapsort(array, numberOfElements);
  
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
