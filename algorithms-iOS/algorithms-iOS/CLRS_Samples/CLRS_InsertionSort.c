//
//  CLRS_InsertionSort.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/1/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#import "CLRS_NaiveAlgorithms.h"
#import "CLRS_CommonFunctions.h"

#ifndef TONNY_IOS_APP
int main(void){
  doInsertionSort(100000);
}
#endif


void doInsertionSort(unsigned int numberOfElements)
{
  const char* algorithmName = "Insertion Sort";
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
  
  // Insertion sort.
  for (int i = 1; i < numberOfElements; i++) {
    int j = i-1;
    int key = array[i];
    // 0...j is the subarray that is already sorted.
    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
  
  for (int i = 0; i < minNumOfElements; i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  printf("[%s] top %d sorted elements.\n", algorithmName, minNumOfElements);

}

