//
//  CLRS_BubbleSort.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/2/12.
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
  doBubbleSort(100000);
}
#endif


// a.k.a Sinking Sort
void doBubbleSort(unsigned int numberOfElements)
{
  const char* algorithmName = "Bubble Sort";
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
  
  for (int i=0; i<numberOfElements-1; i++) {
    for (int j=i+1; j<numberOfElements; j++) {
      if (array[j] < array[i]) {
        // you can choose either use xorSwap or not. xorSwap actually cost much more time.
        
        // xorSwap(&array[i], &array[j]);
        
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
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
