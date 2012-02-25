//
//  CLRS_Fibonacci_1.c
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
#include <inttypes.h>
#include <assert.h>

#import "CLRS_CommonFunctions.h"
#import "CLRS_NaiveAlgorithms.h"

unsigned int calculateFibonacciAtIndexByRecursion(unsigned int index);

#ifndef TONNY_IOS_APP
int main(int args, char * arg_v[]){
  
  if (args != 2) {
    printf("Usage: ./CLRS index_of_fibonacci\n");
    return 0;
  }
  char *endptr;
  int index = strtoimax(arg_v[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("Usage: ./CLRS index_of_fibonacci\n\n");
    printf("       index_of_fibonacci need to be a number.[%s]\n", endptr);
    return 0;
  }
  
#if defined(__LP64__) || defined(_WIN64)
  // LP64 machine, OS X or Linux
  if (index > 93) {
    printf("ERROR: fib(%d) is larger than UINT64_MAX \n", index);
    return 0;
  }
#else
  // 32-bit machine, Windows or Linux or OS X
  if (index > 47) {
    printf("ERROR: fib(%d) is larger than UINT32_MAX \n", index);
    return 0;
  }
#endif
  
  doFibonacci_recursion(index);
  return 0;
}
#endif


void doFibonacci_recursion(unsigned int index){
  const char* algorithmName = "Fibonacci(recursion)";
  printf("[%s] calculate fibonacci number at [%d] = ", algorithmName, index);
  
  struct timeval start;
  gettimeofday(&start, NULL);

  unsigned int result = calculateFibonacciAtIndexByRecursion(index);
  printf("%d\n", result);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
}


unsigned int calculateFibonacciAtIndexByRecursion(unsigned int index){
  /* Fibnacci number to 15
   * 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15
   *--------------------------------------------------------------------------- 
   * 0   1   1   2   3   5   8  13  21  34   55   89  144  233  377  610
   */
  
  int fibValue = 0;
  if (index == 0) {
    fibValue = 0;
    return fibValue;
  }else if (index == 1 || index == 2){
    fibValue = 1;
    return fibValue;
  }
  
  // index > 2
  unsigned int fibValuePre = calculateFibonacciAtIndexByRecursion(index - 1);
  unsigned int fibValuePrePre = calculateFibonacciAtIndexByRecursion(index - 2);
  
  return (fibValuePre + fibValuePrePre);
  
}
