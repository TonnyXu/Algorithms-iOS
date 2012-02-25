//
//  CLRS_Fibonacci_4.c
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

unsigned int calculateFibonacciAtIndexByMatrix(unsigned int index);

#ifndef TONNY_IOS_APP
int main(int args, char* arg_v[]){

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

  doFibonacci_matrix(index);
  return 0;
}
#endif


void doFibonacci_matrix(unsigned int index){
  const char* algorithmName = "Fibonacci(matrix)";
  printf("[%s] calculate fibonacci number at [%d].\n", algorithmName, index);
  
  struct timeval start;
  gettimeofday(&start, NULL);
  
  calculateFibonacciAtIndexByMatrix(index);
  
  struct timeval ended;
  gettimeofday(&ended, NULL);
  struct timeval sub;
  timersub(&ended, &start, &sub);
  printf("[%s] Using %ld.%06d seconds.\n", algorithmName, sub.tv_sec, sub.tv_usec);
}


unsigned int calculateFibonacciAtIndexByMatrix(unsigned int index){
  assert(index <= 47);
  /* Fibnacci number to 15
   * 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15
   *--------------------------------------------------------------------------- 
   * 0   1   1   2   3   5   8  13  21  34   55   89  144  233  377  610
   */
  
  return 0;
}
