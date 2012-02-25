//
//  CLRS_CommonFunctions.c
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/1/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#import "CLRS_CommonFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

void generateInt32Array(int outArray[], unsigned int numOfElements, int minValue, int maxValue)
{
  assert(maxValue > minValue);
  assert(numOfElements <= INT_MAX);
  
  for (int i = 0; i < numOfElements; i++) {
    int value = minValue + arc4random() % (maxValue - minValue);
    outArray[i] = value;
  }
  
}

void generateSortedInt32Array(int outArray[], unsigned int numOfElements, int minValue)
{
  assert(numOfElements <= INT_MAX);
  
  for (int i = 0; i < numOfElements; i++) {
    outArray[i] = i + minValue;
  }
  
}

void generateReverseSortedInt32Array(int outArray[], unsigned int numOfElements, int minValue)
{
  assert(numOfElements <= INT_MAX);
  
  for (int i = numOfElements -1 ; i >= 0; i--) {
    outArray[i] = i + minValue;
  }
  
}

void generateGroupedInt32Array(int outArray[], unsigned int numOfElements, unsigned int numOfGroups, int minValue, int maxValue)
{
  assert(maxValue > minValue);
  assert(numOfElements <= INT_MAX);
  assert(numOfGroups < numOfElements);
  
  for (int i = 0; i < numOfElements; i++) {
    int value = minValue + arc4random() % (maxValue - minValue);
    outArray[i] = value;
  }
  
}

void xorSwap (int *x, int *y) 
{
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

