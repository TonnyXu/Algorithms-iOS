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
#import "CLRS_InsertionSort.h"
#import "CLRS_CommonFunctions.h"

#ifndef TONNY_IOS_APP
int main(void){
  printf("Here we are.");
  doInsertionSort(10000);
}
#endif


void doInsertionSort(unsigned int numberOfElements){
//  int numberOfElements = 100000;
  int array[numberOfElements];
  
  generateInt32Array(array, numberOfElements, 1, numberOfElements);
  for (int i=0; i<MIN(numberOfElements, 20); i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");

  struct timeval start;
  gettimeofday(&start, NULL);
  
  // Actually, it's Bubble sort.
  for (int i=0; i<numberOfElements; i++) {
    for (int j=i+1; j<numberOfElements; j++) {
      if (array[j] < array[i]) {
        xorSwap(&array[i], &array[j]);
      }
    }
  }
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[Insertion Sort] Using %ld.%d seconds.\n", sub.tv_sec, sub.tv_usec);
  
  for (int i=0; i<MIN(numberOfElements, 20); i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}

// a.k.a Sinking Sort
void doBubbleSort(unsigned int numberOfElements)
{
  int array[numberOfElements];
  
  generateInt32Array(array, numberOfElements, 1, numberOfElements);
  for (int i=0; i<MIN(numberOfElements, 20); i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
  
  struct timeval start;
  gettimeofday(&start, NULL);
  
  // Actually, it's Bubble sort.
  for (int i=0; i<numberOfElements-1; i++) {
    for (int j=i+1; j<numberOfElements; j++) {
      if (array[j] < array[i]) {
        xorSwap(&array[i], &array[j]);
      }
    }
  }
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[Bubble Sort] Using %ld.%d seconds.\n", sub.tv_sec, sub.tv_usec);
  
  for (int i=0; i<MIN(numberOfElements, 20); i++) {
    printf("%d, ", array[i]);
  }
  printf("\n");
}
