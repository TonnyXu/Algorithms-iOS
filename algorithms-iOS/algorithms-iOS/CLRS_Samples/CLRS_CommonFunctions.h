//
//  common_functions.h
//  algorithms-iOS
//
//  Created by Tonny Xu on 2/1/12.
//  Copyright (c) 2012 Tonny Xu. All rights reserved.
//

#ifndef algorithms_iOS_common_functions_h
#define algorithms_iOS_common_functions_h

void generateInt32Array(int array[], unsigned int numOfElements, int minValue, int maxValue);
void generateSortedInt32Array(int array[], unsigned int numOfElements, int minValue);
void generateReverseSortedInt32Array(int array[], unsigned int numOfElements, int minValue);
void generateGroupedInt32Array(int array[], unsigned int numOfElements, unsigned int numOfGroups, int minValue, int maxValue);

void xorSwap (int *x, int *y);
void swap(int *x, int *y);

#if !defined(MIN)
#define MIN(A,B)	({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a < __b ? __a : __b; })
#endif

#if !defined(MAX)
#define MAX(A,B)	({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a < __b ? __b : __a; })
#endif


#endif
