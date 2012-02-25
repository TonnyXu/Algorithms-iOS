//
//  CLRS_BinarySearch.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/6/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <inttypes.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_DivideAndConquer.h"

int binarySearch(int x, int sortedArray[], int numOfElements, int startIndex, int endIndex);

#ifndef TONNY_IOS_APP
int main(int args, char* arg_v[]){
  
  if (args != 2) {
    printf("Usage: ./CLRS targetToSearch\n");
    return 0;
  }
  char *endptr;
  int targetValue = strtoimax(arg_v[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("Usage: ./CLRS targetToSearch\n\n");
    printf("       targetToSearch need to be a number.[%s]\n", endptr);
    return 0;
  }
  
  doBinarySearch(targetValue);
  return 0;
}
#endif

void doBinarySearch(int targetToSearch){
  int min = 1;
  int max = 1000000;
  
  if (targetToSearch > max) {
    printf("please choose a value between [%d, %d]", min, max);
    return;
  }
  
  const char* algorithmName = "Binary Search";
  printf("[%s] find %d within sorted array [%d, %d]\n", algorithmName, targetToSearch, min, max);
  
  int numOfElements = max - min + 1;
  int sortedArray[numOfElements];
  generateSortedInt32Array(sortedArray, numOfElements, min);
  
  
  struct timeval start;
  gettimeofday(&start, NULL);
  
  int targetIndex = binarySearch(targetToSearch, sortedArray, numOfElements, 0, numOfElements - 1);
  printf("%d is found at %d\n", targetToSearch, targetIndex);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
  
}

int binarySearch(int x, int sortedArray[], int numOfElements, int startIndex, int endIndex){
  assert(startIndex <= endIndex);
  
  int middleIndex = startIndex + ((endIndex - startIndex) >> 1);
  
  int middleValue = sortedArray[middleIndex];
  
  if (startIndex == endIndex && middleValue != x) {
    // The last element, but still can not find the value
    printf("[Debug]: %d\n", startIndex);
    return INT_MIN;
  }
  
  if (middleValue == x) {
    return middleIndex;
  }else if (middleValue < x){
    // in the right side
    return binarySearch(x, sortedArray, numOfElements, middleIndex + 1, endIndex);
  }else{
    // in the left side
    return binarySearch(x, sortedArray, numOfElements, startIndex, middleIndex - 1);
  }
}


