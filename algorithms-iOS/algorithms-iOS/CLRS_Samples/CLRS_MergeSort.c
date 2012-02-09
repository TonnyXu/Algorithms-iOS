//
//  CLRS_DivideAndConquer.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/2/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_DivideAndConquer.h"

void mergeSort(int array[], int startIndex, int endIndex);
void merge(int array[], int startIndex, int middleIndex, int endIndex);

#ifndef TONNY_IOS_APP
int main(void){
  doMergeSort(100000);
  return 0;
}
#endif


void doMergeSort(unsigned int numberOfElements)
{
  const char* algorithmName = "Merge Sort";
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

  mergeSort(array, 0, numberOfElements -1);
  
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

// the recursive function
void mergeSort(int array[], int startIndex, int endIndex)
{
  if (startIndex < endIndex) { 
    // say 8 elements, start = 0, middle = 3, end = 7
    // left = 3 - 0 + 1 = 4
    // right = 7 - 3 = 4
    int middleIndex = (startIndex + endIndex)>>1;
    
    if (middleIndex != startIndex) {
      // make sure at least we sort 2 elements
      mergeSort(array, startIndex, middleIndex);
    }
    if ((middleIndex + 1) != endIndex) {
      // make sure at least we sort 2 elements
      mergeSort(array, middleIndex + 1, endIndex);
    }
    merge(array, startIndex, middleIndex, endIndex);
  }
}

void merge(int array[], int startIndex, int middleIndex, int endIndex)
{
  // say 8 elements, start = 0, middle = 3, end = 7
  // left = 3 - 0 + 1 = 4
  // right = 7 - 3 = 4
  int leftArrayNumOfElements = middleIndex - startIndex + 1;
  int rightArrayNumOfElements = endIndex - middleIndex;
  
  int leftArray[leftArrayNumOfElements];
  int rightArray[rightArrayNumOfElements];
  
  for (int i = startIndex; i <= middleIndex; i++) {
    leftArray[i - startIndex] = array[i];
  }
  
  for (int i = middleIndex + 1; i <= endIndex; i++) {
    rightArray[i - middleIndex - 1] = array[i];
  }
  
  // now, merge it.
  int l = 0, r = 0, p = startIndex;
  while (l < leftArrayNumOfElements || r < rightArrayNumOfElements) {
    if (l >= leftArrayNumOfElements) {
      // only right part.
      array[p] = rightArray[r];
      p++;
      r++;
    }else if (r >= rightArrayNumOfElements){
      // only left part
      array[p] = leftArray[l];
      p++;
      l++;
    }else{
      // both part
      if (leftArray[l] > rightArray[r]) {
        array[p] = rightArray[r];
        p++;
        r++;
      }else{
        array[p] = leftArray[l];
        p++;
        l++;
      }
    }
  }

}

